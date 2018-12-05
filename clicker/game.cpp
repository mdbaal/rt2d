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

	//factory
	factory->addSprite("assets/fabriek.tga");
	factory->position = Point(512, 256);
	factory->sprite()->color = RGBAColor(225, 255, 0, 255);
	factory->setTask(std::bind(&Game::makeHumanClick, this));
	//counter
	counter->position = Point(32, 32);
	counter->scale = Point(.5,.5);
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
	//cost
	std::vector<int> c = std::vector<int>();
	c.push_back(5);
	c.push_back(100);
	c.push_back(500);
	c.push_back(1000);
	c.push_back(5000);
	c.push_back(10000);
	//generating
	std::vector<int> g = std::vector<int>();
	g.push_back(1);
	g.push_back(5);
	g.push_back(20);
	g.push_back(50);
	g.push_back(100);
	g.push_back(500);

	for (int i = 0; i < 6; i++) {
		upgrades[i] = new Upgrade(c[i], g[i]);
		upgrades[i]->position = Point(x, 576);
		upgrades[i]->addSprite("assets/upgrade_Button.tga");
		upgrades[i]->setTaskI(std::bind(&Game::buyUpgrade, this,std::placeholders::_1),i);
		this->addChild(upgrades[i]);
		x += 128;
	}

	upgrades[0]->setGenMessage("Per click +1");
	upgrades[1]->setGenMessage("Per click +5");
	upgrades[2]->setGenMessage("Per second +20");
	upgrades[3]->setGenMessage("Per second +50");
	upgrades[4]->setGenMessage("Per second +100");
	upgrades[5]->setGenMessage("Per second +500");
}


void Game::update(float deltatime) {
	timer -= deltatime;
	if (timer < 0) {
		makeHumanSec();
		timer = 1;
	}

}
void Game::updateGenerating() {
	int click = 0;
	int sec = 0;
	//update firt 2 for click
	if(upgrades[0]->GetLevel()  >0) click = upgrades[0]->getGenerating();
	if (upgrades[1]->GetLevel() > 0)click += upgrades[1]->getGenerating();
	//update the rest for sec
	for (int i = 2; i < 6; i++) {
		if (upgrades[i]->GetLevel() > 0) sec += upgrades[i]->getGenerating();
	}

	humanClick = click;
	humanSec = sec;
}

void Game::buyUpgrade(int u) {
	if (this->getHumans() - this->upgrades[u]->GetCost() >= 0) {
		this->humans -= this->upgrades[u]->GetCost();
		counter->message("Humans: " + std::to_string(humans));
		this->upgrades[u]->levelUp();
		this->updateGenerating();
	}
}

void Game::makeHumanClick() {
	humans += humanClick;
	counter->message("Humans: " + std::to_string(humans));
}

void Game::makeHumanSec() {
	humans += humanSec;
	counter->message("Humans: " + std::to_string(humans));
}
void Game::exit() {
	this->stop();
}