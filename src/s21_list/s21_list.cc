#include "../s21_containers.h"

int main() {
  // const s21::list<int> a({7, 2, 1, 8, 11, -2});
  s21::list<int> a({4, 4, 4, 3, 2, 4, 9});
  // s21::list<int> b({1, 2, 3, 5});
  // auto itr = a.begin();
  // a.insert(itr, 10);
  // a.push_back(10);
  a.unique();
  auto itr2 = a.end();
  // s21::list<int>::const_iterator itr2 = a.begin();
  // --itr2;
  ++itr2;
  // a.insert(itr3, 10);
  // itr--;
  // auto itr = a.end();
  // ++itr;
  // --itr;
  std::cout << *itr2 << std::endl;
  for (auto itr = a.begin(); itr != a.end(); ++itr) {
    std::cout << *itr << std::endl;
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
  end_node_ = new node_;
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
typename s21::list<T>::const_reference s21::list<T>::front() const {
  return head_->value_;
}

template <class T>
typename s21::list<T>::const_reference s21::list<T>::back() const {
  return tail_->value_;
}

// Iterators
template <class T>
typename s21::list<T>::iterator s21::list<T>::begin() const {
  s21::list<T>::iterator iterator;
  if (head_) {
    iterator = *head_;
  }
  return iterator;
}

template <class T>
typename s21::list<T>::iterator s21::list<T>::end() const {
  s21::list<T>::iterator iterator;
  if (end_node_) {
    iterator = *end_node_;
  }
  return iterator;
}

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
  size_ = 0;
  end_node_ = nullptr;
}

template <class T>
typename s21::list<T>::iterator s21::list<T>::insert(iterator pos,
                                                     const_reference value) {
  node_ *current_node = pos.itr_node_;
  node_ *new_value = new node_{value};
  if (size_ == 0) {
    push_back(value);
  } else {
    if (current_node == head_) {
      new_value->next_ = head_;
      new_value->previous_ = end_node_;
      head_->previous_ = new_value;
      new_value->next_ = current_node;
      end_node_->next_ = new_value;
      head_ = new_value;
    } else {
      current_node->previous_->next_ = new_value;
      new_value->previous_ = current_node->previous_;
      new_value->next_ = current_node;
      current_node->previous_ = new_value;
    }
  }
  pos.itr_node_ = new_value;

  ++size_;
  return pos;
}

template <class T>
void s21::list<T>::erase(iterator pos) {
  node_ *current_node = pos.itr_node_;
  if (size_ != 0 && current_node != end_node_) {
    node_ *next_node = current_node->next_;
    node_ *previous_node = current_node->previous_;
    if (next_node) {
      next_node->previous_ = previous_node;
    } else {
      tail_ = previous_node;
    }
    if (previous_node) {
      previous_node->next_ = next_node;
    } else {
      head_ = next_node;
    }
    if (current_node == head_) {
      head_ = next_node;
    }
    if (current_node == tail_) {
      tail_ = previous_node;
    }
    delete current_node;
    --size_;
  }
}

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
    end_node_->next_ = head_;
    head_->previous_ = end_node_;
  }
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
    end_node_->previous_ = tail_;
    tail_->next_ = end_node_;
  }
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

template <class T>
void s21::list<T>::merge(list &other) {
  if (other.size_ > 0 && &other != this) {
    if (size_ == 0) {
      MoveList(other);
    } else {
      for (iterator itr = other.begin(); itr != other.end(); ++itr) {
        push_back(*itr);
      }
      other.clear();
    }
  }
}

template <class T>
void s21::list<T>::splice(const_iterator pos, list &other) {
  if (other.size_ > 0 && &other != this) {
    if (size_ == 0) {
      pos = end();
    }
    for (auto itr = other.begin(); itr != other.end(); ++itr) {
      insert(pos, *itr);
    }
  }
  other.clear();
}

template <class T>
void s21::list<T>::unique() {
  if (size_ > 1) {
    s21::list<T>::iterator current_node = begin();
    while (current_node != end()) {
      s21::list<T>::iterator next_node = current_node;
        current_node = next_node;
        ++next_node;
      if (*next_node == *current_node && next_node != end()) {
        erase(next_node);
      } else {
        ++current_node;
      }
    }
  }
}

template <class T>
void s21::list<T>::reverse() {
  if (size_ > 1) {
    node_ *current_node = head_;
    while (current_node != end_node_) {
      node_ *next_node = current_node->next_;
      std::swap(current_node->next_, current_node->previous_);
      current_node = next_node;
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
void s21::list<T>::ListIterator::operator=(node_ &other) {
  itr_node_ = &other;
  value_ = other.value_;
}

template <class T>
typename s21::list<T>::value_type &s21::list<T>::ListIterator::operator*() {
  T *value = &value_;
  return *value;
}

template <class T>
typename s21::list<T>::value_type &s21::list<T>::ListIterator::operator*()
    const {
  T *value = const_cast<T *>(&value_);
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
void s21::list<T>::ListIterator::operator++(T) {
  s21::list<T>::iterator iterator = *this;
  ++iterator;
}

template <class T>
void s21::list<T>::ListIterator::operator--() {
  if (itr_node_ && itr_node_->previous_) {
    itr_node_ = itr_node_->previous_;
    value_ = itr_node_->value_;
  }
}

template <class T>
void s21::list<T>::ListIterator::operator--(T) {
  s21::list<T>::iterator iterator = *this;
  --iterator;
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

// Additional
template <class T>
void s21::list<T>::MoveList(list &l) {
  head_ = l.head_;
  tail_ = l.tail_;
  end_node_ = l.end_node_;
  size_ = l.size_;
  l.head_ = nullptr;
  l.tail_ = nullptr;
  l.end_node_ = nullptr;
  l.size_ = 0;
}