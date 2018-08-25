// ring.h

#ifndef _RING_H_
#define _RING_H_

#include <iostream>

template <class T>
class CRing
{
private:
  T *m_values;
  int m_size;
  int m_pos;
public:
  class Iterator;
public:
  CRing(int size):m_pos(0),  m_size(size), m_values(NULL)
  {
    m_values = new T[size];
  }

  ~CRing()
  {
    delete [] m_values;
  }

  int size()
  {
    return m_size;
  }

  void add(T value)
  {
    m_values[m_pos++] = value;

    if(m_pos == m_size)
    {
      m_pos = 0;
    }
  }

  T &get(int pos)
  {
    return m_values[pos];
  }

  Iterator begin()
  {
    return Iterator();
  }

  Iterator end()
  {
    return Iterator();
  }
};

template <class T>
class CRing<T>::Iterator
{
public:
  
}; 
#endif // _RING_H_