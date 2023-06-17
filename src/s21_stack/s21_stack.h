#ifndef SRC_S21_STACK_S21_STACK_H
#define SRC_S21_STACK_S21_STACK_H

#include "../s21_list/s21_list.cc"

namespace s21 {
template <class T>
class stack : public list<T> {
 public:
  // Members type
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  // Constructors
  stack();
  stack(size_type n);
  stack(std::initializer_list<value_type> const &items);
  stack(const stack &s);
  stack(stack &&s);
  ~stack();

  // Overload operators
  stack operator=(stack &&s);

  // Capacity
  bool empty() const;
  size_type size() const;

  // Element access
  const_reference top() const;

  // Modifiers
  void push(const_reference value);
  void pop();
  void swap(stack &other);

  // Additional
  void MoveStack(stack &s);
  void clear();


 private:
  struct node_ {
    value_type value_;
    node_ *next_ = nullptr;
    node_ *previous_ = nullptr;
  };
  node_ *head_ = nullptr;
  node_ *tail_ = nullptr;
  node_ *end_node_ = nullptr;
  size_type size_ = 0;
};
}  // namespace s21

#endif  // SRC_S21_STACK_S21_STACK_H
