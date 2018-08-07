/* 
 * @ Name : Custom_Exceptions
 * @ Author : Jan Glos (re CaveofProgramming)  
*/

#include <iostream>
#include <exception>

class CMyException: public std::exception
{
public:
	virtual const char* what() const throw()
	{
	 	return "Something happened";
	}
};

class CTest
{
public:
	void goesWrong()
	{
		throw CMyException();
	}
};

int main()
{
	CTest myTest;
	try
	{
		myTest.goesWrong();
	}
	catch (CMyException &exception)
	{
		std::cout << "Exception : " << exception.what() << std::endl;
	}

  std::cout << "After Throw" << std::endl;
  return 0;
}