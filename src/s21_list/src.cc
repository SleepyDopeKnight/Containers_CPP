#include <iostream>
#include <list>

int main() {
  const std::list<int> a({6, 2, 1});
  // std::list<int> b({5, 4, 8});
  // a.merge(b);
  std::list<int>::const_iterator itr = a.begin();
  // itr *= 2;
  // ++itr;
  // a.splice(itr, b);
  std::cout << *itr << std::endl;
  // for (auto itr = a.begin(); itr != a.end(); ++itr) {
    // std::cout << *itr << std::endl;
  // }
  return 0;
}