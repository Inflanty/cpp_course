/* 
 * @ Name : Custom_Exceptions
 * @ Author : Jan Glos (re CaveofProgramming)  
*/

#include <iostream>
#include <exception>

void goesWrong ()
{
	bool something1Wrong = false;
	bool something2Wrong = true;
	
	if (something1Wrong)
	{
		throw std::bad_alloc();
	}
	
	if (something2Wrong)
	{
		throw std::exception();
	}
}

int main()
{
	try
	{
		goesWrong();
	}
		catch (std::bad_alloc &ex)
	{
		std::cout << "Catching bad_alloc : " << ex.what() << std::endl;
	}
	catch (std::exception &ex)
	{
		std::cout << "Catching exception : " <<ex.what() << std::endl;
	}
  std::cout << "After Throw" << std::endl;
  return 0;
}