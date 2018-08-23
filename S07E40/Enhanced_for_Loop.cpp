/* 
 * @ Name : Enhanced_for_Loop
 * @ Author : Jan Glos (re CaveofProgramming)  
*/

#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>


int main()
{
  auto textAuto = {"one", "two", "three"};
  
  for (auto text: textAuto)
  {
    std::cout << text << std::endl;
  }

  std::vector<int> numbers;

  numbers.push_back(5);
  numbers.push_back(4);
  numbers.push_back(7);
  numbers.push_back(9);

  for(auto number: numbers)
  {
    std::cout << number << std::endl;
  }

  std::string hello = "Hello";
  
  for(auto c: hello)
  {
    std::cout << c << std::endl;
  }
  return 0;
}
