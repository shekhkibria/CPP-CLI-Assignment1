#pragma once
#include<vcclr.h>
#include<vector>
#include<string>

using namespace std;
using namespace System;

class FileInputOutput
{
	string inputFileName;
	string outputFileName;
public:
	FileInputOutput(string inputFileName, string outputFileName);

	void readFile(std::vector<int> &arr);

	void writeFile(std::vector<int> &arr);

};