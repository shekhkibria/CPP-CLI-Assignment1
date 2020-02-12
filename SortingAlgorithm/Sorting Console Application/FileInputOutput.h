#pragma once
#include<vcclr.h>
using namespace System;
class FileInputOutput
{
	gcroot<String^> m_inputFileName;
	gcroot<String^> m_outputFileName;
	int size = 0;
public:
	FileInputOutput(String^ inFileName, String^ outFileName);

	int getNumberOfElements();

	void readFile(int arr[]);

	void writeFile(int arr[]);

};