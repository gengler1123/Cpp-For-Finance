#ifndef __READDATA_HPP__
#define __READDATA_HPP__

// For Reading the Data
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
// For Shuffling the Data
#include <algorithm>
#include <random>
// For Printing Data
#include <iostream>

class InputData
{
private:
	std::vector<std::vector<float>> data;
	int dataLength_;
protected:

public:
	InputData() { auto engine = std::default_random_engine{}; dataLength_ = 2; }
	void readData(std::string PATH);
	void shuffleData();
	void printData();
};


void InputData::printData()
{
	for (int i = 0; i < data.size(); i++)
	{
		std::cout << data[i][0];
		for (int j = 1; j < data[i].size(); j++)
		{
			std::cout << " , " << data[i][j];
		}
		std::cout << std::endl;
	}
}


void InputData::readData(std::string PATH)
{
	std::ifstream myFile(PATH);
	std::string line;
	std::string value;
	while (std::getline(myFile, line))
	{
		std::stringstream ss(line);
		std::vector<float> v;
		while (std::getline(ss, value, ","))
		{
			v.push_back(std::stof(value));
		}
		data.push_back(v);
	}
	myFile.close();
}


void InputData::shuffleData()
{
	std::shuffle(std::begin(data), std::end(data), engine);
}

#endif