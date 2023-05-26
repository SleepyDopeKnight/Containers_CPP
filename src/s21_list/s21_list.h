#include <iostream>
#include <limits>

namespace s21 {
template <class T>
class list {
 public:
  // Members type
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

 private:
  struct node_ {
    value_type value_;
    node_ *next_ = nullptr;
    node_ *previous_ = nullptr;
  };
  node_ *head_ = nullptr;
  node_ *tail_ = nullptr;
  node_ *end_node_ = nullptr;
  size_type size_ = 0;

 public:
  // Nested class
  class ListIterator {
    friend class list;

   public:
    ListIterator();
    ~ListIterator();

    void operator=(node_ &other);
    T &operator*();
    void operator++();
    void operator++(int);
    void operator--();
    void operator--(int);
    bool operator==(const s21::list<T>::ListIterator iterator) const;
    bool operator!=(const s21::list<T>::ListIterator iterator) const;

   private:
    value_type value_ = value_type();
    node_ *itr_node_ = nullptr;
  };

  // Members type
  using iterator = ListIterator;
  using const_iterator = const T *;

  // Constructors
  list();
  list(size_type n);
  list(std::initializer_list<value_type> const &items);
  list(const list &l);
  list(list &&l);
  ~list();

  // Overload operators
  list operator=(list &&l);

  // Element access
  const_reference front();
  const_reference back();

  // Iterators
  iterator begin();
  iterator end();
  iterator insert(iterator pos, const_reference value);

  // Capacity
  bool empty();
  size_type size();
  size_type max_size();

  // Modifiers
  void clear();
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void push_front(const_reference value);
  void pop_front();
  void swap(list &other);
  void merge(list &other);
  void splice(const_iterator pos, list &other);
  void splice();
  void unique();
  void sort();
  // Additional
  void MoveList(list &l);
};
}  // namespace s21