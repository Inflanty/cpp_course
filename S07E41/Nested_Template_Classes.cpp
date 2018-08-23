/* 
 * @ Name : Nested_Template_Classes
 * @ Author : Jan Glos (re CaveofProgramming)  
*/

#include <iostream>
#include <string>
#include <typeinfo>
#include "ring.h"


int main()
{
  CRing<std::string>::Iterator it;
  it.print();
  /*
  CRing<std::string> textring(3);

  textring.add("one");
  textring.add("two");
  textring.add("three");
  textring.add("four");

  for(int i = 0; i < textring.size(); i++)
  {
    std::cout << textring.get(i) << std::endl;
  }
  */
  return 0;
}
