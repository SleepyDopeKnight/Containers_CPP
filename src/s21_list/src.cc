#include <iostream>
#include <list>

int main() {
  std::list<int> a({9, 2, 4, 4, 4, 3, 2, 2, 4});
  // std::list<int> b({1, 2, 3, 5});
  // a.merge(b);
  // std::list<int>::iterator itr = a.end();
  // ++itr;
  a.unique();
  // std::cout << *itr << std::endl;
  for (auto itr = a.begin(); itr != a.end(); ++itr) {
    std::cout << *itr << std::endl;
  }
  return 0;
}