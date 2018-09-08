/* 
 * @ Name : Lambda_Parameters_and_Return_Type
 * @ Author : Jan Glos (re CaveofProgramming)  
*/

#include <iostream>
#include <string>

void testGreet(void (*greet)(std::string))
{
  greet("Bob");
}
void runDivide(double (*divide)(double a, double b))
{
  auto rval = divide(9, 3);
  std::cout << rval << std::endl;
}
int main(int argc, char const *argv[])
{
  auto pGreet = [](std::string name){ std::cout << "Hello " << name << std::endl; };
  
  pGreet("Mike");

  testGreet(pGreet);

  auto pDivide = [](double a, double b)
  {
    return a/b;
  };

  std::cout << pDivide(10.0, 5.0) << std::endl;
  runDivide(pDivide);
  
  return 0;
}
