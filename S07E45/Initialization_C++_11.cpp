/* 
 * @ Name : Initialization_in_C++_11
 * @ Author : Jan Glos (re CaveofProgramming)  
*/

#include <iostream>
#include <string>
#include <vector>

int main(int argc, char const *argv[])
{
  int value{5};

  std::cout << value << std::endl;

  std::string text{"Some Text"};
  std::cout << text << std::endl;

  int numbers[]{1,2,3,4,5,6};
  std::cout << numbers[3] << std::endl;
  
  int *pInt = new int[3]{1,2,33};
  std::cout << pInt[2] << std::endl;
  delete pInt;

  int value1{};
  std::cout << value1 << std::endl;

  int *pSomething{&value};
  std::cout << *pSomething << std::endl;

  struct 
  {
    int id;
    std::string text;
    double something;
  } Cjpn3133{5, "password", 4.3};

  std::cout << Cjpn3133.text << std::endl;

  std::vector<std::string> strings{"one", "two", "three"};
  std::cout << strings[1] << std::endl;

  return 0;
}
