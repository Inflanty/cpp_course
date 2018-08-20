/* 
 * @ Name : Overloading_Comparison_Operation
 * @ Author : Jan Glos (re CaveofProgramming)  
 * @ Compilation : Please type the command "gcc A_Complex_Number_Class.cpp -o Complex -lstdc++ Complex.cpp" 
*/

#include <iostream>
#include <string>
#include "Complex.h"

int main()
{
  caveofprogramming::CComplex c1(1,1);
  caveofprogramming::CComplex c2(23,1);

  if (c1 == c2)
  {
    std::cout << "Equals!" << std::endl;
  }
  else 
  {
    std::cout << "Not equals!" << std::endl;
  }

  if (c1 != c2)
  {
    std::cout << "NOT equals!" << std::endl;
  }
  else 
  {
    std::cout << "equals!" << std::endl;
  }

  return 0;
}
