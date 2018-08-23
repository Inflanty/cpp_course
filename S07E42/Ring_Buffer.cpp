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


  for(int i = 0; i < textring.size(); i++)
  {
    std::cout << textring.get(i) << std::endl;
  }
  
  return 0;
}
