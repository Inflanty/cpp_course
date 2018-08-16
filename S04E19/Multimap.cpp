/* 
 * @ Name : Multimap
 * @ Author : Jan Glos (re CaveofProgramming)  
*/

#include <iostream>
#include <map>
#include <string>

int main()
{
  std::multimap<int, std::string> lookup;

  lookup.insert(std::make_pair(30 , "Mike"));
  lookup.insert(std::make_pair(32, "Vicky"));
  lookup.insert(std::make_pair(31, "Adam"));
  lookup.insert(std::make_pair(31, "Bart"));

  for (std::multimap<int, std::string>::iterator it = lookup.begin(); it != lookup.end(); it ++)
  {
    std::cout << it->first << ": " << it->second << std::endl;
  }
  std::cout << std::endl;
  for (std::multimap<int, std::string>::iterator it = lookup.find(32); it != lookup.end(); it++)
  {
    std::cout << it->first << ": " << it->second << std::endl;
  }
  std::cout << std::endl;
  std::pair<std::multimap<int, std::string>::iterator, std::multimap<int, std::string>::iterator> its = lookup.equal_range(31);

  for (std::multimap<int, std::string>::iterator it = its.first; it != its.second; it++)
  {
    std::cout << it->first << ": " << it->second << std::endl;
  }
  std::cout << std::endl;
  auto itsAuto = lookup.equal_range(31);

  for (std::multimap<int, std::string>::iterator it = itsAuto.first; it != itsAuto.second; it++)
  {
    std::cout << it->first << ": " << it->second << std::endl;
  }

  return 0;
}