// Complex.cpp
#include "Complex.h"

namespace caveofprogramming
{
  CComplex::CComplex():
    real(0),
    imaginary(0)
    {
    
    }

  CComplex::CComplex(double real, double imaginary):
    real(real),
    imaginary(imaginary)
    {
    
    }

  CComplex::CComplex(const CComplex &other):
    real(other.real),
    imaginary(other.imaginary)
    {
      std::cout << "Copying..." << std::endl;
    }

  const CComplex &CComplex::operator=(const CComplex &other)
  {
    std::cout << "Copying with operator..." << std::endl;
    real = other.real;
    imaginary = other.imaginary;
  }

  std::ostream &operator<<(std::ostream &out, const CComplex &c)
  {
    out << "(" << c.getReal() << "," << c.getImaginary() << ")";
    return out;
  }

  double CComplex::getReal() const
  {
  return real;
  }
  
  double CComplex::getImaginary() const
  {
  return imaginary;
  }

  bool CComplex::operator==(const CComplex &other) const
  {
    return real == other.real && imaginary == other.imaginary;
  }

  bool CComplex::operator!=(const CComplex &other) const
  {
    return !(*this == other);
  }

} //namespace caveofporgramming
