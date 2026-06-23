#include "Span.hpp"
#include <climits>
#include <iostream>
#include <vector>

int main() {
  std::cout << "----- subject example -----\n";
  try {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "shortest: " << sp.shortestSpan() << ", longest: " << sp.longestSpan() << "\n\n";
  } catch (std::exception &e) {
    std::cout << "container full\n\n";
  }

  std::cout << "----- container full (addNumber) -----\n";
  try {
    Span sp = Span(2);
    sp.addNumber(1);
    sp.addNumber(2);
    sp.addNumber(3);
    std::cout << "no exception thrown\n\n";
  } catch (std::exception &e) {
    std::cout << "container full\n\n";
  }

  std::cout << "----- addRange -----\n";
  try {
    std::vector<int> values;
    values.push_back(6);
    values.push_back(3);
    values.push_back(17);
    values.push_back(9);
    values.push_back(11);
    Span sp = Span(5);
    sp.addRange(values.begin(), values.end());
    std::cout << "shortest: " << sp.shortestSpan() << ", longest: " << sp.longestSpan() << "\n\n";
  } catch (std::exception &e) {
    std::cout << "error\n\n";
  }

  std::cout << "----- addRange container full-----\n";
  try {
    std::vector<int> values;
    values.push_back(1);
    values.push_back(2);
    values.push_back(3);
    Span sp = Span(2);
    sp.addRange(values.begin(), values.end());
    std::cout << "no exception thrown\n\n";
  } catch (std::exception &e) {
    std::cout << "container full\n\n";
  }

  std::cout << "----- addRange after addNumber -----\n";
  try {
    std::vector<int> values;
    values.push_back(100);
    values.push_back(200);
    Span sp = Span(3);
    sp.addNumber(50);
    sp.addRange(values.begin(), values.end());
    std::cout << "shortest: " << sp.shortestSpan()
              << ", longest: " << sp.longestSpan() << "\n\n";
  } catch (std::exception &e) {
    std::cout << "error\n\n";
  }

  std::cout << "----- empty and single element -----\n";
  Span empty_sp = Span(5);
  std::cout << "shortest on empty: " << empty_sp.shortestSpan() << ", longest on empty: " << empty_sp.longestSpan() << "\n";
  empty_sp.addNumber(42);
  std::cout << "shortest with 1 element: " << empty_sp.shortestSpan() << ", longest with 1 element: " << empty_sp.longestSpan() << "\n\n";

  std::cout << "----- duplicates -----\n";
  Span dup_sp = Span(3);
  dup_sp.addNumber(5);
  dup_sp.addNumber(5);
  dup_sp.addNumber(8);
  std::cout << "shortest with duplicates: " << dup_sp.shortestSpan() << "\n\n";

  std::cout << "----- max diff -----\n";
  Span extreme_sp = Span(2);
  extreme_sp.addNumber(INT_MIN);
  extreme_sp.addNumber(INT_MAX);
  std::cout << "max diff: " << extreme_sp.longestSpan() << "\n\n";

  return 0;
}