#include "game.h"

Game::Game(){
	counter = new Counter();
	factory = new Factory();
	exitButton = new ExitButton();
	upgradeManager = new UpgradeManager();

	//upgrade manager
	upgradeManager->position = Point(128, 576);

	//factory
	factory->addSprite("assets/fabriek.tga");
	factory->position = Point(512, 256);
	factory->sprite()->color = RGBAColor(225, 255, 0, 255);
	factory->setTask(std::bind(&Game::makeHumanClick, this));
	//counter
	counter->position = Point(64, 32);
	//exit button
	exitButton->addSprite("assets/button.tga");
	exitButton->position = Point(SWIDTH-64, SHEIGHT-32);
	exitButton->sprite()->color = RGBAColor(0, 255, 0, 255);
	exitButton->setTask(std::bind(&Game::exit, this));

	
	this->addChild(factory);
	this->addChild(counter);
	this->addChild(exitButton);
	this->addChild(upgradeManager);
}

Game::~Game(){
	delete counter;
	delete factory;
	delete exitButton;
	delete upgradeManager;
}


void Game::update(float deltatime) {
	timer -= deltatime;
	if (timer < 0) {
		makeHumanSec();
		timer = 1;
	}

}

void Game::makeHumanClick() {
	counter->upHumans(humanClick);
}

void Game::makeHumanSec() {
	counter->upHumans(humanSec);
}
void Game::exit() {
	this->stop();
}