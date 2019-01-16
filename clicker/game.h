#ifndef GAME_H
#define GAME_H

#include <rt2d/scene.h>
#include <rt2d/text.h>
#include "dataManager.h"
#include "factory.h"
#include "credits.h"
#include "upgrade.h"
#include "upgradeBar.h"


class Game : public Scene{
public:
	Game();
	virtual ~Game();
	virtual void update(float deltatime);
	void makeHumanClick();
	void makeHumanSec();
	int getHumans() { return this->humans;}

	void buyUpgrade(int u);

	void setup();
	void exit();
	void reset();
private:
	Text* counter = nullptr;
	Factory* factory = nullptr;
	Button* exitButton = nullptr;
	Credits* credits = nullptr;
	Button* resetButton = nullptr;
	
	DataManager* dataManager = nullptr;

	void save();
	void load();

	void updateGenerating();

	std::vector<UpgradeBar*> upgradeBars = std::vector<UpgradeBar*>(6);
	std::vector<Upgrade*> upgrades = std::vector<Upgrade*>(6);

	unsigned int humans = 0;
	int humanClick = 1;
	int humanSec = 0;

	float timer = 1;
};

#endif //GAME_H