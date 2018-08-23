// ring.h

#ifndef _RING_H_
#define _RING_H_

#include <iostream>

template <class T>
class CRing
{
public:
  class Iterator;

};

template <class T>
class CRing<T>::Iterator
{
public:
  void print()
  {
    std::cout << "Hello from iterator" << T() << std::endl;
  }
}; 
#endif // _RING_H_