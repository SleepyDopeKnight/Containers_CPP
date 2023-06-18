#include <queue>

#include "gtest/gtest.h"
#include "s21_queue.cc"

TEST(queue_empty_test_suite, empty_queue_true_test) {
  s21::queue<int> s;
  EXPECT_TRUE(s.empty());
}

TEST(queue_empty_test_suite, non_empty_queue_false_test) {
  s21::queue<int> s({});
  s.push(42);
  EXPECT_FALSE(s.empty());
  EXPECT_FALSE(s.size() == 0);
}

TEST(queue_empty_test_suite, push_pop_queue_true_test) {
  s21::queue<int> s(0);
  s.push(42);
  s.pop();
  EXPECT_TRUE(s.empty());
  EXPECT_TRUE(s.size() == 0);
}

TEST(swap_test_suite, swap_true_test) {
  s21::queue<int> queue1({});
  queue1.push(1);
  queue1.push(2);

  s21::queue<int> queue2({});
  queue2.push(3);
  queue2.push(4);

  queue1.swap(queue2);

  EXPECT_TRUE(queue1.front() == 3);
  EXPECT_TRUE(queue1.back() == 4);
  EXPECT_TRUE(queue1.size() == 2);

  EXPECT_TRUE(queue2.front() == 1);
  EXPECT_TRUE(queue2.back() == 2);
  EXPECT_TRUE(queue2.size() == 2);
}

TEST(copy_constructor_suite, int_true_test) {
  s21::queue<int> s21_b(5);
  s21::queue<int> s21_a(s21_b);

  EXPECT_TRUE(s21_a.empty() == s21_b.empty());
  EXPECT_TRUE(s21_b.size() == s21_b.size());
}

TEST(move_constructor_suite, int_true_test) {
  s21::queue<int> s21_a({1, 2, 3});
  s21::queue<int> s21_b(std::move(s21_a));
  std::queue<int> std_a({1, 2, 3});
  std::queue<int> std_b(std::move(std_a));

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());

  EXPECT_TRUE(s21_b.empty() == std_b.empty());
  EXPECT_TRUE(s21_b.size() == std_b.size());

  EXPECT_TRUE(s21_a.empty() != s21_b.empty());
  EXPECT_TRUE(s21_a.size() != s21_b.size());
}

TEST(move_operator_constructor_suite, int_true_test) {
  s21::queue<int> s21_a({1, 2, 3});
  s21::queue<int> s21_b = s21_a;
  std::queue<int> std_a({1, 2, 3});
  std::queue<int> std_b = std_a;

  EXPECT_TRUE(s21_a.empty() == std_a.empty());
  EXPECT_TRUE(s21_a.size() == std_a.size());
  EXPECT_TRUE(s21_b.empty() == std_b.empty());
  EXPECT_TRUE(s21_b.size() == std_b.size());
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
