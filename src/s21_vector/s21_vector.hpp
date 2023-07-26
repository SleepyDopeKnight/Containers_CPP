#ifndef CONTAINERS_CPP_S21_VECTOR_S21_VECTOR_H_
#define CONTAINERS_CPP_S21_VECTOR_S21_VECTOR_H_

namespace s21 {
template <class T>
class vector {
  // Members type
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  class VectorIterator;
  using iterator = VectorIterator;
  using const_iterator = VectorIterator;

  // Constructors
  vector();
  vector(size_type n);
  vector(std::initializer_list<value_type> const &items);
  vector(const vector &v);
  vector(vector &&v);
  ~vector();

  // Overload operators
  vector operator=(vector &&v);
  reference operator[](size_type pos);

  // Element access
  reference at(size_type pos) const;
  const_reference front() const;
  const_reference back() const;
  T *data() const;

  // Iterators
  iterator begin() const;
  iterator end() const;

  // Capacity
  bool empty() const;
  size_type size() const;
  size_type max_size() const;
  void reserve(size_type size);
  size_type capacity() const;
  void shrink_to_fit();

  // Modifiers
  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void swap(vector &other)
};

// Nested class
template <class T>
class vector<T>::VectorIterator {
  friend class vector<T>;

 public:
  void operator=(node_ &other);
  T &operator*();
  void operator++();
  void operator++(int);
  void operator--();
  void operator--(int);
  bool operator==(s21::vector<T>::VectorIterator iterator);
  bool operator!=(s21::vector<T>::VectorIterator iterator);
};
}  // namespace s21

// Constructors
// template <class T>
// s21::vector<T>::vector() {}

// template <class T>
// s21::vector<T>::vector(size_type n) {}

// template <class T>
// s21::vector<T>::vector(std::initializer_list<value_type> const &items) {}

// template <class T>
// s21::vector<T>::vector(const vector &v) {}

// template <class T>
// s21::vector<T>::vector(vector &&v) {}

// template <class T>
// s21::vector<T>::~vector() {}

// Overload operators
// template <class T>
// s21::vector<T> s21::vector<T>::operator=(vector &&v) {}

// template <class T>
// typename s21::vector<T>::reference s21::vector<T>::operator[](size_type pos) {}

// Element access
// template <class T>
// typename s21::vector<T>::const_reference s21::vector<T>::front() const {}

// template <class T>
// typename s21::vector<T>::const_reference s21::vector<T>::back() const {}

// template <class T>
// typename s21::vector<T>::reference s21::vector<T>::at(size_type pos) const {}

// template <class T>
// T *s21::vector<T>::data() const {}

// Iterators
// template <class T>
// typename s21::vector<T>::iterator s21::vector<T>::begin() const {}

// template <class T>
// typename s21::vector<T>::iterator s21::vector<T>::end() const {}

// Capacity
// template <class T>
// bool s21::vector<T>::empty() const {
//   // return !size();
// }

// template <class T>
// typename s21::vector<T>::size_type s21::vector<T>::size() const {
//   // return size_;
// }

// template <class T>
// typename s21::vector<T>::size_type s21::vector<T>::max_size() const {}

// template <class T>
// void s21::vector<T>::reserve(size_type size) {}

// template <class T>
// typename s21::vector<T>::size_type s21::vector<T>::capacity() const {}

// template <class T>
// void s21::vector<T>::shrink_to_fit() {}

// Modifiers
// template <class T>
// void s21::vector<T>::clear() {}

// template <class T>
// typename s21::vector<T>::iterator s21::vector<T>::insert(
//     iterator pos, const_reference value) {}

// template <class T>
// void s21::vector<T>::erase(iterator pos) {}

// template <class T>
// void s21::vector<T>::push_back(const_reference value) {}

// template <class T>
// void s21::vector<T>::pop_back() {}

// template <class T>
// void s21::vector<T>::swap(vector &other) {}

// VectorItertor methods
// template <class T>
// void s21::vector<T>::VectorIterator::operator=(node_ &other) {}

// template <class T>
// typename s21::vector<T>::value_type &s21::vector<T>::VectorIterator::operator*() {}

// template <class T>
// void s21::vector<T>::VectorIterator::operator++() {}

// template <class T>
// void s21::vector<T>::VectorIterator::operator++(int) {}

// template <class T>
// void s21::vector<T>::VectorIterator::operator--() {}

// template <class T>
// void s21::vector<T>::VectorIterator::operator--(int) {}

// template <class T>
// bool s21::vector<T>::VectorIterator::operator==(
//     const s21::vector<T>::VectorIterator iterator) {}

// template <class T>
// bool s21::vector<T>::VectorIterator::operator!=(
//     const s21::vector<T>::VectorIterator iterator) {}

#endif  // CONTAINERS_CPP_S21_VECTOR_S21_VECTOR_H_
