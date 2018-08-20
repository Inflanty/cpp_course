/* 
 * @ Name : Overloading_Plus
 * @ Author : Jan Glos (re CaveofProgramming)  
 * @ Compilation : Please type the command "gcc A_Complex_Number_Class.cpp -o Complex -lstdc++ Complex.cpp" 
*/

#include <iostream>
#include <string>
#include "Complex.h"

int main()
{
  caveofprogramming::CComplex c1(3,4);
  caveofprogramming::CComplex c2(1,1);

  std::cout << c1 << std::endl;
  std::cout << c2 << std::endl;
  std::cout << c1 + c2 << std::endl;
  std::cout << c1 + 7 << std::endl;
  std::cout << c1 + c2 + 4 * 567 + 7 << std::endl;

  return 0;
}
