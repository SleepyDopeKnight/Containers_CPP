#include <iostream>
#include <list>

int main() {
  std::list<int> a({1, 2, 3, 4, 5, 3});
  auto itr = a.end();
  *itr;
  std::cout << *itr << " ";
  // for (auto itr = a.begin(); itr != a.end(); ++itr) {
    // std::cout << *itr << " ";
  // }
	return 0;
}