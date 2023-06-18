#include "s21_stack.h"

// Constructors
template <class T>
s21::stack<T>::stack() : list<T>() {}

template <class T>
s21::stack<T>::stack(size_type n) : list<T>(n) {}

template <class T>
s21::stack<T>::stack(std::initializer_list<value_type> const &items)
    : list<T>(items) {}

template <class T>
s21::stack<T>::stack(const stack &s) : list<T>(s) {}

template <class T>
s21::stack<T>::stack(stack &&s) {
  s21::list<T>::MoveList(s);
}

template <class T>
s21::stack<T>::~stack() {}

// Overload operators
template <class T>
s21::stack<T> s21::stack<T>::operator=(stack &&s) {
  *this = list<T>::operator=(s);
  return *this;
}

// Capacity
template <class T>
bool s21::stack<T>::empty() const {
  return s21::list<T>::empty();
}

template <class T>
typename s21::stack<T>::size_type s21::stack<T>::size() const {
  return s21::list<T>::size();
}

// Element access
template <class T>
typename s21::stack<T>::const_reference s21::stack<T>::top() const {
  return s21::list<T>::back();
}

// Modifiers
template <class T>
void s21::stack<T>::push(const_reference value) {
  s21::list<T>::push_back(value);
}

template <class T>
void s21::stack<T>::pop() {
  s21::list<T>::pop_back();
}

template <class T>
void s21::stack<T>::swap(stack &other) {
  s21::list<T>::swap(other);
}
