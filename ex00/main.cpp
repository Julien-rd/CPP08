#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main() {
  std::vector<int> vec;
  vec.push_back(10);
  vec.push_back(11);
  vec.push_back(12);
  vec.push_back(13);

  std::cout << "----- vector, element found -----\n";
  try {
    std::vector<int>::iterator it = easyfind(vec, 12);
    std::cout << "found: " << *it << "\n";
    *it = 99;
    std::cout << "modified: " << vec[2] << "\n\n";
  } catch (std::exception &e) {
    std::cout << "object not found! (unexpected)\n\n";
  }

  std::cout << "----- vector, element NOT found -----\n";
  try {
    easyfind(vec, 42);
    std::cout << "error\n\n";
  } catch (std::exception &e) {
    std::cout << "object not found\n\n";
  }

  std::cout << "----- const vector, element found -----\n";
  const std::vector<int> cvec(vec);
  try {
    std::vector<int>::const_iterator it = easyfind(cvec, 11);
    std::cout << "found in const vector: " << *it << "\n\n";
  } catch (std::exception &e) {
    std::cout << "error\n\n";
  }

  std::cout << "----- empty vector -----\n";
  const std::vector<int> empty_container;
  try {
    easyfind(empty_container, 10);
    std::cout << "error\n\n";
  } catch (std::exception &e) {
    std::cout << "empty container!\n\n";
  }

  std::cout << "----- list, non-const and const -----\n";
  std::list<int> lst;
  lst.push_back(5);
  lst.push_back(6);
  lst.push_back(7);
  try {
    std::list<int>::iterator it = easyfind(lst, 6);
    std::cout << "Found in list: " << *it << "\n";
  } catch (std::exception &e) {
    std::cout << "Error\n";
  }
  const std::list<int> clst(lst);
  try {
    std::list<int>::const_iterator it = easyfind(clst, 7);
    std::cout << "Found in const list: " << *it << "\n\n";
  } catch (std::exception &e) {
    std::cout << "Error\n\n";
  }

  std::cout << "----- first/last element -----\n";
  try {
    std::vector<int>::iterator it = easyfind(vec, 10);
    std::cout << "found first element: " << *it << "\n";
  } catch (std::exception &e) {
    std::cout << "error\n";
  }
  try {
    std::vector<int>::iterator it = easyfind(vec, 13);
    std::cout << "found last element: " << *it << "\n\n";
  } catch (std::exception &e) {
    std::cout << "Error\n\n";
  }

  return 0;
}