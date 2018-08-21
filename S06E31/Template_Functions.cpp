/* 
 * @ Name : Template_Functions
 * @ Author : Jan Glos (re CaveofProgramming)  
*/

#include <iostream>
#include <string>

template<class T>
void print(T n)
{
  std::cout << "Printing something... " << n << std::endl;
}

int main()
{
  print<int>(5);
  print<std::string>("Hello !");
  print("Hi");
  print(5);

  return 0;
}
