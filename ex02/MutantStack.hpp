#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <aio.h>
#include <deque>
#include <iterator>
#include <set>
#include <stack>

template <typename T> class MutantStack : public std::stack<T> {
public:
  typedef typename std::deque<T>::iterator iterator;

  iterator begin() { return this->c.begin(); }
  iterator end() { return this->c.end(); }

  // MutantStack operator+(const MutantStack &n) {
  //   return Number(value + n.value); }

  MutantStack() {}
  MutantStack(const MutantStack<T> &other) : std::stack<T>(other) {}
  MutantStack &operator=(const MutantStack<T> &other) {
    if (this == &other)
      return *this;
    this = other;
    return *this;
  }

  ~MutantStack() {}

private:
};

#endif