#include <iostream>
#include <list>

int main() {
  std::list<int> a({});
  std::list<int> b({1, 2, 3, 5});
  // a.merge(b);
  std::list<int>::iterator itr = a.end();
  // ++itr;
  a.splice(itr, b);
  // std::cout << *itr << std::endl;
  for (auto itr = a.begin(); itr != a.end(); ++itr) {
    std::cout << *itr << std::endl;
  }
  return 0;
}