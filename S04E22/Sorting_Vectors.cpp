/* 
 * @ Name : Sorting_Vectors
 * @ Author : Jan Glos (re CaveofProgramming)  
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class CTest
{
private:
  int id;
  std::string name;
public:
  CTest(int id, std::string name):
  name(name),
  id(id)
  {

  }

  void print()
  {
    std::cout << id << "." << name << std::endl;
  }
  /*
  bool operator<(const CTest &other) const
  {
    return name < other.name;
  }*/

  friend bool compare(const CTest &A, const CTest &B);
};

bool compare(const CTest &A, const CTest &B)
{
  return A.id < B.id;
}

    int main()
{
  std::vector<CTest> testVector;  

  testVector.push_back(CTest(1, "Mike"));
  testVector.push_back(CTest(2, "Tomy"));
  testVector.push_back(CTest(7, "Vera"));
  testVector.push_back(CTest(4, "Adam"));

  std::sort(testVector.begin(), testVector.end(), compare);

  for (int i = 0; i < testVector.size(); i ++)
  {
    testVector[i].print();
  }
  return 0;
}