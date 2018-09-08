/* 
 * @ Name : C++_98_initialization
 * @ Author : Jan Glos (re CaveofProgramming)  
*/

#include <iostream>
#include <string>
#include <typeinfo>


int main()
{

  int intTable[] = {1, 5, 7};

  class CSomeClass
  {
  public:

    int id;
    std::string text;
  };

  CSomeClass someClass = {1, "Some Class"};

  std::cout << someClass.text << std::endl;

  struct SSomeStruct
  {
    int id;
    std::string text; 
  };

  SSomeStruct someStru = {1, "Some Structure"};
  std::cout << someStru.text << std::endl;

  struct SSomeStructXXX
  {
    int id;
    std::string text;
  } someStruXXX = {1, "Some Structure form XXX"};
  

  std::cout << someStruXXX.text << std::endl;

  return 0;
}
