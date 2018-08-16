/* 
 * @ Name : Custom Objects as Map Values
 * @ Author : Jan Glos (re CaveofProgramming)  
*/

#include <iostream>
#include <map>
#include <string>

class CPerson 
{
private:
  std::string name;
  int age;
public:
  CPerson ( ) :
    name(""),
    age(0)
  {
    std::cout << "From no argument constructor" << std::endl;
  }

  CPerson( std::string name, int age ) : 
    name(name),
    age(age)
  {
    std::cout << "From arguments constructor" << std::endl;
  }

  void print() const
  {
    std::cout << name << ": " << age << std::endl;
  }
};

int main()
{
  std::map<int, CPerson> people;

  people[0] = CPerson("Mike", 25);
  people[1] = CPerson("Halinka", 22);
  people[2] = CPerson("Vicky", 19);

  for( std::map<int, CPerson>::iterator it = people.begin(); it != people.end(); it ++ )
  {
    std::cout << it->first << ": " << std::flush;
    it->second.print();
  }
  return 0;
}