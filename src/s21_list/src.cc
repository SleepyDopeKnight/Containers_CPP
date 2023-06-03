#include <iostream>
#include <list>

int main() {
  // std::list<int> a({});
  // auto itr2 = a.end();
  // a.erase(itr2);
  // auto itr = a.front();
  // std::list<int> a({9, 2, 4, 4, 4, 3, 2, 2, 4});
  // std::list<int> b({1, 2, 3, 5});
  // a.merge(b);
  // std::list<int>::iterator itr = a.end();
  // ++itr;
  // a.unique();
  // std::list<int>::iterator itr = a.begin();
  // a.pop_front();
  // ++itr;
    std::list<int> list;
  auto s21_size = list.max_size();
  std::cout << s21_size << std::endl;
  // std::cout << itr << std::endl;
  // for (auto itr = std_a.begin(); itr != std_a.end(); ++itr) {
  //   std::cout << *itr << std::endl;
  // }
  return 0;
}