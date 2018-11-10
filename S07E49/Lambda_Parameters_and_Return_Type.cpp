/* 
 * @ Name : Lambda_Parameters_and_Return_Type
 * @ Author : Jan Glos (re CaveofProgramming)  
*/

#include <iostream>
#include <string>

void testGreetSecond (void (*someFunction)(std::string _name), std::string _nameMain)
{
  someFunction(_nameMain);
}

void testFirst(std::string _name)
{
  std::cout << "Name : " << _name << std::endl;
}

void testGreet(void (*greet)(std::string))
{
  greet("Bob");
}
void runExpression(double (*expression)(double a, double b))
{
  auto rval = expression(9.6, 3.1);
  std::cout << rval << std::endl;
}
int main(int argc, char const *argv[])
{
  auto pGreet = [](std::string name){ std::cout << "Hello " << name << std::endl; };
  
  pGreet("Mike");

  testGreet(pGreet);

  auto pDivide = [](double a, double b)
  {
    std::cout << "DIVIDE :" << std::endl;
    return a/b;
  };

  auto pDifference = [](double a, double b) 
  {
    std::cout << "DIFFERENCE :" << std::endl;
    return a > b ? (a - b) : (b - a);
  };

  auto pSum = [](double a, double b) 
  {
    std::cout << "SUM :" << std::endl;
    return (a + b);
  };

  auto pMultiplication = [](double a, double b) {
    std::cout << "MULTIPLICATION :" << std::endl;
    return (a * b);
  };

  std::cout << pDivide(10.0, 5.0) << std::endl;
  runExpression(pDivide);
  runExpression(pDifference);
  runExpression(pSum);
  runExpression(pMultiplication);

  double someRetValue = pDifference(9.0, 1.3);
  std::cout << "Difference : " << someRetValue << std::endl;

  testGreetSecond(testFirst, "Piter");

  return 0;
}
