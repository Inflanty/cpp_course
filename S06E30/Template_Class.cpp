/* 
 * @ Name : Template_Class
 * @ Author : Jan Glos (re CaveofProgramming)  
 * @ Compilation : Please type the command "gcc A_Complex_Number_Class.cpp -o Complex -lstdc++ Complex.cpp" 
*/

#include <iostream>
#include <string>

template<class T, class K>
class CTest
{
private:
  T object;
  K variable;
public:
  CTest(T object, K varaiable)
  {
    this->object = object;
    this->variable = variable;
  }

  void print()
  {
    std::cout << object << std::endl;
  }

  void calculate()
  {
    std::cout << "Calculate function running, with argument: " << variable << std::endl;
  }
};

int main()
{
  CTest<std::string, int> test1("Hello!", 11110);
  test1.print();
  test1.calculate();

  return 0;
}
