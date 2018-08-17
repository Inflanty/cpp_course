/* 
 * @ Name : Set
 * @ Author : Jan Glos (re CaveofProgramming)  
*/

#include <iostream>
#include <set>
#include <string>

class CTest
{
  int id;
  std::string name;
public:
  CTest ():
  id(0),
  name("")
  {

  }

  CTest(int id, std::string name):
  id(id),
  name(name)
  {

  }

  void print() const
  {
    std::cout << id << ": " << name << std::endl;
  }

  bool operator<(const CTest &other) const
  {
    return name < other.name;
  }
};

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
  std::cout << " " << std::endl;

  std::set<int>::iterator itXX = number.find(101);
  if (itXX != number.end())
  {
    std::cout << "Found: " << *itXX << std::endl;
  }

  std::set<CTest> tests;

  tests.insert(CTest(30, "Mike"));
  tests.insert(CTest(20, "Joe"));
  tests.insert(CTest(110, "Joe"));
  tests.insert(CTest(31, "Adam"));

  for (std::set<CTest>::iterator it = tests.begin(); it != tests.end(); it ++)
  {
    it->print();
  }
  return 0;
}