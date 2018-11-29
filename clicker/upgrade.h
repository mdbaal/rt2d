#ifndef UPGRADE_H
#define UPGRADE_H

#include "button.h"
#include <rt2d/text.h>

class Upgrade : public Button{
public:
	Upgrade();
	virtual ~Upgrade();

	virtual void update(float deltatime);

	int getCost() { return this->cost; }
	int getLevel() { return this->level; }
	int getHumans() { return this->humans; }

	void levelUp();

private:
	int cost = 0;
	int level = 0;
	int humans = 0;
	

	Text* costText = nullptr;
	Text* levelText = nullptr;
	Text* generatingText = nullptr;

	void updateText();


};

#endif //UPGRADE_H