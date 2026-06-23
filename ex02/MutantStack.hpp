#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <deque>
#include <stack>

template <typename T> class MutantStack : public std::stack<T> {
public:
  typedef typename std::deque<T>::iterator iterator;

  iterator begin() { return this->c.begin(); }
  iterator end() { return this->c.end(); }

  MutantStack() {}
  MutantStack(const MutantStack<T> &other) : std::stack<T>(other) {}
  MutantStack &operator=(const MutantStack<T> &other) {
    if (this == &other)
      return *this;
    std::stack<T>::operator=(other);
    return *this;
  }

  ~MutantStack() {}

private:
};

#endif