/* 
 * @ Name : Standard_Exceptions
 * @ Author : Jan Glos (re CaveofProgramming)  
*/

#include <iostream>

class canGoWrong
{
public:
  canGoWrong()
  {
    char *pMemory = new char[699];
    delete [] pMemory;
  }
};

int main()
{ 
  try
  {
    canGoWrong wrong;
  }
  catch(std::bad_alloc &exception)
  {
    std::cout << "Cought exception : " << exception.what() << std::endl;
  }
  std::cout << "Running" << std::endl;
  return 0;
}