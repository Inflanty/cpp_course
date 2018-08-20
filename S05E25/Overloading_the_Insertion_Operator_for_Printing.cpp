/* 
 * @ Name : Overloading_the_Insertion_Operator_for_Printing
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
    id = other.id;
    name = other.name;
    return *this;
  }

  CTest(const CTest &other)
  {
    *this = other;
  }

  friend std::ostream &operator<<(std::ostream &out, const CTest &test)
  {
    out << test.id << ": " << test.name;
    return out;
  }
};

int main()
{
  CTest test1(10, "Mike");
  CTest test2(30, "Tomy");

  //test1.print();
  std::cout << test1 << test2 << std::endl;

  return 0;
}