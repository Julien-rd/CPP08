#include "Span.hpp"
#include <iostream>
#include <vector>

int main() {
  try{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(3);
    // sp.addNumber(-2147483648);
    // sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    // std::cout << 2147483647 + 2147483648 << std::endl;
  }
  catch (std::exception &e) {
    std::cout << "container full\n";
  }
  return 0;
}