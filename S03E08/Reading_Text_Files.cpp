/* 
 * @ Name : Basic_Exceptions
 * @ Author : Jan Glos (re CaveofProgramming)  
*/

#include <iostream>
#include <fstream>

int main()
{
	std::string fileName = "textFile.txt";
	
	std::ifstream inFile;
	inFile.open( fileName );
	
	if ( inFile.is_open() )
	{
		std::string line;
		inFile >> line;
		std::cout << line;
		getline( inFile, line );
		std::cout << line << std::endl;
		
		//while( !inFile.eof() )
		while(inFile)
		{
			getline( inFile, line );
			std::cout << line << std::endl;
		}
		inFile.close();
	}
	else
	{
		std::cout << "Can't open File : " << fileName;
	}
	
	std::cout << "." << std::endl;
	return 0;
}