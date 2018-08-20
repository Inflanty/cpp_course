// Complex.h

#ifndef _COMPLEX_H_
#define _COMPLEX_H_
#include <iostream>

namespace caveofprogramming
{
  class CComplex
  {
  private:
    double real;
    double imaginary;
  public:
    CComplex();

    CComplex(double real, double imaginary);

    CComplex(const CComplex &other);

    const CComplex &operator=(const CComplex &other);

    double getReal() const;

    double getImaginary() const;
  };
  std::ostream &operator<<(std::ostream &out, const CComplex &c);
  CComplex operator+(const CComplex &c1, const CComplex &c2); 
  CComplex operator+(const CComplex &c1, double c); 
} //namespace caveofporgramming

#endif // _COMPLEX_H_ 