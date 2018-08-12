/* 
 * @ Name : Vectors and Memory
 * @ Author : Jan Glos (re CaveofProgramming)  
*/

#include <iostream>
#include <list>
#include <string>

int main()
{
  std::list<int> numbers;

  numbers.push_back(1);
  numbers.push_back(2);
  numbers.push_back(3);
  numbers.push_front(0);

  for ( std::list<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
  {
    std::cout << *it << std::endl;
  }
  return 0;
}