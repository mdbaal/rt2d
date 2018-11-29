#ifndef GAME_H
#define GAME_H

#include <rt2d/scene.h>
#include "factory.h"
#include "exitButton.h"
#include "counter.h"
#include "upgradeManager.h"



class Game : public Scene{
public:
	Game();
	virtual ~Game();
	virtual void update(float deltatime);
	void makeHumanClick();
	void makeHumanSec();
	void exit();
private:
	Counter* counter = nullptr;
	Factory* factory = nullptr;
	ExitButton* exitButton = nullptr;
	UpgradeManager* upgradeManager = nullptr;

	int humanClick = 1;
	int humanSec = 0;

	float timer = 1;
};

#endif //GAME_H