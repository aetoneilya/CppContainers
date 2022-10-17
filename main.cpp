#include <gtest/gtest.h>

#include <functional>
#include <utility>

#include "s21_containers.h"
#include "s21_containersplus.h"

// s21_list
TEST(s21_containers, s21_list_constructor_1) {
    s21::list<int> list;
    EXPECT_TRUE(list.empty());
}

TEST(s21_containers, s21_list_constructor_2) {
    int size = 10;
    s21::list<int> list(size);
    EXPECT_EQ(list.size(), size);
}

TEST(s21_containers, s21_list_constructor_3) {
    s21::list<int> list({1, 1, 1});
    EXPECT_EQ(list.size(), 3);
    for (auto const i : list) {
        EXPECT_EQ(i, 1);
    }
}

TEST(s21_containers, s21_list_constructor_4) {
    s21::list<int> origin({1, 1, 1});
    s21::list<int> list(origin);
    EXPECT_EQ(list.size(), 3);
    for (auto const i : list) {
        EXPECT_EQ(i, 1);
    }
}

TEST(s21_containers, s21_list_constructor_5) {
    s21::list<int> origin({1, 1, 1});
    s21::list<int> list(std::move(origin));
    EXPECT_EQ(list.size(), 3);
    for (auto const i : list) {
        EXPECT_EQ(i, 1);
    }
    EXPECT_EQ(origin.size(), 0);
}

TEST(s21_containers, s21_list_assignment_operator_1) {
    s21::list<int> l1({-1, 0, 1, 2});
    auto l2 = std::move(l1);

    EXPECT_TRUE(l1.empty());
    EXPECT_EQ(l2.size(), 4);
}

TEST(s21_containers, s21_list_front_1) {
    s21::list<int> l({-1, 0, 1, 2});

    EXPECT_EQ(l.front(), -1);
}

TEST(s21_containers, s21_list_back_1) {
    s21::list<int> l({-1, 0, 1, 2});

    EXPECT_EQ(l.back(), 2);
}

TEST(s21_containers, s21_list_begin_1) {
    s21::list<int> l({-1, 0, 1, 2});

    EXPECT_EQ(*l.begin(), -1);
}

TEST(s21_containers, s21_list_end_1) {
    s21::list<int> l({-1, 0, 1, 2});

    EXPECT_EQ(*(--l.end()), 2);
}

TEST(s21_containers, s21_list_empty_1) {
    s21::list<int> l({});

    EXPECT_TRUE(l.empty());
}

TEST(s21_containers, s21_list_size_1) {
    s21::list<int> l({-1, 0, 1, 2});

    EXPECT_EQ(l.size(), 4);
}

TEST(s21_containers, s21_list_max_size_1) {
    s21::list<int> l({-1, 0, 1, 2});

    EXPECT_GT(l.max_size(), 0);
}

TEST(s21_containers, s21_list_clear_1) {
    s21::list<int> l({-1, 0, 1, 2});
    l.clear();

    EXPECT_TRUE(l.empty());
}

TEST(s21_containers, s21_list_insert_1) {
    s21::list<int> l({-1, 0, 1, 2});
    l.insert(++l.begin(), 21);

    EXPECT_EQ(l.size(), 5);
    EXPECT_EQ(*(++l.begin()), 21);
}

TEST(s21_containers, s21_list_emplace_1) {
    s21::list<int> l({-1, 0, 1, 2});
    l.emplace(++l.begin(), 21, -21, 16);

    EXPECT_EQ(l.size(), 7);

    auto it = l.begin();
    EXPECT_EQ(*(++it), 21);
    EXPECT_EQ(*(++it), -21);
    EXPECT_EQ(*(++it), 16);
}

TEST(s21_containers, s21_list_emplace_2) {
    s21::list<int> l({-1, 0, 1, 2});
    l.emplace(++l.begin());

    EXPECT_EQ(l.size(), 4);
}

TEST(s21_containers, s21_list_erase_1) {
    s21::list<int> l({-1, 0, 1, 2});
    l.erase(++l.begin());

    EXPECT_EQ(*(++l.begin()), 1);
}

TEST(s21_containers, s21_list_erase_2) {
    s21::list<int> l;
    l.erase(l.begin());
}

TEST(s21_containers, s21_list_push_back_1) {
    s21::list<int> l({-1, 0, 1, 2});
    l.push_back(16);

    EXPECT_EQ(l.back(), 16);
}

TEST(s21_containers, s21_list_emplace_back_1) {
    s21::list<int> l({-1, 0, 1, 2});
    l.emplace_back(-6, 1, -21);

    EXPECT_EQ(l.size(), 7);
    EXPECT_EQ(l.back(), -21);
}

TEST(s21_containers, s21_list_pop_back_1) {
    s21::list<int> l({-1, 0, 1, 2});
    l.pop_back();

    EXPECT_EQ(l.size(), 3);
    EXPECT_EQ(l.back(), 1);
}

TEST(s21_containers, s21_list_push_front_1) {
    s21::list<int> l({-1, 0, 1, 2});
    l.push_front(16);

    EXPECT_EQ(l.front(), 16);
}

TEST(s21_containers, s21_list_emplace_front_1) {
    s21::list<int> l({-1, 0, 1, 2});
    l.emplace_front(-6, 1, -21);

    EXPECT_EQ(l.size(), 7);
    EXPECT_EQ(l.front(), -21);
}

TEST(s21_containers, s21_list_pop_front_1) {
    s21::list<int> l({-1, 0, 1, 2});
    l.pop_front();

    EXPECT_EQ(l.size(), 3);
    EXPECT_EQ(l.front(), 0);
}

TEST(s21_containers, s21_list_swap_1) {
    s21::list<int> l1({-1, 0, 1, 2});
    s21::list<int> l2({5, 3, 8});
    l1.swap(l2);

    EXPECT_EQ(l1.size(), 3);
    EXPECT_EQ(l2.size(), 4);

    EXPECT_EQ(l1.back(), 8);
    EXPECT_EQ(l2.back(), 2);
}

TEST(s21_containers, s21_list_merge_1) {
    s21::list<int> l1({-1, 0, 1, 2, 5});
    s21::list<int> l2({1, 1, 3, 5, 8});

    l1.merge(l2);

    int res[] = {-1, 0, 1, 1, 1, 2, 3, 5, 5, 8};

    std::size_t i = 0;
    for (auto it = l1.begin(); it != l1.end(); ++it) {
        EXPECT_EQ(*it, res[i++]);
    }
}

TEST(s21_containers, s21_list_splice_1) {
    s21::list<int> l1({-1, 0, 1, 5, 2});
    s21::list<int> l2({1, 8, 3, 5});

    l1.splice(++l1.begin(), l2);

    int res[] = {-1, 1, 8, 3, 5, 0, 1, 5, 2};

    std::size_t i = 0;
    for (auto it = l1.begin(); it != l1.end(); ++it) {
        EXPECT_EQ(*it, res[i++]);
    }
}

TEST(s21_containers, s21_list_reverse_1) {
    s21::list<int> l({-1, 0, 1, 5, 2});

    l.reverse();

    int res[] = {2, 5, 1, 0, -1};

    std::size_t i = 0;
    for (auto it = l.begin(); it != l.end(); ++it) {
        EXPECT_EQ(*it, res[i++]);
    }
}

TEST(s21_containers, s21_list_unique_1) {
    s21::list<int> l({0, 1, 1, 4, 7, 7, 7, 9, 10, 11, 11});

    l.unique();

    int res[] = {0, 1, 4, 7, 9, 10, 11};

    std::size_t i = 0;
    for (auto it = l.begin(); it != l.end(); ++it) {
        EXPECT_EQ(*it, res[i++]);
    }
}

TEST(s21_containers, s21_list_sort_1) {
    s21::list<int> l({10, -1, -21, 4, 5, 12, -21, 9});

    l.sort();

    int res[] = {-21, -21, -1, 4, 5, 9, 10, 12};

    std::size_t i = 0;
    for (auto it = l.begin(); it != l.end(); ++it) {
        EXPECT_EQ(*it, res[i++]);
    }
}

// s21_vector
TEST(s21_containers, s21_vector_constructor_1) {
    s21::vector<int> v;
    EXPECT_TRUE(v.empty());
}

TEST(s21_containers, s21_vector_constructor_2) {
    std::size_t size = 16;
    s21::vector<int> v(size);
    EXPECT_EQ(v.size(), size);
}

TEST(s21_containers, s21_vector_constructor_3) {
    std::initializer_list<int> l = {-1, 0, 1, 2};
    s21::vector<int> v(l);

    EXPECT_EQ(v.size(), l.size());

    auto lit = l.begin();
    auto vit = v.begin();
    for (; lit != l.end(); ++lit, ++vit) {
        EXPECT_EQ(*lit, *vit);
    }
}

TEST(s21_containers, s21_vector_constructor_4) {
    s21::vector<int> v1({-1, 0, 1, 2});
    s21::vector<int> v2(v1);

    EXPECT_EQ(v1.size(), v2.size());

    auto v1it = v1.begin();
    auto v2it = v2.begin();
    for (; v1it != v1.end(); ++v1it, ++v2it) {
        EXPECT_EQ(*v1it, *v2it);
    }
}

TEST(s21_containers, s21_vector_constructor_5) {
    s21::vector<int> v1({-1, 0, 1, 2});
    s21::vector<int> v2(std::move(v1));

    EXPECT_TRUE(v1.empty());
    EXPECT_EQ(v2.size(), 4);
}

TEST(s21_containers, s21_vector_assignment_operator_1) {
    s21::vector<int> v1({-1, 0, 1, 2});
    auto v2 = std::move(v1);

    EXPECT_TRUE(v1.empty());
    EXPECT_EQ(v2.size(), 4);
}

TEST(s21_containers, s21_vector_at_1) {
    s21::vector<int> v({-1, 0, 1, 2});

    EXPECT_EQ(v.at(3), 2);
}

TEST(s21_containers, s21_vector_at_2) {
    s21::vector<int> v({-1, 0, 1, 2});

    EXPECT_THROW({ v.at(-1); }, std::out_of_range);
}

TEST(s21_containers, s21_vector_square_brackets_operator_1) {
    s21::vector<int> v({-1, 0, 1, 2});

    EXPECT_EQ(v[0], -1);
}

TEST(s21_containers, s21_vector_front_1) {
    s21::vector<int> v({-1, 0, 1, 2});

    EXPECT_EQ(v.front(), -1);
}

TEST(s21_containers, s21_vector_back_1) {
    s21::vector<int> v({-1, 0, 1, 2});

    EXPECT_EQ(v.back(), 2);
}

TEST(s21_containers, s21_vector_data_1) {
    s21::vector<int> v({-1, 0, 1, 2});

    EXPECT_EQ(v.data()[2], 1);
}

TEST(s21_containers, s21_vector_begin_1) {
    s21::vector<int> v({-1, 0, 1, 2});

    EXPECT_EQ(*v.begin(), -1);
}

TEST(s21_containers, s21_vector_end_1) {
    s21::vector<int> v({-1, 0, 1, 2});

    EXPECT_EQ(*(--v.end()), 2);
}

TEST(s21_containers, s21_vector_empty_1) {
    s21::vector<int> v({});

    EXPECT_TRUE(v.empty());
}

TEST(s21_containers, s21_vector_size_1) {
    s21::vector<int> v({-1, 0, 1, 2});

    EXPECT_EQ(v.size(), 4);
}

TEST(s21_containers, s21_vector_max_size_1) {
    s21::vector<int> v({-1, 0, 1, 2});

    EXPECT_GT(v.max_size(), 0);
}

TEST(s21_containers, s21_vector_reserve_1) {
    s21::vector<int> v({-1, 0, 1, 2});
    v.reserve(128);

    EXPECT_EQ(v.capacity(), 128);
}

TEST(s21_containers, s21_vector_reserve_2) {
    s21::vector<int> v({-1, 0, 1, 2});
    v.reserve(2);

    EXPECT_EQ(v.capacity(), 2);
}

TEST(s21_containers, s21_vector_capacity_1) {
    s21::vector<int> v({-1, 0, 1, 2});

    EXPECT_GT(v.capacity(), 0);
}

TEST(s21_containers, s21_vector_shrink_to_fit_1) {
    s21::vector<int> v({-1, 0, 1, 2});
    v.shrink_to_fit();

    EXPECT_EQ(v.size(), v.capacity());
}

TEST(s21_containers, s21_vector_clear_1) {
    s21::vector<int> v({-1, 0, 1, 2});
    v.clear();

    EXPECT_TRUE(v.empty());
}

TEST(s21_containers, s21_vector_insert_1) {
    s21::vector<int> v({-1, 0, 1, 2});
    v.insert(++v.begin(), 21);

    EXPECT_EQ(v.size(), 5);
    EXPECT_EQ(*(++v.begin()), 21);
}

TEST(s21_containers, s21_vector_emplace_1) {
    s21::vector<int> v({-1, 0, 1, 2});
    v.emplace(++v.begin(), 21, -21, 16);

    EXPECT_EQ(v.size(), 7);

    auto it = v.begin();
    EXPECT_EQ(*(++it), 16);
    EXPECT_EQ(*(++it), -21);
    EXPECT_EQ(*(++it), 21);
}

TEST(s21_containers, s21_vector_emplace_2) {
    s21::vector<int> v({-1, 0, 1, 2});
    v.emplace(++v.begin());

    EXPECT_EQ(v.size(), 4);
}

TEST(s21_containers, s21_vector_erase_1) {
    s21::vector<int> v({-1, 0, 1, 2});
    v.erase(++v.begin());

    EXPECT_EQ(*(++v.begin()), 1);
}

TEST(s21_containers, s21_vector_erase_2) {
    s21::vector<int> v;
    v.erase(v.begin());
}

TEST(s21_containers, s21_vector_push_back_1) {
    s21::vector<int> v({-1, 0, 1, 2});
    v.push_back(16);

    EXPECT_EQ(v.back(), 16);
}

TEST(s21_containers, s21_vector_emplace_back_1) {
    s21::vector<int> v({-1, 0, 1, 2});
    v.emplace_back(-6, 1, -21);

    EXPECT_EQ(v.size(), 7);
    EXPECT_EQ(v.back(), -21);
}

TEST(s21_containers, s21_vector_pop_back_1) {
    s21::vector<int> v({-1, 0, 1, 2});
    v.pop_back();

    EXPECT_EQ(v.size(), 3);
    EXPECT_EQ(v.back(), 1);
}

TEST(s21_containers, s21_vector_swap_1) {
    s21::vector<int> v1({-1, 0, 1, 2});
    s21::vector<int> v2({5, 3, 8});
    v1.swap(v2);

    EXPECT_EQ(v1.size(), 3);
    EXPECT_EQ(v2.size(), 4);

    EXPECT_EQ(v1.back(), 8);
    EXPECT_EQ(v2.back(), 2);
}

// s21_stack
TEST(s21_containers, s21_stack_constructor_1) {
    s21::stack<int> stack;
    EXPECT_TRUE(stack.empty());
}

TEST(s21_containers, s21_stack_constructor_2) {
    s21::stack<int> stack({3, 2, 1});
    EXPECT_EQ(stack.size(), 3);
    for (int i = 1; i <= 3; i++) {
        EXPECT_EQ(stack.top(), i);
        stack.pop();
    }
}

TEST(s21_containers, s21_stack_constructor_3) {
    s21::stack<int> origin({3, 2, 1});
    s21::stack<int> stack(origin);
    EXPECT_EQ(stack.size(), 3);
    for (int i = 1; i <= 3; i++) {
        EXPECT_EQ(stack.top(), i);
        stack.pop();
    }
}

TEST(s21_containers, s21_stack_constructor_4) {
    s21::stack<int> origin({3, 2, 1});
    s21::stack<int> stack(std::move(origin));
    EXPECT_EQ(stack.size(), 3);
    for (int i = 1; i <= 3; i++) {
        EXPECT_EQ(stack.top(), i);
        stack.pop();
    }
    EXPECT_EQ(origin.size(), 0);
}

TEST(s21_containers, s21_stack_move_operator_1) {
    s21::stack<int> s1({-1, 0, 1, 2});
    auto s2 = std::move(s1);

    EXPECT_TRUE(s1.empty());
    EXPECT_EQ(s2.size(), 4);
}

TEST(s21_containers, s21_stack_top) {
    s21::stack<int> stack({3, 2, 1});
    EXPECT_EQ(stack.top(), 1);
    stack.top() = 10;
    EXPECT_EQ(stack.top(), 10);
}

TEST(s21_containers, s21_stack_size_empty) {
    s21::stack<int> stack_1;
    s21::stack<int> stack_2({3, 2, 1, 2, 4});
    s21::stack<int> stack_3({3, 2, 1});

    EXPECT_FALSE(stack_2.empty());
    EXPECT_TRUE(stack_1.empty());
    EXPECT_EQ(stack_1.size(), 0);
    EXPECT_EQ(stack_2.size(), 5);
    EXPECT_EQ(stack_3.size(), 3);
}

TEST(s21_containers, s21_stack_push) {
    s21::stack<int> stack;
    stack.push(1);
    EXPECT_EQ(stack.top(), 1);
}

TEST(s21_containers, s21_stack_pop) {
    s21::stack<int> stack({4, 5, 3});
    stack.pop();
    EXPECT_EQ(stack.top(), 5);
    EXPECT_EQ(stack.size(), 2);
}

TEST(s21_containers, s21_stack_swap) {
    s21::stack<int> stack_1({1, 2, 3, 4, 5});
    s21::stack<int> stack_2({4, 5, 6});
    stack_1.swap(stack_2);

    EXPECT_EQ(stack_1.size(), 3);
    for (int i = 6; i > 3; i--) {
        EXPECT_EQ(stack_1.top(), i);
        stack_1.pop();
    }

    EXPECT_EQ(stack_2.size(), 5);
    for (int i = 5; i > 0; i--) {
        EXPECT_EQ(stack_2.top(), i);
        stack_2.pop();
    }
}

TEST(s21_containers, s21_stack_emplace_front) {
    s21::stack<int> stack({2, 1});
    stack.emplace_front(3, 4, 5);

    EXPECT_EQ(stack.size(), 5);
    for (int i = 1; i <= 5; i++) {
        EXPECT_EQ(stack.top(), i);
        stack.pop();
    }
}

// s21_queue
TEST(s21_containers, s21_queue_constructor_1) {
    s21::queue<int> q;
    EXPECT_TRUE(q.empty());
}

TEST(s21_containers, s21_queue_constructor_2) {
    s21::queue<int> q({1, 2, 3});
    EXPECT_EQ(q.size(), 3);
    for (int i = 1; i <= 3; i++) {
        EXPECT_EQ(q.front(), i);
        q.pop();
    }
}

TEST(s21_containers, s21_queue_constructor_3) {
    s21::queue<int> origin({1, 2, 3});
    s21::queue<int> q(origin);
    EXPECT_EQ(q.size(), 3);
    for (int i = 1; i <= 3; i++) {
        EXPECT_EQ(q.front(), i);
        q.pop();
    }
}

TEST(s21_containers, s21_queue_constructor_4) {
    s21::queue<int> origin({1, 2, 3});
    s21::queue<int> q(std::move(origin));
    EXPECT_EQ(q.size(), 3);
    for (int i = 1; i <= 3; i++) {
        EXPECT_EQ(q.front(), i);
        q.pop();
    }
    EXPECT_EQ(origin.size(), 0);
}

TEST(s21_containers, s21_queue_move_operator_1) {
    s21::queue<int> s1({-1, 0, 1, 2});
    auto s2 = std::move(s1);

    EXPECT_TRUE(s1.empty());
    EXPECT_EQ(s2.size(), 4);
}

TEST(s21_containers, s21_queue_front) {
    s21::queue<int> q({3, 2, 1});
    EXPECT_EQ(q.front(), 3);
    q.front() = 10;
    EXPECT_EQ(q.front(), 10);
}

TEST(s21_containers, s21_queue_size_empty) {
    s21::queue<int> q_1;
    s21::queue<int> q_2({3, 2, 1, 2, 4});
    s21::queue<int> q_3({3, 2, 1});

    EXPECT_FALSE(q_2.empty());
    EXPECT_TRUE(q_1.empty());
    EXPECT_EQ(q_1.size(), 0);
    EXPECT_EQ(q_2.size(), 5);
    EXPECT_EQ(q_3.size(), 3);
}

TEST(s21_containers, s21_queue_push) {
    s21::queue<int> q;
    q.push(1);
    q.push(2);
    EXPECT_EQ(q.front(), 1);
    EXPECT_EQ(q.back(), 2);
}

TEST(s21_containers, s21_queue_pop) {
    s21::queue<int> q({4, 5, 3});
    q.pop();
    EXPECT_EQ(q.front(), 5);
    EXPECT_EQ(q.size(), 2);
}

TEST(s21_containers, s21_queue_swap) {
    s21::queue<int> q_1({1, 2, 3, 4, 5});
    s21::queue<int> q_2({4, 5, 6});
    q_1.swap(q_2);

    EXPECT_EQ(q_1.size(), 3);
    for (int i = 4; i <= 6; i++) {
        EXPECT_EQ(q_1.front(), i);
        q_1.pop();
    }

    EXPECT_EQ(q_2.size(), 5);
    for (int i = 1; i <= 5; i++) {
        EXPECT_EQ(q_2.front(), i);
        q_2.pop();
    }
}

TEST(s21_containers, s21_queue_emplace_back) {
    s21::queue<int> q({1, 2});
    q.emplace_back(3, 4, 5);

    EXPECT_EQ(q.size(), 5);
    for (int i = 1; i <= 5; i++) {
        EXPECT_EQ(q.front(), i);
        q.pop();
    }
}

// s21_array
TEST(s21_containers, s21_array_constructor_1) {
    s21::array<int, 1> a;
    EXPECT_EQ(a.size(), 1);
}

TEST(s21_containers, s21_array_constructor_2) {
    s21::array<int, 5> a({0, 1, 2, 3, 4});
    EXPECT_EQ(a.size(), 5);
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(a[i], i);
    }
}

TEST(s21_containers, s21_array_constructor_3) {
    s21::array<int, 5> origin({0, 1, 2, 3, 4});
    s21::array<int, 5> a(origin);

    EXPECT_EQ(a.size(), 5);
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(a[i], i);
    }
}

TEST(s21_containers, s21_array_constructor_4) {
    s21::array<int, 5> origin({0, 1, 2, 3, 4});
    s21::array<int, 5> a(std::move(origin));

    EXPECT_EQ(a.size(), 5);
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(a[i], i);
    }
}

TEST(s21_containers, s21_array_assignment_operator_1) {
    s21::array<int, 4> a1({-1, 0, 1, 2});
    auto a2 = std::move(a1);

    EXPECT_EQ(a2.size(), 4);
}

TEST(s21_containers, s21_array_at_1) {
    s21::array<int, 4> a({-1, 0, 1, 2});

    EXPECT_EQ(a.at(3), 2);
}

TEST(s21_containers, s21_array_at_2) {
    s21::array<int, 4> a({-1, 0, 1, 2});

    EXPECT_THROW({ a.at(-1); }, std::out_of_range);
}

TEST(s21_containers, s21_array_square_brackets_operator_1) {
    s21::array<int, 4> a({-1, 0, 1, 2});

    a[1] = 10;
    EXPECT_EQ(a[0], -1);
    EXPECT_EQ(a[1], 10);
}

TEST(s21_containers, s21_array_front_1) {
    s21::array<int, 4> a({-1, 0, 1, 2});

    EXPECT_EQ(a.front(), -1);
}

TEST(s21_containers, s21_array_back_1) {
    s21::array<int, 4> a({-1, 0, 1, 2});

    EXPECT_EQ(a.back(), 2);
}

TEST(s21_containers, s21_array_data_1) {
    s21::array<int, 4> a({-1, 0, 1, 2});

    EXPECT_EQ(a.data()[2], 1);
}

TEST(s21_containers, s21_array_begin_1) {
    s21::array<int, 4> a({-1, 0, 1, 2});

    EXPECT_EQ(*a.begin(), -1);
}

TEST(s21_containers, s21_array_end_1) {
    s21::array<int, 4> a({-1, 0, 1, 2});

    EXPECT_EQ(*(a.end() - 1), 2);
}

TEST(s21_containers, s21_array_empty_1) {
    s21::array<int, 0> a({});

    EXPECT_TRUE(a.empty());
}

TEST(s21_containers, s21_array_size_1) {
    s21::array<int, 4> a({-1, 0, 1, 2});

    EXPECT_EQ(a.size(), 4);
}

TEST(s21_containers, s21_array_max_size_1) {
    s21::array<int, 4> a({-1, 0, 1, 2});

    EXPECT_GT(a.max_size(), 0);
}

TEST(s21_containers, s21_array_swap_1) {
    s21::array<int, 4> a1({-1, 0, 1, 2});
    s21::array<int, 4> a2({5, 3, 8, 6});
    a1.swap(a2);

    EXPECT_EQ(a1.size(), 4);
    EXPECT_EQ(a2.size(), 4);

    EXPECT_EQ(a1.back(), 6);
    EXPECT_EQ(a2.back(), 2);

    EXPECT_EQ(a1.front(), 5);
    EXPECT_EQ(a2.front(), -1);
}

TEST(s21_containers, s21_array_fill) {
    s21::array<int, 4> a;
    a.fill(4);
    for (const auto i : a) {
        EXPECT_EQ(i, 4);
    }
}

// s21_map
TEST(s21_containers, s21_map_constructor_1) {
    s21::map<int, char> m;
    EXPECT_TRUE(m.empty());
}

TEST(s21_containers, s21_map_constructor_2) {
    s21::map<int, std::string> m{{42, "foo"}, {3, "bar"}};
    EXPECT_EQ(m.size(), 2);
    EXPECT_EQ(m[42], "foo");
}

TEST(s21_containers, s21_map_constructor_3) {
    s21::map<int, std::string> origin{{42, "foo"}, {3, "bar"}};
    s21::map<int, std::string> m(origin);
    EXPECT_EQ(m.size(), 2);
    EXPECT_EQ(m[42], "foo");
    EXPECT_EQ(origin.size(), 2);
    EXPECT_EQ(origin[42], "foo");
}

TEST(s21_containers, s21_map_constructor_4) {
    s21::map<int, std::string> origin{{42, "foo"}, {3, "bar"}};
    s21::map<int, std::string> m(std::move(origin));
    EXPECT_EQ(m.size(), 2);
    EXPECT_EQ(m[42], "foo");
    EXPECT_EQ(origin.size(), 0);
}

TEST(s21_containers, s21_map_move_operator) {
    s21::map<int, std::string> origin{{42, "foo"}, {3, "bar"}};
    s21::map<int, std::string> m;
    m = std::move(origin);
    EXPECT_EQ(m.size(), 2);
    EXPECT_EQ(m[42], "foo");
    EXPECT_EQ(origin.size(), 0);
}

TEST(s21_containers, s21_map_at) {
    s21::map<int, std::string> m{{42, "foo"}, {3, "bar"}};
    m.at(3) = "abba";
    EXPECT_THROW(m.at(2) = "ads", std::out_of_range);
    EXPECT_EQ(m.at(42), "foo");
    EXPECT_EQ(m.at(3), "abba");
}

TEST(s21_containers, s21_map_brackets) {
    s21::map<int, std::string> m{{42, "foo"}, {3, "bar"}};
    m[3] = "abba";
    EXPECT_EQ(m[42], "foo");
    EXPECT_EQ(m[3], "abba");
}

TEST(s21_containers, s21_map_begin) {
    s21::map<int, std::string> m{{42, "foo"}, {3, "bar"}};
    EXPECT_EQ((*(m.begin())).second, "bar");
}

TEST(s21_containers, s21_map_end) {
    s21::map<int, std::string> m{{42, "foo"}, {3, "bar"}};
    EXPECT_EQ((*(--m.end())).second, "foo");
}

TEST(s21_containers, s21_map_empty) {
    s21::map<int, std::string> m1;
    s21::map<int, std::string> m2{{42, "foo"}, {3, "bar"}};
    EXPECT_TRUE(m1.empty());
    EXPECT_FALSE(m2.empty());
}

TEST(s21_containers, s21_map_size) {
    s21::map<int, std::string> m{{42, "foo"}, {3, "bar"}};
    EXPECT_EQ(m.size(), 2);
}

TEST(s21_containers, s21_map_clear) {
    s21::map<int, std::string> m{{42, "foo"}, {3, "bar"}};
    m.clear();
    EXPECT_TRUE(m.empty());
}

TEST(s21_containers, s21_map_insert_1) {
    s21::map<int, std::string> m;
    m.insert({32, "hello"});
    EXPECT_EQ(m[32], "hello");
}

TEST(s21_containers, s21_map_insert_or_assign) {
    s21::map<int, std::string> m;
    m.insert_or_assign(32, "hello");
    EXPECT_EQ(m[32], "hello");
}

TEST(s21_containers, s21_map_erase) {
    s21::map<int, std::string> m{{42, "foo"}, {3, "bar"}};
    m.erase(m.begin());
    m.erase(m.begin());
    EXPECT_TRUE(m.empty());
}

TEST(s21_containers, s21_map_swap) {
    s21::map<int, std::string> m1{{42, "foo"}, {3, "bar"}};
    s21::map<int, std::string> m2{{33, "foofoo"}, {4, "barbar"}};
    m1.swap(m2);

    EXPECT_EQ(m1[33], "foofoo");
    EXPECT_EQ(m1[4], "barbar");
    EXPECT_EQ(m2[42], "foo");
    EXPECT_EQ(m2[3], "bar");
}

TEST(s21_containers, s21_map_merge) {
    s21::map<int, std::string> m1{{42, "foo"}, {3, "bar"}};
    s21::map<int, std::string> m2{{33, "foofoo"}, {4, "barbar"}};
    m1.merge(m2);

    EXPECT_EQ(m1[33], "foofoo");
    EXPECT_EQ(m1[4], "barbar");
    EXPECT_EQ(m1[42], "foo");
    EXPECT_EQ(m1[3], "bar");
}

TEST(s21_containers, s21_map_contains) {
    s21::map<int, std::string> m{{42, "foo"}, {3, "bar"}};

    EXPECT_TRUE(m.contains(42));
    EXPECT_FALSE(m.contains(4));
}

TEST(s21_containers, s21_map_emplase) {
    s21::map<int, float> s(
        {{1, 0.21}, {3, 0.21}, {8, 0.21}, {5, 0.21}, {-2, 0.21}});
    std::pair<int, float> p1({9, 0.21}), p2({-1, 0.21}), p3({1, 0.21});
    s.emplace(p1, p2, p3);
    EXPECT_EQ(s.size(), 7);
}

// s21_set
TEST(s21_containers, s21_set_constructor_1) {
    s21::set<int> s;
    EXPECT_TRUE(s.empty());
}

TEST(s21_containers, s21_set_constructor_2) {
    s21::set<int> s({5, 3, 4, 6});
    EXPECT_EQ(s.size(), 4);
    EXPECT_EQ(*s.begin(), 3);
    EXPECT_EQ(*--s.end(), 6);
}

TEST(s21_containers, s21_set_constructor_3) {
    s21::set<int> origin({5, 3, 4, 6});
    s21::set<int> s(origin);
    EXPECT_EQ(s.size(), 4);
    EXPECT_EQ(*s.begin(), 3);
    EXPECT_EQ(*--s.end(), 6);
    EXPECT_EQ(origin.size(), 4);
    EXPECT_EQ(*origin.begin(), 3);
    EXPECT_EQ(*--origin.end(), 6);
}

TEST(s21_containers, s21_set_constructor_4) {
    s21::set<int> origin({5, 3, 4, 6});
    s21::set<int> s(std::move(origin));
    EXPECT_EQ(s.size(), 4);
    EXPECT_EQ(*s.begin(), 3);
    EXPECT_EQ(*--s.end(), 6);
    EXPECT_EQ(origin.size(), 0);
}

TEST(s21_containers, s21_set_constructor_5) {
    s21::set<int> origin({5, 3, 4, 6});
    s21::set<int> s;
    s = std::move(origin);
    EXPECT_EQ(s.size(), 4);
    EXPECT_EQ(*s.begin(), 3);
    EXPECT_EQ(*--s.end(), 6);
    EXPECT_EQ(origin.size(), 0);
}

TEST(s21_containers, s21_set_it_begin_end) {
    s21::set<int> s({5, 3, 4, 6});
    EXPECT_EQ(*s.begin(), 3);
    EXPECT_EQ(*--s.end(), 6);
}

TEST(s21_containers, s21_set_empty) {
    s21::set<int> s1;
    s21::set<int> s2({1});
    EXPECT_TRUE(s1.empty());
    EXPECT_FALSE(s2.empty());
}

TEST(s21_containers, s21_set_size) {
    s21::set<int> s1;
    s21::set<int> s2({1, 2, 3, 4, 5});
    EXPECT_EQ(s1.size(), 0);
    EXPECT_EQ(s2.size(), 5);
}

TEST(s21_containers, s21_set_clear) {
    s21::set<int> s({1});
    s.clear();
    EXPECT_TRUE(s.empty());
}

TEST(s21_containers, s21_set_insert) {
    s21::set<int> s({1, 2, 3, 4, 5});

    EXPECT_EQ(*(s.insert(10).first), 10);
}

TEST(s21_containers, s21_set_erase) {
    s21::set<int> s({8, 1, 2, 3, 7, 4, 5, 6});
    for (auto it = s.begin(); it != s.end();) {
        if ((*it) % 2 == 0) {
            auto tmp = it;
            it++;
            s.erase(tmp);
        } else {
            it++;
        }
    }
    EXPECT_EQ(*s.begin(), 1);
}

TEST(s21_containers, s21_set_swap) {
    s21::set<int> s1({1, 2, 3, 4, 5});
    s21::set<int> s2({6, 7, 8, 9, 10});
    s1.swap(s2);
    EXPECT_EQ(*s1.begin(), 6);
    EXPECT_EQ(*--s1.end(), 10);
    EXPECT_EQ(*s2.begin(), 1);
    EXPECT_EQ(*--s2.end(), 5);
}

TEST(s21_containers, s21_set_merge) {
    s21::set<int> s1({1, 2, 3, 4, 5});
    s21::set<int> s2({5, 7, 8, 9, 10});
    s1.merge(s2);
    EXPECT_EQ(s1.size(), 9);
    EXPECT_EQ(*s1.begin(), 1);
    EXPECT_EQ(*--s1.end(), 10);
}

TEST(s21_containers, s21_set_find) {
    s21::set<int> s({1, 3, 4, 5, 6});
    EXPECT_EQ(*s.find(5), 5);
    EXPECT_EQ(*s.find(3), 3);
}

TEST(s21_containers, s21_set_contains) {
    s21::set<int> s({1, 3, 4, 5, 6});
    EXPECT_TRUE(s.contains(5));
    EXPECT_TRUE(s.contains(6));
    EXPECT_FALSE(s.contains(7));
}

TEST(s21_containers, s21_set_emplase) {
    s21::set<int> s({1, 3, 8, 5, -2});
    s.emplace(9, -1, 1);
    EXPECT_EQ(s.size(), 7);
}

// s21_multiset
TEST(s21_containers, s21_multiset_constructor_1) {
    s21::multiset<int> m;
    EXPECT_TRUE(m.empty());
}

TEST(s21_containers, s21_multiset_constructor_2) {
    s21::multiset<int> m({5, 3, 4, 6, 6});
    EXPECT_EQ(m.size(), 5);
    EXPECT_EQ(*m.begin(), 3);
    EXPECT_EQ(*--m.end(), 6);
}

TEST(s21_containers, s21_multiset_constructor_3) {
    s21::multiset<int> origin({5, 3, 4, 6});
    s21::multiset<int> m(origin);
    EXPECT_EQ(m.size(), 4);
    EXPECT_EQ(*m.begin(), 3);
    EXPECT_EQ(*--m.end(), 6);
    EXPECT_EQ(origin.size(), 4);
    EXPECT_EQ(*origin.begin(), 3);
    EXPECT_EQ(*--origin.end(), 6);
}

TEST(s21_containers, s21_multiset_constructor_4) {
    s21::multiset<int> origin({5, 3, 4, 6});
    s21::multiset<int> m(std::move(origin));
    EXPECT_EQ(m.size(), 4);
    EXPECT_EQ(*m.begin(), 3);
    EXPECT_EQ(*--m.end(), 6);
    EXPECT_EQ(origin.size(), 0);
}

TEST(s21_containers, s21_multiset_constructor_5) {
    s21::multiset<int> origin({5, 3, 4, 6});
    s21::multiset<int> m;
    m = std::move(origin);
    EXPECT_EQ(m.size(), 4);
    EXPECT_EQ(*m.begin(), 3);
    EXPECT_EQ(*--m.end(), 6);
    EXPECT_EQ(origin.size(), 0);
}

TEST(s21_containers, s21_multiset_it_begin_end) {
    s21::multiset<int> m({5, 3, 4, 6});
    EXPECT_EQ(*m.begin(), 3);
    EXPECT_EQ(*--m.end(), 6);
}

TEST(s21_containers, s21_multiset_empty) {
    s21::multiset<int> m1;
    s21::multiset<int> m2({1});
    EXPECT_TRUE(m1.empty());
    EXPECT_FALSE(m2.empty());
}

TEST(s21_containers, s21_multiset_size) {
    s21::multiset<int> m1;
    s21::multiset<int> m2({1, 2, 3, 4, 5});
    EXPECT_EQ(m1.size(), 0);
    EXPECT_EQ(m2.size(), 5);
}

TEST(s21_containers, s21_multiset_insert) {
    s21::multiset<int> m({1, 2, 3, 4, 5});

    EXPECT_EQ(*(m.insert(10).first), 10);
}

TEST(s21_containers, s21_multiset_erase) {
    s21::multiset<int> m({1, 2, 3, 4, 5});
    m.erase(m.begin());
    EXPECT_EQ(*m.begin(), 2);
}

TEST(s21_containers, s21_multiset_swap) {
    s21::multiset<int> m1({1, 2, 3, 4, 5});
    s21::multiset<int> m2({6, 7, 8, 9, 10});
    m1.swap(m2);
    EXPECT_EQ(*m1.begin(), 6);
    EXPECT_EQ(*--m1.end(), 10);
    EXPECT_EQ(*m2.begin(), 1);
    EXPECT_EQ(*--m2.end(), 5);
}

TEST(s21_containers, s21_multiset_merge) {
    s21::multiset<int> m1({1, 2, 3, 4, 5});
    s21::multiset<int> m2({5, 7, 8, 9, 10});
    m1.merge(m2);
    EXPECT_EQ(m1.size(), 10);
    EXPECT_EQ(*m1.begin(), 1);
    EXPECT_EQ(*--m1.end(), 10);
}

TEST(s21_containers, s21_multiset_count) {
    s21::multiset<int> m({1, 3, 3, 3, 6});
    EXPECT_EQ(m.count(3), 3);
    EXPECT_EQ(m.count(6), 1);
    EXPECT_EQ(m.count(10), 0);
}

TEST(s21_containers, s21_multiset_find) {
    s21::multiset<int> m({1, 3, 4, 5, 6});
    EXPECT_EQ(*m.find(5), 5);
    EXPECT_EQ(*m.find(3), 3);
}

TEST(s21_containers, s21_multiset_contains) {
    s21::multiset<int> m({1, 3, 4, 5, 6});
    EXPECT_TRUE(m.contains(5));
    EXPECT_TRUE(m.contains(6));
    EXPECT_FALSE(m.contains(7));
}

TEST(s21_containers, s21_multiset_equal_range) {
    s21::multiset<int> m({1, 3, 4, 5, 5, 5, 5, 6});
    auto range = m.equal_range(5);
    for (auto it = range.first; it != range.second; it++) {
        EXPECT_EQ(*it, 5);
    }
}

TEST(s21_containers, s21_multiset_lower_upper_bound) {
    s21::multiset<int> m({1, 3, 4, 5, 5, 5, 5, 6});

    for (auto it = m.lower_bound(5); it != m.upper_bound(5); it++) {
        EXPECT_EQ(*it, 5);
    }
}

TEST(s21_containers, s21_multiset_emplase) {
    s21::multiset<int> s({1, 3, 8, 5, -2});
    s.emplace(9, -1, 1);
    EXPECT_EQ(s.size(), 8);
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
