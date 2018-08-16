/* 
 * @ Name : Set
 * @ Author : Jan Glos (re CaveofProgramming)  
*/

#include <iostream>
#include <set>
#include <string>

int main()
{
  std::set<int> number;
  number.insert(10);
  number.insert(1101);
  number.insert(13);
  number.insert(20);


  for ( std::set<int>::iterator it = number.begin(); it != number.end(); it ++ )
  {
    std::cout << *it << std::endl;
  }

  std::cout << " " << std::endl;
  for (std::set<int>::iterator it = number.find(13); it != number.end(); it++)
  {
    std::cout << *it << std::endl;
  }

  std::set<int>::iterator itXX = number.find(1101);
  if (itXX != number.end())
  {
    std::cout << "It's not the end !" << std::endl;
  }
  return 0;
}