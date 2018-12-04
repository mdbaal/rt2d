#ifndef GAME_H
#define GAME_H

#include <rt2d/scene.h>
#include <rt2d/text.h>
#include "factory.h"
#include "exitButton.h"
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
	void setup();
	void exit();
private:
	Text* counter = nullptr;
	Factory* factory = nullptr;
	ExitButton* exitButton = nullptr;

	std::vector<UpgradeBar*> upgradeBars = std::vector<UpgradeBar*>(6);
	std::vector<Upgrade*> upgrades = std::vector<Upgrade*>(6);

	int humans = 0;
	int humanClick = 1;
	int humanSec = 0;

	float timer = 1;
};

#endif //GAME_H