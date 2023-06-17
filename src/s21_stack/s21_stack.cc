#include "../s21_containers.h"

int main() {
  // std::cout << "jojo" << std::endl;
  s21::stack<int> a({2});
  //  while (!a.empty())
  //   {
  //       int temp = a.top();
  //       a.pop();
  //       std::cout << temp << std::endl;
  //   }
}

// Constructors
template <class T>
s21::stack<T>::stack() {}

template <class T>
s21::stack<T>::stack(size_type n) {
  for (size_type i = 0; i < n; ++i) {
    push(T());
  }
}

template <class T>
s21::stack<T>::stack(std::initializer_list<value_type> const &items) {
  for (auto itr = items.begin(); itr != items.end(); ++itr) {
    push(*itr);
  }
}

template <class T>
s21::stack<T>::stack(const stack &s) {
  for (auto itr = s.begin(); itr != s.end(); ++itr) {
    push_back(*itr);
  }
}

template <class T>
s21::stack<T>::stack(stack &&s) {
  MoveStack(s);
}

template <class T>
s21::stack<T>::~stack() {
  clear();
}

// Overload operators
template <class T>
s21::stack<T> s21::stack<T>::operator=(stack &&s) {
  clear();
  MoveStack(s);
}

// Capacity
template <class T>
bool s21::stack<T>::empty() const {
  return !size();
}

template <class T>
typename s21::stack<T>::size_type s21::stack<T>::size() const {
  return size_;
}

// Element access
template <class T>
typename s21::stack<T>::const_reference s21::stack<T>::top() const {
  if (size_ > 0) {
    return head_->value_;
  } else {
    return NULL;
  }
}

// Modifiers
template <class T>
void s21::stack<T>::push(const_reference value) {
  auto *new_node = new node_;
  new_node->value_ = value;
  new_node->next_ = head_;
  head_ = new_node;
  ++size_;
}

template <class T>
void s21::stack<T>::pop() {
  if (head_) {
    --size_;
  }
}

template <class T>
void s21::stack<T>::swap(stack &other) {
  std::swap(head_, other.head_);
  std::swap(size_, other.size_);
}

// Additional
template <class T>
void s21::stack<T>::MoveStack(stack &s) {
  head_ = s.head_;
  size_ = s.size_;
  s.head_ = nullptr;
  s.size_ = 0;
}

template <class T>
void s21::stack<T>::clear() {
  while (head_) {
    auto deleted_node = head_;
    head_ = head_->next_;
    delete deleted_node;
  }
  size_ = 0;
}
