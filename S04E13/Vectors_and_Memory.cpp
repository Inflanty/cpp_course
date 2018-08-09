/* 
 * @ Name : Vectors and Memory
 * @ Author : Jan Glos (re CaveofProgramming)  
*/

#include <iostream>
#include <vector>
#include <string>

int main()
{
  std::vector<double> numbers(20);

  std::cout << numbers.size() << std::endl;
  int capacity = numbers.capacity();
  std::cout << "Capacity, before the loop : " << capacity << std::endl;

  for (int i = 0; i < 2100; i ++)
  {
    if (numbers.capacity() != capacity)
    {
      capacity = numbers.capacity();
      std::cout << "Capacity : " << capacity << std::endl;
    }
    numbers.push_back(i);
  }

  numbers.resize( 100 );
  std::cout << "Size : " << numbers.size() << std::endl;
  std::cout << "Capacity : " << numbers.capacity() << std::endl;

  numbers.reserve( 1 );
  std::cout << "Size : " << numbers.size() << std::endl;
  std::cout << "Capacity : " << numbers.capacity() << std::endl;

  return 0;
}