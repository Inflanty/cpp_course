/* 
 * @ Name : Object_Slicing_and_Polymorphism
 * @ Author : Jan Glos (re CaveofProgramming)  
*/

#include <iostream>
#include <string>

class CParent
{
private:
  int one;

  bool typeFlag;
  int typeVariable;
public:
  int oneType;

  CParent():
  one(0),
  typeFlag(false),
  typeVariable(666),
  oneType(0)
  {
    std::cout << "from constructor" << std::endl;
  }

  CParent(const CParent &other):
  one(0),
  typeFlag(false),
  typeVariable(666),
  oneType(0)
  {
    one = other.one;
    std::cout << "copy parent" << std::endl;
  }

  virtual void print()
  {
    std::cout << "Parent" << std::endl;
  }

  virtual ~CParent()
  {

  }

  void type(bool flag, int variable)
  {
    typeFlag = flag;
    typeVariable = variable;
    std::cout << "typing !" << std::endl;
  }
};

class CChild : public CParent
{
private:
  int two;
public:
  CChild():
  two(0)
  {

  }

  void print()
  {
    std::cout << "child" << std::endl;
  }
};


int main()
{
  CChild c1;
  CParent &p1 = c1;
  p1.print();
  c1.type(34, true);
  c1.oneType = 456;

  CParent p2 = CChild();
  p2.print();

  return 0;
}
