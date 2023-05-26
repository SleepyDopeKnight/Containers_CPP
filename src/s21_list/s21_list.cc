#include "../s21_containers.h"

int main() {
  // std::cout << "Hola" << std::endl;
  // s21::list<int> a({7, 2, 1});
  s21::list<int> a({1, 2, 3, 0, 5, 3});
  // s21::list<int> a(4);
  // auto itr = a.begin();
  // auto itr = a.begin();
  // // ++itr;
  // // --itr;
  // std::cout << *itr << std::endl;

  auto itr2 = a.end();
  // --itr2;
  // ++itr2;
  std::cout << *itr2 << std::endl;
  for (auto itr = a.begin(); itr != a.end(); ++itr) {
    std::cout << *itr << std::endl;
  }
  return 0;
}

// Constructors
template <class T>
s21::list<T>::list() {
  //   *head_ = new node_;
  //   *tail_ = new node_;
  //   *end_node_ = new node_;

  //   tail_->next_ = end_node_;
  //   end_node_->next_ = head_;
  //   end_node_->previous_ = tail_;
  //   head_->previous_ = end_node_;
}

template <class T>
s21::list<T>::list(size_type n) {
  for (int i = 0; i < n; ++i) {
    push_back(T());
  }
}
template <class T>
s21::list<T>::list(std::initializer_list<value_type> const &items) {
  for (auto itr = items.begin(); itr != items.end(); ++itr) {
    push_back(*itr);
  }
}

template <class T>
s21::list<T>::list(const list &l) {
  for (auto itr = l.begin(); itr != l.end(); ++itr) {
    push_back(*itr);
  }
}

template <class T>
s21::list<T>::list(list &&l) {
  MoveList(l);
}

template <class T>
s21::list<T>::~list() {
  clear();
}

// Overload operators
template <class T>
s21::list<T> s21::list<T>::operator=(list &&l) {
  clear();
  MoveList(l);
  return *this;
}

// Element access
template <class T>
typename s21::list<T>::const_reference s21::list<T>::front() {
  return head_->value_;
}

template <class T>
typename s21::list<T>::const_reference s21::list<T>::back() {
  return tail_->value_;
}

// Iterators
template <class T>
typename s21::list<T>::iterator s21::list<T>::begin() {
  s21::list<T>::iterator iterator;
  if (head_) {
    iterator = *head_;
  }
  return iterator;
}

template <class T>
typename s21::list<T>::iterator s21::list<T>::end() {
  s21::list<T>::iterator iterator;
  if (end_node_ && head_ && tail_) {
    iterator = *end_node_;
  }
  return iterator;
}

// template <class T>
// s21::list<T>::iterator s21::list<T>::insert(iterator pos, const_reference
// value) {}

// Capacity
template <class T>
bool s21::list<T>::empty() {
  return !size();
}

template <class T>
typename s21::list<T>::size_type s21::list<T>::size() {
  return size_;
}

template <class T>
typename s21::list<T>::size_type s21::list<T>::max_size() {
  return std::numeric_limits<size_type>::max();
}

// Modifiers
template <class T>
void s21::list<T>::clear() {
  while (head_) {
    auto tmp_node = head_;
    head_ = head_->next_;
    delete tmp_node;
  }
  // delete end_node_;
}

// template <class T>
// void s21::list<T>::erase(iterator pos) {}

template <class T>
void s21::list<T>::push_back(const_reference value) {
  auto *new_node = new node_;
  new_node->value_ = value;
  if (!head_) {
    head_ = new_node;
    tail_ = head_;
  } else {
    new_node->previous_ = tail_;
    tail_->next_ = new_node;
    tail_ = new_node;
  }
  ++size_;
}

// template <class T>
// void s21::list<T>::pop_back() {}

// template <class T>
// void s21::list<T>::push_front(const_reference value) {}

// template <class T>
// void s21::list<T>::pop_front() {}

// template <class T>
// void s21::list<T>::swap(list &other) {}

// template <class T>
// void s21::list<T>::merge(list &other) {}

// template <class T>
// void s21::list<T>::splice(const_iterator pos, list &other) {}

// template <class T>
// void s21::list<T>::splice() {}

// template <class T>
// void s21::list<T>::unique() {}

// template <class T>
// void s21::list<T>::sort() {}

// LisIterrator methods
template <class T>
s21::list<T>::ListIterator::ListIterator() = default;

template <class T>
s21::list<T>::ListIterator::~ListIterator() = default;

template <class T>
void s21::list<T>::ListIterator::operator=(node_ &node) {
  itr_node_ = &node;
  value_ = node.value_;
}

template <class T>
typename s21::list<T>::value_type &s21::list<T>::ListIterator::operator*() {
  T *value = &value_;
  return *value;
}

template <class T>
void s21::list<T>::ListIterator::operator++() {
  itr_node_ = itr_node_->next_;
  value_ = itr_node_->value_;
}

template <class T>
void s21::list<T>::ListIterator::operator++(int) {
  s21::list<T>::iterator iterator;
  iterator = *this;
  ++(*this);
}

template <class T>
void s21::list<T>::ListIterator::operator--() {
  itr_node_ = itr_node_->previous_;
  value_ = itr_node_->value_;
}

template <class T>
void s21::list<T>::ListIterator::operator--(int) {
  s21::list<T>::iterator iterator;
  iterator = *this;
  --(*this);
}

template <class T>
bool s21::list<T>::ListIterator::operator==(
    const s21::list<T>::ListIterator iterator) const {
  return itr_node_ == iterator.itr_node_;
}

template <class T>
bool s21::list<T>::ListIterator::operator!=(
    const s21::list<T>::ListIterator iterator) const {
  return itr_node_ != iterator.itr_node_;
}

// Additional
template <class T>
void s21::list<T>::MoveList(list &l) {
  head_ = l.head_;
  tail_ = l.tail_;
  end_node_ = l.end_node_;
  l.head_ = nullptr;
  l.tail_ = nullptr;
  l.end_node_ = nullptr;
}