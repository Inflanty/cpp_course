/* 
 * @ Name : Template_Functions_and_Type_Inference
 * @ Author : Jan Glos (re CaveofProgramming)  
*/

#include <iostream>
#include <string>

template<class T>
void print(T n)
{
  std::cout << "Printing something... " << n << std::endl;
}

void print(int n)
{
  std::cout << "Non template version : " << n << std::endl;
}

template<class T>
void show()
{
  std::cout << "Something " << T() << std::endl;
}

int main()
{
  print<int>(5);
  print<std::string>("Hello !");
  print("Hi");
  print(5);
  print<>(5);
  show<double>();
  return 0;
}
