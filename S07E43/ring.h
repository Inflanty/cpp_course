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
  
  // Should return the address of first element
  Iterator begin()
  {
    return Iterator(0, *this);
  }

  // Should return the address of last element
  Iterator end()
  {
    return Iterator(m_size, *this);
  }
};

template <class T>
class CRing<T>::Iterator
{
private:
  int m_pos;
  CRing m_ring;
public:
  Iterator(int pos, CRing &aRing): m_ring(aRing), m_pos(pos)
  {
  
  }

  Iterator &operator++(int)
  {
    m_pos ++;
    return *this; 
  } 

  Iterator &operator++()
  {
    m_pos ++;
    return *this; 
  }

  T &operator*()
  {
    return m_ring.get(m_pos);
  } 

  bool operator!=(const Iterator &other) const
  {
    return m_pos != other.m_pos;
  }
}; 
#endif // _RING_H_