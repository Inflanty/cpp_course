/* 
 * @ Name : Decltype
 * @ Author : Jan Glos (re CaveofProgramming)  
*/

#include <iostream>
#include <string>
#include <typeinfo>

int main()
{
  std::string value;

  std::cout << typeid(value).name() << std::endl;

  decltype(value) name = "Bob";
  std::cout << name << std::endl;


  return 0;
}
