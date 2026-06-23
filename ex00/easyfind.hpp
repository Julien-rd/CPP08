#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>

template <typename T> typename T::iterator easyfind(T x, int y) {
  for (typename T::iterator it = x.begin(); it != x.end(); ++it) {
    if (*it == y)
      return it;
  }
  throw std::exception();
}

#endif