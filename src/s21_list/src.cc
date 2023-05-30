#include <iostream>
#include <list>

int main() {
  std::list<int> a({6});
  // std::list<int> a({});
  // a.merge(b);
  auto itr = a.end();
  a.insert(itr, 10);
  // ++itr;
  // std::cout << *itr << std::endl;
  for (auto itr = a.begin(); itr != a.end(); ++itr) {
    std::cout << *itr << std::endl;
  }
  return 0;
}