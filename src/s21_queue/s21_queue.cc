#include "s21_queue.h"

// Constructors
template <class T>
s21::queue<T>::queue() : list<T>() {}

template <class T>
s21::queue<T>::queue(size_type n) : list<T>(n) {}

template <class T>
s21::queue<T>::queue(std::initializer_list<value_type> const &items)
    : list<T>(items) {}

template <class T>
s21::queue<T>::queue(const queue &q) : list<T>(q) {}

template <class T>
s21::queue<T>::queue(queue &&q) {
  s21::list<T>::MoveList(q);
}

template <class T>
s21::queue<T>::~queue() {}

// Overload operators
template <class T>
s21::queue<T> s21::queue<T>::operator=(queue &&q) {
  *this = list<T>::operator=(q);
  return *this;
}

// Capacity
template <class T>
bool s21::queue<T>::empty() const {
  return s21::list<T>::empty();
}

template <class T>
typename s21::queue<T>::size_type s21::queue<T>::size() const {
  return s21::list<T>::size();
}

// Element access
template <class T>
typename s21::queue<T>::const_reference s21::queue<T>::front() const {
  return s21::list<T>::front();
}

template <class T>
typename s21::queue<T>::const_reference s21::queue<T>::back() const {
  return s21::list<T>::back();
}

// Modifiers
template <class T>
void s21::queue<T>::push(const_reference value) {
  s21::list<T>::push_back(value);
}

template <class T>
void s21::queue<T>::pop() {
  s21::list<T>::pop_front();
}

template <class T>
void s21::queue<T>::swap(queue &other) {
  s21::list<T>::swap(other);
}
