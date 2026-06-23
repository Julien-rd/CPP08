#ifndef SPAN_HPP
#define SPAN_HPP

#include <aio.h>
#include <set>

class Span {
public:
  Span(unsigned int size);
  Span(const Span &other);
  Span &operator=(const Span &other);
  
  void addNumber(int num);
  size_t shortestSpan();
  size_t longestSpan();
  
private:
  Span();
  size_t _size;
  std::multiset<int> _container;
};

#endif