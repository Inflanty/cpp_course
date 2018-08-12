/* 
 * @ Name : Binary_Files
 * @ Author : Jan Glos (re CaveofProgramming)  
*/

#include <iostream>
//#include <fstream>
#pragma pack(push, 1)

struct SPerson 
{
	char name[50];
	int age;
	double weight;
};

#pragma pack(pop)
int main()
{

	std::cout << sizeof(SPerson) << std::endl;
	std::cout << "." << std::endl;
	return 0;
}