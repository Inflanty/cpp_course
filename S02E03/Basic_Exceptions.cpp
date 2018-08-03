/* 
 * @ Name : Basic_Exceptions
 * @ Author : Jan Glos (re CaveofProgramming)  
*/

#include <iostream>

void mightGoWrong()
{
  bool error = false, error2 = false, error3 = true;

  if (error)
  {
    throw "Something went wrong !";
  }

  if (error2)
  {
    throw std::string("Something else went wrong !");
  }

  if (error3)
  {
    throw 4.33f;
  }
}

void takeExceptions()
{
  mightGoWrong();
}

int main()
{
  try 
  {
    takeExceptions();
  }
  catch(int exception)
  {
    std::cout << "Error code : " << exception << std::endl;  
  }
  catch(const char * exception)
  {
    std::cout << "Error code : " << exception << std::endl;
  }
  catch(std::string &exception)
  {
    std::cout << "String Error Message : " << exception << std::endl;
  }
  catch(float exception)
  {
    std::cout << "Error code : " << exception << std::endl; 
  }
  std::cout << "After Throw" << std::endl;
  return 0;
}