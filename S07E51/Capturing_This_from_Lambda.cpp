/* 
 * @ Name : Capturing_This_from_Lambda
 * @ Author : Jan Glos (re CaveofProgramming)  
*/

#include <iostream>
#include <string>

class CTest
{
private:
  int one = 1;
  int two = 2;

public:
  void run()
  {
    int three = 3;
    int four = 4;

    auto pLambda = [this, three, four]() {
      std::cout << ". one" << one << std::endl;
      std::cout << ". two" << two << std::endl;
      std::cout << ". three" << three << std::endl;
      std::cout << ". four" << four << std::endl;
    };

    pLambda();
  }
};

int globalOne = 10;

int main(int argc, char const *argv[])
{
  CTest testOne;
  testOne.run();

  std::cout << "\n.\n.\n.\nThe End" << std::endl;
  return 0;
}
