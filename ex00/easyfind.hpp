#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

template <typename T> typename T::iterator easyfind(T &x, int y) {
  typename T::iterator it = std::find(x.begin(), x.end(), y);
  if (it == x.end())
    throw std::exception();
  return it;
}

template <typename T> typename T::const_iterator easyfind(const T &x, int y) {
  typename T::const_iterator it = std::find(x.begin(), x.end(), y);
  if (it == x.end())
    throw std::exception();
  return it;
}

#endif
