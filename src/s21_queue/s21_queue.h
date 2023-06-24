#ifndef CONTAINERS_CPP_S21_QUEUE_S21_QUEUE_H
#define CONTAINERS_CPP_S21_QUEUE_S21_QUEUE_H

#include <iostream>

#include "../s21_list/s21_list.cc"

namespace s21 {
template <class T>
class queue : public list<T> {
 public:
  // Members type
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  // Constructors
  queue();
  queue(size_type n);
  queue(std::initializer_list<value_type> const &items);
  queue(const queue &q);
  queue(queue &&q);
  ~queue();

  // Overload operators
  queue operator=(queue &&q);

  // Modifiers
  void push(const_reference value);
  void pop();
};
}  // namespace s21

#endif  // CONTAINERS_CPP_S21_QUEUE_S21_QUEUE_H
