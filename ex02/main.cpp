#include "MutantStack.hpp"
#include <iostream>
#include <stack>

template <typename Stack> void printStack(Stack s) {
  while (!s.empty()) {
    std::cout << s.top() << " ";
    s.pop();
  }
  std::cout << std::endl;
}

int main() {
  std::cout << "----- iteration -----\n";
  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  mstack.push(0);

  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  while (it != ite) {
    std::cout << *it << " ";
    ++it;
  }
  std::cout << "\n\n";

  std::cout << "----- inherited stack functions -----\n";
  std::cout << "top: " << mstack.top() << "\nsize before pop: " << mstack.size()
            << "\n";
  mstack.pop();
  std::cout << "size after pop: " << mstack.size()
            << ", top after pop: " << mstack.top() << "\n";
  std::cout << "empty: " << mstack.empty() << "\n\n";

  std::cout << "----- copy constructor -----\n";
  MutantStack<int> copy_constructed(mstack);
  mstack.push(999);
  std::cout << "original top after push: " << mstack.top() << "\n";
  std::cout << "copy top: " << copy_constructed.top() << "\n\n";

  std::cout << "----- operator= -----\n";
  MutantStack<int> assigned;
  assigned.push(1);
  assigned.push(2);
  assigned = mstack;
  std::cout << "assigned top after assignment: " << assigned.top() << "\n";
  assigned.push(123);
  std::cout << "assigned top after own push: " << assigned.top()
            << "\nmstack top: " << mstack.top() << "\n";

  return 0;
}