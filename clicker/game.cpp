#include "game.h"

Game::Game(){
	counter = new Counter();
	factory = new Factory();
	exitButton = new ExitButton();
	//counter
	counter->addSprite("assets/square.tga");
	counter->position = Point(64, 64);
	counter->sprite()->color = RGBAColor(225, 0, 0, 255);
	//factory
	factory->addSprite("assets/square.tga");
	factory->position = Point(SWIDTH / 2, SHEIGHT / 2);
	factory->sprite()->color = RGBAColor(225, 255, 0, 255);
	factory->setTask(std::bind(&Game::makeHumanClick, this));
	//exit button
	exitButton->addSprite("assets/square.tga");
	exitButton->position = Point(SWIDTH-64, 64);
	exitButton->sprite()->color = RGBAColor(0, 255, 0, 255);
	exitButton->setTask(std::bind(&Game::exit, this));

	this->addChild(counter);
	this->addChild(factory);
	this->addChild(exitButton);
}

Game::~Game(){
	delete counter;
	delete factory;
	delete exitButton;

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