/* 
 * @ Name : Binary_Files
 * @ Author : Jan Glos (re CaveofProgramming)  
*/

#include <iostream>
#include <fstream>
#include <string>
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
	SPerson someone = {"Frodo", 220, 0.8};

	// ***************WRITE BINARY FILE***************
	std::string fileName = "test.bin";

	std::ofstream outputFile;
	outputFile.open( fileName, std::ios::binary );  
	//outputFile.close();

	if ( outputFile.is_open() )
	{
		outputFile.write(reinterpret_cast<char *>(&someone), sizeof(SPerson));
		outputFile.close();
	}
	else
	{
		std::cout << "Could not create the file : " << fileName << std::endl;
	} 
	
	// ***************READ BINARY FILE***************
	SPerson someoneElse = {};
	
	std::ifstream inputFile;
	inputFile.open( fileName, std::ios::binary );  

	if ( inputFile.is_open() )
	{
		inputFile.read(reinterpret_cast<char *>(&someoneElse), sizeof(SPerson));
		inputFile.close();
	}
	else
	{
		std::cout << "Could not open the file : " << fileName << std::endl;
	} 

	std::cout << someoneElse.name << " , " << someoneElse.age << " , " << someoneElse.weight << std::endl; 
	std::cout << "." << std::endl;
	return 0;
}