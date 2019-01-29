#ifndef UPGRADE_H
#define UPGRADE_H

#include "button.h"
#include <rt2d/text.h>

class Upgrade : public Button{
public:
	Upgrade(int cost, int g);
	virtual ~Upgrade();

	int getCost() { return this->_cost; }
	int getLevel() { return this->_level; }
	void setLevel(int l) { this->_level = l; }
	int getGenerating() { return this->_generating*_level; }
	

	void setCost(int i) { _baseCost = i; }
	void setGenerating(int i) { _generating = i; }
	
	void setGenMessage(std::string genMSG);

	void levelUp();
	void updateText();
	void clear();
private:
	unsigned int _cost = 0;
	int _baseCost = 0;
	unsigned int _level = 0;
	unsigned int _generating = 0;
	
	

	Text* costText = nullptr;
	Text* levelText = nullptr;
	Text* genText = nullptr;
	

	


};

#endif //UPGRADE_H