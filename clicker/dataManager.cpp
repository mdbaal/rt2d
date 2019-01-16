#include "dataManager.h"

DataManager::DataManager(){

}

DataManager::~DataManager(){


}

std::vector<int> DataManager::readData() {
	std::vector<int> data = std::vector<int>();
	
		std::ifstream f;
		std::string str;
		
		f.open("saveData/data.txt");
		while (std::getline(f, str)) {
			data.push_back(std::stoi(str));
		}
		f.close();
	
	return data;
}

void DataManager::writeData(std::vector<int> data) {
	fileExist = true;
	std::ofstream f;
	f.open("saveData/data.txt", std::ofstream::trunc);

	for (int i = 0; i < data.size(); i++) {
		f << data[i] << std::endl;
	}

	f.close();
}
