/* 
 * @ Name : A_Complex_Number_Class
 * @ Author : Jan Glos (re CaveofProgramming)  
 * @ Compilation : Please type the command "gcc A_Complex_Number_Class.cpp -o Complex -lstdc++ Complex.cpp" 
*/

#include <iostream>
#include <string>
#include "Complex.h"


int main()
{
  std::cout << std::endl;
  std::cout << "Complex making" << std::endl;
  caveofprogramming::CComplex complex;
  std::cout << std::endl;

  std::cout << "ComplexCopy making" << std::endl;
  caveofprogramming::CComplex complexCopy = complex;
  std::cout << std::endl;

  std::cout << "ComplexCopyClear making" << std::endl;
  caveofprogramming::CComplex complexCopyClear;
  complexCopyClear = complex;
  std::cout << std::endl;

  std::cout << "Making an complex variable" << std::endl;
  caveofprogramming::CComplex complexVariable(1, 0.8);
  caveofprogramming::CComplex complexVariableEqual = complexVariable;

  std::cout << "Complex Variable = " << complexVariable << std::endl;
  std::cout << "Complex Variable Equal init = " << complexVariableEqual << std::endl;

  return 0;
}
