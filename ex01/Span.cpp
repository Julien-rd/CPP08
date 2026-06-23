#include "Span.hpp"
#include <exception>
#include <limits>
#include <stdlib.h>

Span::Span(unsigned int size) : _size(size) {}

Span::Span() : _size(0) {}

Span::Span(const Span &other)
    : _size(other._size), _container(other._container) {}

Span::~Span() {}

Span &Span::operator=(const Span &other) {
  if (this == &other)
    return *this;
  _size = other._size;
  _container.clear();
  _container = other._container;
  return *this;
}

void Span::addNumber(int num) {
  if (_container.size() == _size)
    throw std::exception();
  _container.insert(num);
}

size_t Span::shortestSpan() {
  size_t ret = std::numeric_limits<size_t>::max();
  if (_container.size() < 2)
    return 0;
  for (std::multiset<int>::iterator it = _container.begin();
       it != _container.end(); ++it) {
    std::multiset<int>::iterator tmp = it;
    ++tmp;
    if (tmp == _container.end())
      break;
    size_t diff = *tmp - *it;
    if (diff < ret)
      ret = diff;
  }
  return ret;
}

size_t Span::longestSpan() {
  if (_container.size() < 2)
    return 0;
  return static_cast<size_t>(*(--_container.end())) -
         static_cast<size_t>(*(_container.begin()));
}
