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
//Guys, have you a second for a little talk after the meeting ? About my future in the Team.
//Talk in private
//I have opportunity to do foregin student intership in Swedish company which develop automotive embedded systems.
//Then I must take 6 montch non payed vacation because the interships duration is 6 month. they work with QT C++ and embedded linux systems.
//But the point is that my participation is unconfirmed yet, I'm waiting for secont recrutation step. I will recieve the finally decision until the end of the week.

//The worst thing is that the intership begins on third september, I know that its quite late for informing you but I receive a informations about the intership last week.
//I can try shift the term 2/3 weeks If I get the acceotance.
//But probably I will staty in Poland because the  

//It's unconfirmed and they can rejected me.

//I have some supposion about the issue reason.
//The point is that the electrical signals were not defined in IOsignals - yml file.
//I have already implemented them. 
//But the question is should I declere them in configit model ? 

//I wrote an email to task reporter about my doubts 
//Niels Eric Danielsen and I'm waiting for the answer.

//So as I expected, the intership in Sweden were canceled, so good information is that I stay in Poland,
//But I have other plan. I have been looking for some postgraduate studies and I found one in AGH 

//I'm waiting for confirmation from Swedish company.
//I can't contact them without the confirmation, this is the rules.
//This is company wchih developed linux embedded system for automotive mainly.
//The interships includes C++ programing, QT framework and RT Linux.
//I have been takling with Brian and he didn't mind, 
//I will know finally decision about the end of this week.
//About this project : Maciej know everything about new sprint.

//Today is a last day they can 
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