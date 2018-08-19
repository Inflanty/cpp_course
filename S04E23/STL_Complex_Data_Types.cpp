/* 
 * @ Name : STL_Complex_Data_Types
 * @ Author : Jan Glos (re CaveofProgramming)  
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>


int main()
{
  std::map<std::string,std::vector<int> > scores;

  scores["Adam"].push_back(12);
  scores["Vicky"].push_back(22);
  scores["Tom"].push_back(32);

  for (std::map<std::string, std::vector<int> >::iterator it = scores.begin(); it != scores.end(); it ++)
  {
    std::string name = it->first;
    std::vector<int> scoreList = it->second;

    std::cout << "My score : " << name << std::flush;

    for (int i = 0; i < scoreList.size(); i++)
    {
      std::cout << " " << scoreList[i] << std::flush;
    }

    std::cout << std::endl;
  }

    return 0;
}