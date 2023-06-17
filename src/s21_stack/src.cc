#include <iostream>
#include <stack>

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
  std::stack<int> a({1, 2, 3});
   while (!a.empty())
    {
        int temp = a.top();
        a.pop();
        std::cout << temp << std::endl;
    }
  return 0;
}