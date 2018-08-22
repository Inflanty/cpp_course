/* 
 * @ Name : Using_Function_Pointers
 * @ Author : Jan Glos (re CaveofProgramming)  
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool match(std::string test)
{
  //return test = "two";
  return test.size() == 3;
}

int countsStrings(std::vector<std::string> &texts, bool (*match)(std::string test) )
{
  int tally = 0;
  for (int i = 0; i < texts.size(); i ++)
  {
    if ( match(texts[i]) )
    {
      tally ++;
    }
  }
  return tally;
}

int main()
{
  std::vector<std::string> texts;
  texts.push_back("one");
  texts.push_back("two");
  texts.push_back("three");
  texts.push_back("four");
  texts.push_back("two");
  texts.push_back("two");
  texts.push_back("one");
  texts.push_back("three");
  texts.push_back("five");

  std::cout << match("two") << std::endl;

  std::cout << std::count_if(texts.begin(), texts.end(), match) << std::endl;

  std::cout << countsStrings(texts, match) << std::endl;

  return 0;
}
