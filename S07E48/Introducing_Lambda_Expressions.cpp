/* 
 * @ Name : Introducing_Lambda_Expressions
 * @ Author : Jan Glos (re CaveofProgramming)  
*/

#include <iostream>
#include <string>

void test(void (*pFunction)())
{
  pFunction();
}

int main(int argc, char const *argv[])
{
  auto function = [](){ std::cout << "Hello" << std::endl; };
  
  function();

  test(function);

  test([](){std::cout << "Hello" << std::endl;});
  
  return 0;
}
