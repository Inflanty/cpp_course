/* 
 * @ Name : Overloading_the_Assigment_Operator
 * @ Author : Jan Glos (re CaveofProgramming)  
*/

#include <iostream>
#include <string>

class CTest 
{
private:
  int id;
  std::string name;
public:
  CTest() : 
    id(0),
    name(" ")
    {}

  CTest( int id, std::string name ) :
    name( name ),
    id( id )
    {}

  void print()
  {
    std::cout << id << "-> " << name << std::endl;
  }

  const CTest &operator=(const CTest &other)
  {
    std::cout << "Assigment working..." << std::endl;

    id = other.id;
    name = other.name;
    return *this;
  }

  CTest(const CTest &other)
  {
    std::cout << "Copy constructor working..." << std::endl;
    *this = other;
  }
};

int main()
{
  CTest test1(10, "Mike");
  std::cout << "Print test1: " << std::flush;
  test1.print();

  CTest test2(20, "Bob");
  test2 = test1;
  std::cout << "Print test2: " << std::flush;
  test2.print();

  CTest test3;
  //test3 = test2 = test1;
  test3.operator=(test2);
  std::cout << "Print test3: " << std::flush;
  test3.print();

  // Copy initialization
  std::cout << "Copy initialization >>" << std::endl;
  CTest test4(test1);
  test4.print();

  return 0;
}