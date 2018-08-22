/* 
 * @ Name : Abstract_Classes
 * @ Author : Jan Glos (re CaveofProgramming)  
*/

#include <iostream>
#include <string>

class CAnimal
{
public:
  virtual void run() = 0;
  virtual void speak() = 0;
};

class CDog: public CAnimal
{
public:
  virtual void speak()
  {
    std::cout << "Woof!" << std::endl;
  }
};

class CLabrador: public CDog
{
public:
  CLabrador()
  {
    std::cout << "New Labrador in the city" << std::endl;
  }

  virtual void run()
  {
    std::cout << "Labrador running" << std::endl;
  }
};

void test(CAnimal &a)
{
  a.run();
}

int main()
{
  CLabrador labrador1;

  labrador1.run();
  labrador1.speak();

  CLabrador *animals[5];
  animals[0] = &labrador1;
  animals[0]->speak();
  test(labrador1);

  return 0;
}
