#include <iostream>
#include <list>

int main() {
  std::list<int> a({7, 2, 1, 8});
  std::list<int> b({});
  a.swap(b);
  // auto itr = a.end();
  // ++itr;
  // std::cout << *itr << std::endl;
  for (auto itr = a.begin(); itr != a.end(); ++itr) {
    std::cout << *itr << std::endl;
  }
	return 0;
}