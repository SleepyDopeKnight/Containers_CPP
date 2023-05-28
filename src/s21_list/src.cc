#include <iostream>
#include <list>

int main() {
  std::list<int> a(0);
  auto itr = a.end();
  ++itr;
  std::cout << *itr << std::endl;
  for (auto itr = a.begin(); itr != a.end(); ++itr) {
    std::cout << *itr << std::endl;
  }
	return 0;
}