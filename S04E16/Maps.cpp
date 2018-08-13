/* 
 * @ Name : Maps
 * @ Author : Jan Glos (re CaveofProgramming)  
*/

#include <iostream>
#include <map>
#include <string>

int main()
{
  std::map<std::string, int> ages;

  ages["Mike"] = 40;
  ages["Vicky"] = 20;
  ages["Raj"] = 15;
  ages["Raj"] = 14;

  std::cout << ages["Raj"] << std::endl;

  std::cout << ages["Sue"] << std::endl;

  if (ages.find("Vicky") != ages.end())
  {
    std::cout << "Found Vicky" << std::endl;
  }

  for( std::map<std::string, int>::iterator it = ages.begin(); it != ages.end(); it ++ )
  {
    std::cout << it->first << ": " << it->second << std::endl;
  }

  for( std::map<std::string, int>::iterator it = ages.begin(); it != ages.end(); it ++ )
  {
    std::pair<std::string, int> age = *it;
    std::cout << age.first << ": " << age.second << std::endl;
  }
  return 0;
}