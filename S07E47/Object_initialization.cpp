/* 
 * @ Name : Object_initialization
 * @ Author : Jan Glos (re CaveofProgramming)  
*/

#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>


class CTest
{
  int id{3};
  std::string name{"Mike"};
public:
  CTest() = default;
  CTest(const CTest &other) = default;
  CTest &operator=(const CTest &other) = delete;

  CTest(int id): 
    id(id)
    {}

  void print()
  {
    std::cout << id << ": " << name << std::endl;
  }
};

int main(int argc, char const *argv[])
{

  CTest test;
  test.print();

  CTest test1(675);
  test1.print();

  std::cout << std::endl;

  CTest test2 = test;
  test2.print();
  
  return 0;
}
