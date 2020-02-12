#include "stdafx.h"
#include "FileInputOutput.h"


FileInputOutput::FileInputOutput(String^ inFileName, String^ outFileName)
{
	this->m_inputFileName = inFileName;
	this->m_outputFileName = outFileName;
}
int FileInputOutput::getNumberOfElements()
{
	return size;
}

void FileInputOutput::readFile(int arr[])
{
	String^ line;
	IO::StreamReader^ din = IO::File::OpenText(m_inputFileName);
	while ((line = din->ReadLine()) != nullptr)
		Int32::TryParse(line, arr[size++]);
	din->Close();
}

void FileInputOutput::writeFile(int arr[])
{
	IO::StreamWriter ^ dout = IO::File::CreateText(m_outputFileName);
	for (int i = 0; i < size; i++)
		dout->WriteLine(arr[i]);
	dout->Close();
}