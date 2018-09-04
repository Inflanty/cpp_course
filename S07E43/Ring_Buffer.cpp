/* 
 * @ Name : Ring_Buffer
 * @ Author : Jan Glos (re CaveofProgramming)  
*/

#include <iostream>
#include <string>
#include <typeinfo>
#include "ring.h"


int main()
{
  
  CRing<std::string> textring(3);

  textring.add("one");
  textring.add("two");
  textring.add("three");
  
  for (CRing<std::string>::Iterator it = textring.begin(); it != textring.end(); it ++)
  {
    std::cout << *it << std::endl;
  }

  std::cout << std::endl;

  for (auto val : textring)
  {
    std::cout << val << std::endl;
  }
  return 0;
}
