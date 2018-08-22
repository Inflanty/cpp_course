/* 
 * @ Name : Function_Pointers
 * @ Author : Jan Glos (re CaveofProgramming)  
*/

#include <iostream>

void test(int val)
{
  std::cout << "Hello " << val << std::endl;
}

int main()
{
  test(1);

  void (*pTest)(int) = test;
  //pTest = &test;
  pTest(6);

  return 0;
}

// I don't have any task now,
// I'm staying in Poland, this is confirmed information.
// So I will not leave the team for the Intership in Sweden.

// I have been talking with coordinator from Poland and Sweden in case of lack of contact with Sweden company,
// We decided that I staying in Poland.
// IAESTE is a international students organization, they cooperate with big companys and organize student interships.
