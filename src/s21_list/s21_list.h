#include <iostream>

template <class T>
class list {
 public:
  // Members type
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = ListIterator<T>;
  using const_iterator = ListConstIterator<T>;
  using size_type = size_t;

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
	void swap(list& other);
	void merge(list& other);
	void splice(const_iterator pos, list& other);
	void splice();
	void unique();
	void sort();

};