#ifndef SRC_S21_STACK_S21_STACK_H
#define SRC_S21_STACK_S21_STACK_H

namespace s21 {
template <class T>
class stack {
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
  };
  node_ *head_ = nullptr;
  size_type size_ = 0;
};
}  // namespace s21

#endif  // SRC_S21_STACK_S21_STACK_H
