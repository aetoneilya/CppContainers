CXX=g++
CXXFLAGS=-c -pedantic -Wall -Wextra -Wshadow -Wconversion -Wunreachable-code -std=c++17
LDFLAGS=-lm -lgtest -lpthread

DEBUG ?= 0

ifeq ($(DEBUG),1)
	CXXFLAGS+=-g
	CXXFLAGS+=-DDEBUG
else
	CXXFLAGS+=-Werror
endif

MAINSRC=main.cpp
MAINOBJ=$(MAINSRC:.cpp=.o)
LCOVEXEC=$(EXECUTABLE).info
REPORTDIR=report
EXECUTABLE=result_file

.PHONY: all build test gcov_report style clean leaks rebuild

all: build

build: LDFLAGS+=-lgtest
build: $(MAINOBJ)
	$(CXX) $^ -o $(EXECUTABLE) $(LDFLAGS)

test: build
	./$(EXECUTABLE)

gcov_report: CXXFLAGS+=--coverage
gcov_report: LDFLAGS+=--coverage
gcov_report: test
	lcov -t $(EXECUTABLE) -o $(LCOVEXEC) -c -d .
	lcov -r $(LCOVEXEC) "/usr*" -o $(LCOVEXEC)
	genhtml -o $(REPORTDIR) $(LCOVEXEC)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

style:
	cppcheck --std=c++17 --enable=all --suppressions-list=suppressions.txt .
	python3 ../materials/linters/cpplint.py --filter=-runtime/references --extensions=cpp,h --recursive .

leaks: build
	CK_FORK=no valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(EXECUTABLE)

clean:
	rm -rf *.o $(EXECUTABLE) *.gcno *.gcda *.gcov $(LCOVEXEC) $(REPORTDIR)

rebuild: clean all
