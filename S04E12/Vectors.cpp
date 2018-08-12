/* 
 * @ Name : Vectors
 * @ Author : Jan Glos (re CaveofProgramming)  
*/

#include <iostream>
#include <vector>
#include <string>

int main()
{
  std::vector<std::string> strings;
  strings.push_back("one");
  strings.push_back("two");
  strings.push_back("three");

  std::cout << strings[2] << std::endl;
  std::cout << strings.size() << std::endl;

  for (int i = 0; i < strings.size(); i ++)
  {
    std::cout << strings[i] << std::endl;
  }

  for (std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); it++)
  {
    std::cout << *it << std::endl;
  }

  std::vector<int> intVector(5);
  std::vector<int>::iterator itInt = intVector.begin();
  itInt += 1;
  *itInt =+ 100;
  intVector[0] = 22;
  intVector[2] = 34;
  std::cout << "Iterator : " << *itInt << std::endl;
  std::cout << "Pierszy Element : " << intVector[0] << std::endl;
  std::cout << "Trzeci Element : " << intVector[2] << std::endl;

  std::vector<double> doubleVector;
  doubleVector.push_back(3.3);
  doubleVector.push_back(3.4);
  doubleVector.push_back(3.5);
  doubleVector.push_back(3.6);
  std::vector<double>::iterator itvDouble = doubleVector.begin();
  std::vector<double>::iterator itvDoubleInvert = doubleVector.end();
  int i = 0;
  for (std::vector<double>::iterator itD = doubleVector.begin(); itD != doubleVector.end(); itD ++)
  {
    i ++;
    itvDoubleInvert --;
    std::cout << "Element " << i << " przechowuje wartosc : " << *itD << std::endl;
    std::cout << "Element invert " << i << " przechowuje wartosc : " << *itvDoubleInvert << std::endl;
  }
  return 0;
}