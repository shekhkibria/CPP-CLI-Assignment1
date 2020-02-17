#include "stdafx.h"
#include <fstream>
#include "FileInputOutput.h"


FileInputOutput::FileInputOutput(string inputFileName, string outputFileName)
{
	this->inputFileName = inputFileName;
	this->outputFileName = outputFileName;
}

void FileInputOutput::readFile(std::vector<int> &arr)
{
	String^ line;
	//IO::StreamReader^ din = IO::File::OpenText(inputFileName);

	ifstream inputFile;
	inputFile.open(inputFileName);
	int number;
	while (inputFile>>number)
	{
		// If it's an integer then it will be stored to the corresponding position

		
		/*if (Int32::TryParse(line, arr[size]))
			size++;*/
		arr.push_back(number);
	}
	inputFile.close();
}

void FileInputOutput::writeFile(std::vector<int> &arr)
{
	//IO::StreamWriter ^ dout = IO::File::CreateText(m_outputFileName);
	ofstream outputFile(outputFileName);
	for (int i = 0; i < arr.size(); i++)
		outputFile << arr[i] << endl;
	outputFile.close();
}