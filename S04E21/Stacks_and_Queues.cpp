/* 
 * @ Name : Stacks_and_Queues
 * @ Author : Jan Glos (re CaveofProgramming)  
*/

#include <iostream>
#include <string>
#include <queue>
#include <stack>

class CTest
{
private:
  std::string name;
public:
  CTest(std::string name):
  name(name)
  {

  }

  ~CTest()
  {
    //std::cout << "Object destroyed !" << std::endl;
  }

  void print()
  {
    std::cout << name << std::endl;
  }
};

int main()
{
  // LIFO
  std::stack<CTest> testStack;
  testStack.push(CTest("Mike"));
  testStack.push(CTest("John"));
  testStack.push(CTest("Lucy"));

  while (testStack.size() > 0)
  {
    CTest &test = testStack.top();
    test.print();
    testStack.pop();
    std::cout << "Stack size: " << testStack.size() << std::endl;
  }

  std::cout << "************* BREAK *************" << std::endl;
  std::queue<CTest> testQueue;
  testQueue.push(CTest("John"));
  testQueue.push(CTest("Jackob"));
  testQueue.push(CTest("Joanna"));

  while ( testQueue.size() > 0 )
  {
    CTest &test = testQueue.front();
    test.print();
    testQueue.pop();
  }


  return 0;
}