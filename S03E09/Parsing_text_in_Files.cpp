/* 
 * @ Name : Basic_Exceptions
 * @ Author : Jan Glos (re CaveofProgramming)  
*/

#include <iostream>
#include <fstream>

int main()
{
	std::string fileName = "newFile.txt";
	
	std::ifstream inFile;
	inFile.open( fileName );
	
	if ( !inFile.is_open() )
	{
		return 1;
	}
	
	while (inFile)
	{
		std::string line;
		
		getline( inFile, line, ':');
		
		int population;
		inFile >> population;
		inFile.get();
		inFile >> std::ws;
		
		std::cout << line << "----" << population << std::endl;
	}
	inFile.close();
	std::cout << "." << std::endl;
	return 0;
}