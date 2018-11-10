/* 
 * @ Name : Functional_Types
 * @ Author : Jan Glos (re CaveofProgramming)  
*/

#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <algorithm>

bool check(std::string &test)
{
  return test.size() == 3;
}

class CCheck
{
public:
  bool operator()(std::string &test)
  {
    return test.size() == 5;
  }
} checkFirst; 

void run(std::function<bool(std::string&)> check)
{
  std::string test = "doggy";
  std::cout << test << std::endl;
  std::cout << check(test) << std::endl;
}

int main(int argc, char const *argv[])
{
  int size = 5;
  std::vector<std::string> vectorStrings{"One", "Two", "Three"};
  int count = count_if(vectorStrings.begin(), vectorStrings.end(), [size](std::string test) { return test.size() == size; });
  std::cout << count << std::endl;

  int countSecond = count_if(vectorStrings.begin(), vectorStrings.end(), check);
  std::cout << countSecond << std::endl;
  auto lambda = [size](std::string test) { return test.size() == size; };
  
  run(lambda );
  run(checkFirst);
  run(check);

  std::cout << "\n.\n.\n.\nThe End" << std::endl;
  return 0;
}
