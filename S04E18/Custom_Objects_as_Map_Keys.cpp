/* 
 * @ Name : Custom_Objects_as_Map_Keys
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
    std::cout << name << ": " << age << std::flush;
  }

  bool operator<(const CPerson &other) const
  {
    if (name == other.name)
    {
      return age < other.age;
    }
    else
    {
      return name < other.name;
    }
  }
};

int main()
{
  std::map<CPerson, int> people;

  people[CPerson("Mike", 40)] = 40;
  people[CPerson("Mike", 440)] = 120;
  people[CPerson("Sue", 20)] = 20;
  people[CPerson("Gaba", 30)] = 30;

  for( std::map<CPerson, int>::iterator it = people.begin(); it != people.end(); it ++ )
  {
    std::cout << it->second << ": " << std::flush;
    it->first.print();
    std::cout << std::endl;
  }
  return 0;
}