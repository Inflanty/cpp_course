/* 
 * @ Name : Auto_Keyword
 * @ Author : Jan Glos (re CaveofProgramming)  
*/

#include <iostream>
#include <string>
#include <typeinfo>

template <class T, class S>
auto addSomething(T valueT, S valueS) -> decltype(valueT + valueS)
{
  return valueT+valueS;
}

int get()
{
  return 999;
}
auto test() -> decltype(get())
{
  return get();
}

int main()
{
  auto value = 7;
  auto text = "Hello";
  
  std::cout << value << std::endl;
  std::cout << addSomething(6.5, 5) << std::endl;
  std::cout << test() << std::endl;

  return 0;
}
