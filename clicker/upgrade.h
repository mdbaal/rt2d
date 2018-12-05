#ifndef UPGRADE_H
#define UPGRADE_H

#include "button.h"
#include <rt2d/text.h>

class Upgrade : public Button{
public:
	Upgrade(int cost, int g);
	virtual ~Upgrade();

	int GetCost() { return this->_cost; }
	int GetLevel() { return this->_level; }
	int getGenerating() { return this->_generating*_level; }
	

	void setCost(int i) { _cost = i; }
	void setGenerating(int i) { _generating = i; }
	
	void setGenMessage(std::string genMSG);

	void levelUp();

private:
	unsigned int _cost = 0;
	unsigned int _level = 0;
	unsigned int _generating = 0;
	
	

	Text* costText = nullptr;
	Text* levelText = nullptr;
	Text* genText = nullptr;
	

	void updateText();


};

#endif //UPGRADE_H