#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main() {
  const std::vector<int> container;
  const int search = 10;

  // container.push_back(10);
  // container.push_back(11);
  // container.push_back(12);
  // container.push_back(13);

  try {
    easyfind(container, search);
  } catch (std::exception &e) {
    std::cout << "object not found!\n";
  }
}