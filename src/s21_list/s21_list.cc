#include "../s21_containers.h"
// #include <list>

// int main() {
//     return 0;
// }

// Constructors
template <class T>
s21::list<T>::list() {
  *head_ = new node_;
  *tail_ = new node_;
  *end_node_ = new node_;

  tail_->next_ = end_node_;
  end_node_->next_ = head_;
  end_node_->previous_ = tail_;
  head_->previous_ = end_node_;
}

template <class T>
s21::list<T>::list(size_type n) {
  for (int i = 0; i < n; ++i) {
    // push_back
  }
}

template <class T>
s21::list<T>::list(std::initializer_list<value_type> const &items) {
  if (items.size()) {
    for (auto itr = items.begin(); itr != items.end_node_; ++itr) {
      //  push_back(*itr);
    }
  }
}

template <class T>
s21::list<T>::list(const list &l) {
  for (auto itr = l.begin(); itr != l.end_node_; ++itr) {
    //  push_back(*itr);
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
  Clear();
  MoveList(l);
  return *this;
}

// Element access
// template <class T>
// const_reference s21::list<T>::front() {}

// template <class T>
// const_reference s21::list<T>::back() {}

// Iterators
// template <class T>
// s21::list<T>::iterator begin() {}

// template <class T>
// s21::list<T>::iterator end() {}

// template <class T>
// s21::list<T>::iterator insert(iterator pos, const_reference value) {}

// Capacity
template <class T>
bool s21::list<T>::empty() {
  return !size();
}

template <class T>
s21::list<T>::size_type s21::list<T>::size() {
  return size_;
}

// template <class T>
// s21::list<T>::size_type s21::list<T>::max_size() {}

// Modifiers
template <class T>
void s21::list<T>::clear() {
  for (auto itr = head_.begin(); itr != end_node_; ++itr) {
    delete *itr;
  }
}
// template <class T>
// void s21::list<T>::erase(iterator pos) {}

// template <class T>
// void s21::list<T>::push_back(const_reference value) {}

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