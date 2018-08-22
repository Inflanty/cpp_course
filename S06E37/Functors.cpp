/* 
 * @ Name : Functors
 * @ Author : Jan Glos (re CaveofProgramming)  
*/

#include <iostream>
#include <string>

struct Test{
  virtual bool operator()(std::string &text)
  {

  }

  virtual ~Test()
  {

  }
};

struct MatchTest: public Test
{
  virtual bool operator()(std::string &text)
  {
    return text == "Lion";
  }
};

void check(std::string text, Test &test)
{
  if(test(text))
  {
    std::cout << "Concept" << std::endl;
  }
  else 
  {
    std::cout << "NO Concept" << std::endl;
  }
}

class CDimmensions
{
private:
  int x, y, z;
public:
  CDimmensions():
  x(0),
  y(0),
  z(0)
  {

  }

  ~CDimmensions()
  {

  }

  virtual void setDimensions(int X, int Y, int Z)
  {
    x = X;
    y = Y;
    z = Z;
  }

  int calculateVolume()
  {
    return (x*y*z);
  }  

  int calculateArea()
  {
    return (x*y);
  }
};

class CTent: public CDimmensions
{
private:
  bool opened;
public:
  bool operator()(std::string &text)
  {
    if( text == "UP" && !opened)
    {
      std::cout << "Opening the Tent..." << std::endl;
      std::cout << "Give the dimmensions" << std::endl;
      std::cout << "Volume: " << calculateVolume() << std::endl;
      std::cout << "Area: " << calculateArea() << std::endl;
      std::cout << "DONE !" << std::endl;
      opened = 1;
      return true;
    }
    else if( text == "UP" && opened)
    {
      std::cout << "Already opened" << std::endl;
      return false;
    }
    else if( text == "DOWN" && opened )
    {
      std::cout << "Spreading the Tent..." << std::endl;
      std::cout << "DONE !" << std::endl;
      opened = 0;
      return true;
    }
    else if( text == "DOWN" && !opened )
    {
      std::cout << "The Tent is closed !" << std::endl;
      return false;
    }
    std::cout << "Logic error !" << std::endl;
    return false;
  }
};

int main()
{

  MatchTest pred;
  std::string value = "Lion";
  pred(value);

  MatchTest m;
  check("Lion", m);

  CTent Quechua;
  Quechua.setDimensions(3, 4, 2);

  std::string up = "UP", down = "DOWN";
  
  Quechua(up);
  Quechua(up);
  Quechua(down);
  Quechua(down);


  return 0;
}
