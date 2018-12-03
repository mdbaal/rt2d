#include "game.h"

Game::Game(){
	setup();
}

Game::~Game(){
	this->removeChild(counter);
	delete counter;
	this->removeChild(factory);
	delete factory;
	this->removeChild(exitButton);
	delete exitButton;
	delete upgradeManager;
	//delete upgrade bars
	for (int i = 0; i < 6; i++)
	{
		this->removeChild(upgradeBars[i]);
		delete upgradeBars[i];
		upgradeBars[i] = nullptr;
	}
	upgradeBars.clear();
	// delete upgrade buttons
	for (int i = 0; i < 6; i++)
	{
		this->removeChild(upgrades[i]);
		delete upgrades[i];
		upgrades[i] = nullptr;
	}
	upgrades.clear();
}

void Game::setup() {
	counter = new Text();
	factory = new Factory();
	exitButton = new ExitButton();
	upgradeManager = new UpgradeManager();

	//factory
	factory->addSprite("assets/fabriek.tga");
	factory->position = Point(512, 256);
	factory->sprite()->color = RGBAColor(225, 255, 0, 255);
	factory->setTask(std::bind(&Game::makeHumanClick, this));
	//counter
	counter->position = Point(64, 32);
	//exit button
	exitButton->addSprite("assets/button.tga");
	exitButton->position = Point(SWIDTH - 64, SHEIGHT - 32);
	exitButton->sprite()->color = RGBAColor(0, 255, 0, 255);
	exitButton->setTask(std::bind(&Game::exit, this));

	this->addChild(factory);
	this->addChild(counter);
	this->addChild(exitButton);

	//upgrade bars
	int y = 32;
	for (int i = 0; i < 6; i++) {
		upgradeBars[i] = new UpgradeBar();
		upgradeBars[i]->position = Point(1152, y);
		upgradeBars[i]->addSprite("assets/upgrade_Bar.tga");
		this->addChild(upgradeBars[i]);
		y += 64;
	}
	//upgrade buttons
	int x = 192;
	for (int i = 0; i < 6; i++) {
		upgrades[i] = new Upgrade();
		upgrades[i]->position = Point(x, 576);
		upgrades[i]->addSprite("assets/upgrade_Button.tga");
		this->addChild(upgrades[i]);
		x += 128;
	}
}


void Game::update(float deltatime) {
	timer -= deltatime;
	if (timer < 0) {
		makeHumanSec();
		timer = 1;
	}

}

void Game::makeHumanClick() {
	
}

void Game::makeHumanSec() {
	
}
void Game::exit() {
	this->stop();
}