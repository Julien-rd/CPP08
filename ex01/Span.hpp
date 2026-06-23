#ifndef SPAN_HPP
#define SPAN_HPP

#include <cstddef>
#include <set>

class Span {
public:
  Span(unsigned int size);
  Span(const Span &other);
  Span &operator=(const Span &other);
  ~Span();

  void addNumber(int num);
  template <typename InputIterator>
  void addRange(InputIterator begin, InputIterator end) {
    for (InputIterator it = begin; it != end; ++it) {
      addNumber(*it);
    }
  }
  
  size_t shortestSpan();
  size_t longestSpan();

private:
  Span();
  size_t _size;
  std::multiset<int> _container;
};

#endif
