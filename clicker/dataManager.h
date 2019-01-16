#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include "dataManager.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>

class DataManager{
public:
	DataManager();
	virtual ~DataManager();
	std::vector<int> readData();
	void writeData(std::vector<int> data);

private:
	bool fileExist = false;
};

#endif //DATAMANAGER_H