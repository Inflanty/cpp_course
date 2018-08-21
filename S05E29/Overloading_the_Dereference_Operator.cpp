/* 
 * @ Name : Overloading_the_Dereference_Operator
 * @ Author : Jan Glos (re CaveofProgramming)  
 * @ Compilation : Please type the command "gcc A_Complex_Number_Class.cpp -o Complex -lstdc++ Complex.cpp" 
*/

#include <iostream>
#include <string>
#include "Complex.h"

int main()
{
  caveofprogramming::CComplex c1(1,5);
  std::cout << c1 << std::endl;
  std::cout << *c1 << std::endl;
  std::cout << ~c1 << std::endl;

  return 0;
}
