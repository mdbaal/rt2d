#ifndef GAME_H
#define GAME_H

#include <rt2d/scene.h>
#include "factory.h"
#include "exitButton.h"
#include "counter.h"


class Game : public Scene{
public:
	Game();
	virtual ~Game();
	virtual void update(float deltatime);
	void makeCookiesClick();
	void makeCookiesSec();
	void exit();
private:
	Counter* counter = nullptr;
	Factory* factory = nullptr;
	ExitButton* exitButton = nullptr;

	int cookiesClick = 1;
	int coockiesSec = 0;

	float timer = 1;
};

#endif //GAME_H