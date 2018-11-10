/* 
 * @ Name : Lambda_Capture_Expressions
 * @ Author : Jan Glos (re CaveofProgramming)  
*/

#include <iostream>
#include <string>

int globalOne = 10;

int main(int argc, char const *argv[])
{
  int one = 1;
  int two = 2;
  int three = 3;

  [one, two](){std::cout << "Hello " << one << " and " << two << std::endl;}();
  [=](){ std::cout << "Hello " << one << " and " << two << std::endl; }();
  [=, &three](){globalOne = 11 ;three = 9; std::cout << "Hello " << three << " and " << two << std::endl; }();
  [&]() { std::cout << "Hello by reference" << one << " and " << two << std::endl; one = 0;}();

  std::cout << one << std::endl;
  std::cout << globalOne << std::endl;

  std::cout << "\n.\n.\n.\nThe End" << std::endl;
  return 0;
}
