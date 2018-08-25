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
  textring.add("four");
  textring.add("five");
  textring.add("six");
 
  for (CRing<std::string>::Iterator it = textring.begin(); it != textring.end(); it ++)
  {
    std::cout << *it << std::endl;
  }

  for(int i = 0; i < textring.size(); i++)
  {
    std::cout << textring.get(i) << std::endl;
  }
  return 0;
}
