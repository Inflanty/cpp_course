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
//Talk in private
//I have opportunity to do foregin student intership in Swedish company which develop automotive embedded systems.
//Then I must take 6 montch non payed vacation because the interships duration is 6 month. they work with QT C++ and embedded linux systems.
//But the point is that my participation is unconfirmed yet, I'm waiting for secont recrutation step. 
//It's unconfirmed and they can rejected me

//I have some supposion about the issue reason.
//The point is that the electrical signals were not defined in IOsignals - yml file.
//I have already implemented them. 
//But the question is should I declere them in configit model ? 

//I wrote an email to task reporter about my doubts 
//Niels Eric Danielsen and I'm waiting for the answer.
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