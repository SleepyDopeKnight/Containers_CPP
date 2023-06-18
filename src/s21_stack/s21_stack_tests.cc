#include <stack>

#include "gtest/gtest.h"
#include "s21_stack.cc"

TEST(stack_empty_test_suite, empty_stack_true_test) {
  s21::stack<int> s;
  EXPECT_TRUE(s.empty());
}

TEST(stack_empty_test_suite, non_empty_stack_false_test) {
  s21::stack<int> s({});
  s.push(42);
  EXPECT_FALSE(s.empty());
  EXPECT_FALSE(s.size() == 0);
}

TEST(stack_empty_test_suite, push_pop_stack_true_test) {
  s21::stack<int> s(0);
  s.push(42);
  s.pop();
  EXPECT_TRUE(s.empty());
  EXPECT_TRUE(s.size() == 0);
}

TEST(swap_test_suite, swap_true_test) {
  s21::stack<int> stack1({});
  stack1.push(1);
  stack1.push(2);

  s21::stack<int> stack2({});
  stack2.push(3);
  stack2.push(4);

  stack1.swap(stack2);

  EXPECT_TRUE(stack1.top() == 4);
  EXPECT_TRUE(stack1.size() == 2);

  EXPECT_TRUE(stack2.top() == 2);
  EXPECT_TRUE(stack2.size() == 2);
}

TEST(copy_constructor_suite, int_true_test) {
  s21::stack<int> s21_b(5);
  s21::stack<int> s21_a(s21_b);

  EXPECT_TRUE(s21_a.empty() == s21_b.empty());
  EXPECT_TRUE(s21_b.size() == s21_b.size());
}

TEST(move_constructor_suite, int_true_test) {
  s21::stack<int> s21_a({1, 2, 3});
  s21::stack<int> s21_b(std::move(s21_a));
  std::stack<int> std_a({1, 2, 3});
  std::stack<int> std_b(std::move(std_a));

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());

  EXPECT_TRUE(s21_b.empty() == std_b.empty());
  EXPECT_TRUE(s21_b.size() == std_b.size());

  EXPECT_TRUE(s21_a.empty() != s21_b.empty());
  EXPECT_TRUE(s21_a.size() != s21_b.size());
}

TEST(move_operator_constructor_suite, int_true_test) {
  s21::stack<int> s21_a({1, 2, 3});
  s21::stack<int> s21_b = s21_a;
  std::stack<int> std_a({1, 2, 3});
  std::stack<int> std_b = std_a;

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
  EXPECT_TRUE(s21_b.empty() == std_b.empty());
  EXPECT_TRUE(s21_b.size() == std_b.size());
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
