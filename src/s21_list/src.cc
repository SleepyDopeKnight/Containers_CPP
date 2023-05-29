#include <iostream>
#include <list>

int main() {
  std::list<int> a({7, 2, 1, 8});
  // std::list<int> b({});
  // a.swap(b);
  std::list<int>::const_iterator itr = a.cbegin();
  // ++itr;
  std::cout << *itr << std::endl;
  // for (auto itr = a.begin(); itr != a.end(); ++itr) {
    // std::cout << *itr << std::endl;
  // }
	return 0;
}