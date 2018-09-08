/* 
 * @ Name : Initializer_list
 * @ Author : Jan Glos (re CaveofProgramming)  
*/

#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>


class CTest
{
public:
  CTest(std::initializer_list<std::string> texts)
  {
    for( auto value: texts )
    {
      std::cout << value << std::endl;
    }
  }

  void print(std::initializer_list<std::string> texts)
  {
    for(auto value: texts)
    {
      std::cout << value << std::endl;
    }
  }
};

int main(int argc, char const *argv[])
{
  std::vector<int> numbers {1,2,3,4,5,6,6777,34};
  std::cout << numbers[4] << std::endl;

  CTest test{"apple", "orange", "banana"};

  test.print({"Something", "Else"});
  return 0;
}
