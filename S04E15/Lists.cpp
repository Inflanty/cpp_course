/* 
 * @ Name : Vectors and Memory
 * @ Author : Jan Glos (re CaveofProgramming)  
*/

#include <iostream>
#include <list>
#include <string>

int main()
{
  int numbersMembers = 0;
  std::list<int> numbers;

  numbers.push_back(1);
  numbers.push_back(2);
  numbers.push_back(3);
  numbers.push_front(0);

  for ( std::list<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
  {
    numbersMembers ++;
    std::cout << *it << std::endl;
  }
  std::cout << "Members of Numbers : " << numbersMembers << std::endl;
  
  // Second stage
  numbersMembers = 0;
  std::list<int>::iterator itFirst = numbers.begin();
  numbers.insert(itFirst, 100);

  for ( std::list<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
  {
    numbersMembers ++;
    std::cout << *it << std::endl;
  }
  std::cout << "Members of Numbers : " << numbersMembers << std::endl;

  // Third stage
  numbersMembers = 0;
  std::list<int>::iterator itSecond = numbers.begin();
  numbers.insert(itSecond, 110);
  numbers.insert(itSecond, 124);
  itSecond ++;
  *itSecond += 12;

    for ( std::list<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
  {
    numbersMembers ++;
    std::cout << *it << std::endl;
  }
  std::cout << "Members of Numbers : " << numbersMembers << std::endl;

  itSecond ++;
  std::cout << "Element before erase : " << *itSecond << std::endl;
  itSecond = numbers.erase(itSecond);
  std::cout << "Element after erase : " << *itSecond << std::endl;
  itSecond ++;
  itSecond = numbers.erase(itSecond);
  std::cout << "Element after erase : " << *itSecond << std::endl;
  for ( std::list<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
  {
    numbersMembers ++;
    std::cout << *it << std::endl;
  }
  std::cout << "Members of Numbers : " << numbersMembers << std::endl;
  numbers.sort();
  for ( std::list<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
  {
    numbersMembers ++;
    std::cout << *it << std::endl;
  }
  numbers.reverse();
  for ( std::list<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
  {
    numbersMembers ++;
    std::cout << *it << std::endl;
  }
  return 0;
}