// C++ Tutorial - Files.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::string toWrite1 = "This is a test!";
	int toWrite2 = 573;
	float toWrite3 = -123.4f;

	{
		// Text Files

		{
			// Writing
			std::ofstream outputFile;
			outputFile.open("text_file.txt");

			outputFile << toWrite1 << std::endl;
			outputFile << toWrite2 << std::endl;
			outputFile << toWrite3 << std::endl;

			outputFile.close();
		}

		{
			// Reading
			std::ifstream inputFile;
			inputFile.open("text_file.txt");

			// did we find and open the file?
			if (inputFile.is_open())
			{
				std::string readValue1;
				std::getline(inputFile, readValue1);

				int readValue2;
				inputFile >> readValue2;

				float readValue3;
				inputFile >> readValue3;

				std::cout << readValue1 << std::endl;
				std::cout << readValue2 << std::endl;
				std::cout << readValue3 << std::endl;
			}

			inputFile.close();
		}
	}

	{
		// Binary Files

		{
			// writing

			std::ofstream outputFile;
			outputFile.open("binary_file.bin", std::ios::out | std::ios::binary);

			std::size_t toWrite1Length = toWrite1.size();

			outputFile.write((char*)&toWrite1Length, sizeof(toWrite1Length));
			outputFile.write(toWrite1.c_str(), toWrite1Length);
			outputFile.write((char*) &toWrite2, sizeof(toWrite2));
			outputFile.write((char*) &toWrite3, sizeof(toWrite3));

			outputFile.close();
		}

		{
			// reading

			std::ifstream inputFile;
			inputFile.open("binary_file.bin", std::ios::in | std::ios::binary);

			std::size_t readValue1Length;
			inputFile.read((char*) &readValue1Length, sizeof(readValue1Length));

			char* readValue1Buffer = new char[readValue1Length + 1];

			inputFile.read(readValue1Buffer, readValue1Length);
			readValue1Buffer[readValue1Length] = '\0'; // add end of string terminator

			std::string readValue1 = readValue1Buffer;

			delete[] readValue1Buffer;

			int readValue2;
			inputFile.read((char*)& readValue2, sizeof(readValue2));

			float readValue3;
			inputFile.read((char*)& readValue3, sizeof(readValue3));

			inputFile.close();

			std::cout << readValue1 << std::endl;
			std::cout << readValue2 << std::endl;
			std::cout << readValue3 << std::endl;
		}
	}
}
