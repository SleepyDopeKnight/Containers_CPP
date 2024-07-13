#ifndef CONTAINERS_CPP_S21_VECTOR_S21_VECTOR_H_
#define CONTAINERS_CPP_S21_VECTOR_S21_VECTOR_H_

#include <cstring>
#include <initializer_list>
#include <iostream>

#include "cstdio"

namespace s21 {
template <class T>
class vector {
 public:
  // Members type
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  // Constructors
  vector();
  vector(size_type n);
  vector(std::initializer_list<value_type> const &items);
  vector(const vector &v);
  vector(vector &&v) noexcept;
  ~vector();

  // Overload operators
  vector &operator=(vector &&v) noexcept;

  // Element access
  reference at(size_type pos);
  reference operator[](size_type pos);
  const_reference front();
  const_reference back();
  iterator data();

  // Iterators
  iterator begin() const;
  iterator end() const;

  // Capacity
  bool empty();
  size_type size();
  size_type max_size();
  void reserve(size_type size);
  size_type capacity();
  void shrink_to_fit();

  // Modifiers
  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void swap(vector &other);

  // Additional
  void filling();

 private:
  T *begin_ = nullptr;
  size_t size_ = 0;
  size_t capacity_ = 0;

  // Additional
  void reallocator();
};
}  // namespace s21

// Constructors
template <class T>
s21::vector<T>::vector() = default;

template <class T>
s21::vector<T>::vector(size_type n) {
  begin_ = new T[n];
  size_ = n;
  capacity_ = n;
}

template <class T>
s21::vector<T>::vector(std::initializer_list<value_type> const &items)
    : vector(items.size()) {
  auto itr = items.begin();
  std::memcpy(begin_, itr, size_ * sizeof(T));
}

template <class T>
s21::vector<T>::vector(const vector &v)
    : size_(v.size_), capacity_(v.capacity_) {
  begin_ = new T[capacity_];
  std::memcpy(begin_, v.begin_, v.size_ * sizeof(T));
}

template <class T>
s21::vector<T>::vector(vector &&v) noexcept {
  if (this != &v) {
    if (begin_) {
      delete[] begin_;
    }
    size_ = 0;
    capacity_ = 0;
    begin_ = nullptr;
    std::swap(size_, v.size_);
    std::swap(capacity_, v.capacity_);
    std::swap(begin_, v.begin_);
  }
}

template <class T>
s21::vector<T>::~vector() {
  clear();
}

// Overload operators
template <class T>
typename s21::vector<T>& s21::vector<T>::operator=(vector&& v) noexcept {
  if (begin_) {
    delete[] begin_;
  }
  size_ = 0;
  capacity_ = 0;
  begin_ = nullptr;
  std::swap(size_, v.size_);
  std::swap(capacity_, v.capacity_);
  std::swap(begin_, v.begin_);
  return *this;
}


template <class T>
typename s21::vector<T>::reference s21::vector<T>::operator[](size_type pos) {
  return begin_[pos];
}

// Element access
template <class T>
typename s21::vector<T>::const_reference s21::vector<T>::front() {
  return begin_[0];
}

template <class T>
typename s21::vector<T>::const_reference s21::vector<T>::back() {
  return *(end() - 1);
}

template <class T>
typename s21::vector<T>::reference s21::vector<T>::at(size_type pos) {
  if (pos >= size()) {
    throw std::out_of_range("out_of_range");
  }
  return begin_[pos];
}

template <class T>
T *s21::vector<T>::data() {
  return begin_;
}

// Iterators
template <class T>
typename s21::vector<T>::iterator s21::vector<T>::begin() const {
  return begin_;
}

template <class T>
typename s21::vector<T>::iterator s21::vector<T>::end() const {
  return begin_ + size_;
}

// Capacity
template <class T>
bool s21::vector<T>::empty() {
  return !size();
}

template <class T>
typename s21::vector<T>::size_type s21::vector<T>::size() {
  return size_;
}

template <class T>
typename s21::vector<T>::size_type s21::vector<T>::max_size() {
  std::allocator<T> alloc;
  return alloc.max_size();
}

template <class T>
void s21::vector<T>::reserve(size_type size) {
  if (capacity_ < size) {
    capacity_ = size;
    T *sized_array = new T[capacity_];
    std::memcpy(sized_array, begin_, size_ * sizeof(T));

    delete[] begin_;
    begin_ = new T[capacity_];

    std::memcpy(begin_, sized_array, size_ * sizeof(T));
    delete[] sized_array;
  }
}

template <class T>
typename s21::vector<T>::size_type s21::vector<T>::capacity() {
  return capacity_;
}

template <class T>
void s21::vector<T>::shrink_to_fit() {
  if (size_ != capacity_) {
    T *shrinked_array = new T[size_];
    capacity_ = size_;
    std::memcpy(shrinked_array, begin_, size_ * sizeof(T));
    delete[] begin_;

    begin_ = shrinked_array;
  }
}

// Modifiers
template <class T>
void s21::vector<T>::clear() {
  delete[] begin_;
  begin_ = nullptr;
  size_ = 0;
  capacity_ = 0;
}

template <class T>
typename s21::vector<T>::iterator s21::vector<T>::insert(
    iterator pos, const_reference value) {
  if (pos == end()) {
    push_back(value);
  } else if (pos == begin_) {
    T *temp_array = new T[capacity_ + 1]();
    temp_array[0] = value;
    std::memcpy(temp_array + 1, begin_, size_ * sizeof(T));
    ++size_;
    reallocator();
    std::memcpy(begin_, temp_array, size_ * sizeof(T));
    delete []temp_array;
  } else {
    T *temp_array = new T[capacity_ + 1]();
    long int insertion_position = pos - begin_;
    size_t size_start_to_insertion = insertion_position * sizeof(T);
    size_t size_insertion_to_end = (end() - pos + 1) * sizeof(T);
    std::memcpy(temp_array, begin_, size_start_to_insertion);
    temp_array[insertion_position] = value;
    std::memcpy(temp_array + insertion_position + 1,
                begin_ + insertion_position, size_insertion_to_end);
    ++size_;
    reallocator();
    std::memcpy(begin_, temp_array, size_ * sizeof(T));
    pos = begin_ + insertion_position;
    delete []temp_array;
  }
  return pos;
}

template <class T>
void s21::vector<T>::erase(iterator pos) {
  size_ -= 1;
  T *new_array = new T[capacity_];
  long deleting_position = pos - begin_;
  size_t size_start_to_deleting = sizeof(T) * deleting_position;
  size_t size_deleting_to_end = sizeof(T) * (begin_ + size_ - pos);

  std::memcpy(new_array, begin_, size_start_to_deleting);
  std::memcpy(new_array + deleting_position, begin_ + deleting_position + 1,
              size_deleting_to_end);
  std::memcpy(begin_, new_array, size_ * sizeof(T));
  delete[] new_array;
}

template <class T>
void s21::vector<T>::push_back(const_reference value) {
  reallocator();
  begin_[size_] = value;
  size_ += 1;
}

template <class T>
void s21::vector<T>::pop_back() {
  erase(end() - 1);
}

template <class T>
void s21::vector<T>::swap(vector &other) {
  std::swap(size_, other.size_);
  std::swap(capacity_, other.capacity_);
  std::swap(begin_, other.begin_);
}

// Additional
template <class T>
void s21::vector<T>::filling() {
  for (size_type i = 0; i < size_; i++) {
    begin_[i] = i + 10;
  }
}

template <class T>
void s21::vector<T>::reallocator() {
  if (!size_ && !capacity_) {
    capacity_ = 1;
  } else if (size_ == capacity_) {
    capacity_ = (size_t)(capacity_ * 2);
  }
  T *extended_array = new T[capacity_];
  std::memcpy(extended_array, begin_, size_ * sizeof(T));
  delete[] begin_;
  begin_ = new T[capacity_];
  std::memcpy(begin_, extended_array, size_ * sizeof(T));
  delete[] extended_array;
}

#endif  // CONTAINERS_CPP_S21_VECTOR_S21_VECTOR_H_
