#include "../s21_containers.h"

int main() {
  // std::cout << "Hola" << std::endl;
  const s21::list<int> a({7, 2, 1, 8, 11, -2});
  // a.reverse();
  // s21::list<int> b({1});
  // s21::list<int> a({});
  // a = nullptr;
  // a.back();
  // const auto itr = a.begin();
  // auto itr = a.begin();
  // --itr;
  // // --itr;
  // std::cout << *itr << std::endl;
  // const auto itr2 = a.begin();
  s21::list<int>::const_iterator itr = a.begin();
  s21::list<int>::const_iterator itr2 = a.begin();
  // auto itr = a.begin();
  // a.pop_front();
  // a.pop_front();

  // itr--;
  // --itr;
  // --itr2;
  // --itr2;
  // std::cout << *itr << std::endl;
  // if (itr == itr2) {
  for (auto itr = a.begin(); itr != a.end(); ++itr) {
    std::cout << *itr << std::endl;
    // }
  }
  return 0;
}

// Constructors
template <class T>
s21::list<T>::list() {}

template <class T>
s21::list<T>::list(size_type n) {
  end_node_ = new node_;
  for (size_type i = 0; i < n; ++i) {
    push_back(T());
  }
}

template <class T>
s21::list<T>::list(std::initializer_list<value_type> const &items) {
  if (items.size() > 0) {
    end_node_ = new node_;
    for (auto itr = items.begin(); itr != items.end(); ++itr) {
      push_back(*itr);
    }
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
typename s21::list<T>::const_iterator s21::list<T>::begin() const {
  s21::list<T>::const_iterator iterator;
  if (head_) {
    iterator = *head_;
  }
  return iterator;
}


template <class T>
typename s21::list<T>::iterator s21::list<T>::end() {
  s21::list<T>::iterator iterator;
  if (end_node_) {
    iterator = *end_node_;
  }
  return iterator;
}

template <class T>
typename s21::list<T>::const_iterator s21::list<T>::end() const {
  s21::list<T>::const_iterator iterator;
  if (end_node_) {
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
  if (size_ == 0) {
    head_ = nullptr;
  } else {
    head_->previous_ = nullptr;
    end_node_->next_ = nullptr;
  }
  while (head_) {
    auto deleted_node = head_;
    head_ = head_->next_;
    delete deleted_node;
  }
}

// template <class T>
// void s21::list<T>::erase(iterator pos) {}

template <class T>
void s21::list<T>::push_back(const_reference value) {
  auto *new_node = new node_;
  new_node->value_ = value;
  new_node->next_ = end_node_;
  end_node_->previous_ = new_node;
  if (head_ == nullptr) {
    head_ = new_node;
    tail_ = head_;
  } else {
    new_node->previous_ = tail_;
    tail_->next_ = new_node;
    tail_ = new_node;
  }
  end_node_->next_ = head_;
  head_->previous_ = end_node_;
  ++size_;
}

template <class T>
void s21::list<T>::pop_back() {
  node_ *deleted_node = tail_;
  if (tail_) {
    if (head_ == tail_) {
      head_ = end_node_;
    } else {
      tail_ = tail_->previous_;
      tail_->next_ = end_node_;
      end_node_->previous_ = tail_;
    }
    delete deleted_node;
    --size_;
  }
}

template <class T>
void s21::list<T>::push_front(const_reference value) {
  auto *new_node = new node_;
  new_node->value_ = value;
  new_node->previous_ = end_node_;
  end_node_->next_ = new_node;
  if (head_ == nullptr) {
    head_ = new_node;
    tail_ = head_;
  } else {
    new_node->next_ = head_;
    head_->previous_ = new_node;
    head_ = new_node;
  }
  end_node_->previous_ = tail_;
  tail_->next_ = end_node_;
  ++size_;
}

template <class T>
void s21::list<T>::pop_front() {
  node_ *deleted_node = head_;
  if (tail_) {
    if (head_ == tail_) {
      head_ = end_node_;
    } else {
      head_ = head_->next_;
      head_->previous_ = end_node_;
      end_node_->next_ = head_;
    }
    delete deleted_node;
    --size_;
  }
}

template <class T>
void s21::list<T>::swap(list &other) {
  std::swap(head_, other.head_);
  std::swap(tail_, other.tail_);
  std::swap(end_node_, other.end_node_);
  std::swap(size_, other.size_);
}

// template <class T>
// void s21::list<T>::merge(list &other) {}

// template <class T>
// void s21::list<T>::splice(const_iterator pos, list &other) {}

// template <class T>
// void s21::list<T>::unique() {}

template <class T>
void s21::list<T>::reverse() {
  if (size_ > 1) {
    node_ *current = head_;
    while (current != end_node_) {
      node_ *next = current->next_;
      std::swap(current->next_, current->previous_);
      current = next;
    }
    std::swap(head_, tail_);
  }
}

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
  if (itr_node_ && itr_node_->next_) {
    itr_node_ = itr_node_->next_;
    value_ = itr_node_->value_;
  }
}

template <class T>
void s21::list<T>::ListIterator::operator++(const T) {
  s21::list<T>::iterator iterator;
  iterator = *this;
  ++(*this);
}

template <class T>
void s21::list<T>::ListIterator::operator--() {
  if (itr_node_ && itr_node_->previous_) {
    itr_node_ = itr_node_->previous_;
    value_ = itr_node_->value_;
  }
}

template <class T>
void s21::list<T>::ListIterator::operator--(const T) {
  s21::list<T>::iterator iterator;
  iterator = *this;
  --(*this);
}

template <class T>
bool s21::list<T>::ListIterator::operator==(
    const s21::list<T>::ListIterator iterator) {
  return itr_node_ == iterator.itr_node_;
}

template <class T>
bool s21::list<T>::ListIterator::operator!=(
    const s21::list<T>::ListIterator iterator) {
  return itr_node_ != iterator.itr_node_;
}

// ListConstIterator methods
template <class T>
s21::list<T>::ListConstIterator::ListConstIterator() = default;

template <class T>
s21::list<T>::ListConstIterator::~ListConstIterator() = default;

template <class T>
void s21::list<T>::ListConstIterator::operator=(const node_ &node) {
  itr_node_ = &node;
  value_ = node.value_;
  }

template <class T>
typename s21::list<T>::value_type &s21::list<T>::ListConstIterator::operator*()
    const {
  T *value = const_cast<T *>(&value_);
  return *value;
}

template <class T>
void s21::list<T>::ListConstIterator::operator++() {
  if (itr_node_ && itr_node_->next_) {
    itr_node_ = itr_node_->next_;
    value_ = itr_node_->value_;
  }
}

template <class T>
void s21::list<T>::ListConstIterator::operator++(T) {
  s21::list<T>::const_iterator iterator;
  iterator = *this;
  ++(*this);
}

template <class T>
void s21::list<T>::ListConstIterator::operator--() {
  if (itr_node_ && itr_node_->previous_) {
    itr_node_ = itr_node_->previous_;
    value_ = itr_node_->value_;
  }
}

template <class T>
void s21::list<T>::ListConstIterator::operator--(T) {
  s21::list<T>::const_iterator iterator;
  iterator = *this;
  --(*this);
}

template <class T>
bool s21::list<T>::ListConstIterator::operator==(
    const s21::list<T>::ListConstIterator iterator) {
  return itr_node_ == iterator.itr_node_;
}

template <class T>
bool s21::list<T>::ListConstIterator::operator!=(
    const s21::list<T>::ListConstIterator iterator) {
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