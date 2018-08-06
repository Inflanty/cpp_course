/* 
 * @ Name : Basic_Exceptions
 * @ Author : Jan Glos (re CaveofProgramming)  
*/

#include <iostream>
#include <fstream>

int main()
{
	std::ofstream outFile;
	std::fstream outFile2;
	std::string outputFileName = "newFile.txt";
	std::string outputFileName2 = "newFile2.txt";
	outFile.open(outputFileName);
	outFile2.open(outputFileName2, std::ios::out);
	if( outFile.is_open() )
	{
		outFile << "Hello there !" << std::endl;
		outFile << 121;
		outFile.close();
	}
	else
	{
		std::cout << "Can't open the file : " << outputFileName << std::endl;
	}
	
	if ( outFile2.is_open() )
	{
		outFile2 << "Something new" << std::endl;
		outFile2.close();
	}
	else
	{
		std::cout << "Can't open the file : " << outputFileName2 << std::endl;
	}
	std::cout << "." << std::endl;
	return 0;
}