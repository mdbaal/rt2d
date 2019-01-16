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
	exitButton = new Button();
	credits = new Credits();
	resetButton = new Button();

	dataManager = new DataManager();

	//factory
	factory->addSprite("assets/fabriek.tga");
	factory->position = Point(512, 256);
	factory->sprite()->color = RGBAColor(225, 255, 0, 255);
	factory->setTask(std::bind(&Game::makeHumanClick, this));
	//counter
	counter->position = Point(32, 32);
	counter->scale = Point(.5,.5);
	//exit button
	exitButton->addSprite("assets/exit_Button.tga");
	exitButton->position = Point(SWIDTH-64, 672);
	exitButton->setTask(std::bind(&Game::exit, this));
	//credits
	credits->addSprite("assets/credits.tga");
	credits->position = Point(1152, 512);
	//reset button
	resetButton->addSprite("assets/reset_Button.tga");
	resetButton->position = Point(SWIDTH-192, 672);
	resetButton->setTask(std::bind(&Game::reset, this));

	this->addChild(factory);
	this->addChild(counter);
	this->addChild(exitButton);
	this->addChild(credits);
	this->addChild(resetButton);

	//upgrade bars
	int y = 32;
	for (int i = 0; i < 6; i++) {
		upgradeBars[i] = new UpgradeBar("assets/mini_Upgrade_Image.tga");
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

	load();
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
	if(upgrades[0]->getLevel()  >0) click = upgrades[0]->getGenerating();
	if (upgrades[1]->getLevel() > 0)click += upgrades[1]->getGenerating();
	//update the rest for sec
	for (int i = 2; i < 6; i++) {
		if (upgrades[i]->getLevel() > 0) sec += upgrades[i]->getGenerating();
	}

	humanClick = click;
	humanSec = sec;
}

void Game::buyUpgrade(int u) {
	if (this->getHumans() - this->upgrades[u]->getCost() >= 0) {
		this->humans -= this->upgrades[u]->getCost();
		counter->message("Humans: " + std::to_string(humans));
		this->upgrades[u]->levelUp();
		this->upgradeBars[u]->addMini();
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
	save();
	this->stop();
}

void Game::save() {
	std::cout << "saving" << std::endl;
	std::vector<int> _data = std::vector<int>();
	for (int i = 0; i < 6; i++) {
		std::cout << "saving upgrade: " << i +1<< " with level: " << upgrades[i]->getLevel() << std::endl;
		_data.push_back(upgrades[i]->getLevel());
	}

	_data.push_back(getHumans());
	std::cout << "saving humans: " << getHumans();
	dataManager->writeData(_data);
}
void Game::load() {
	std::cout << "loading" << std::endl;
	std::vector<int> _data = dataManager->readData();
	if (_data.size() < 1) { return; }
	for (int i = 0; i < _data.size()-1; i++) {
		std::cout << "getting upgrade: " << i +1 << " with level: " << _data[i] << std::endl;
		upgrades[i]->setLevel(_data[i]);
		upgrades[i]->updateText();
	}
	std::cout << "loading humans: " << _data[_data.size()-1];
	this->humans = _data[_data.size()-1];
}
void Game::reset() {
	std::cout << "reset" << std::endl;
	std::vector<int> _data = std::vector<int>();
	for (int i = 0; i < 7; i++) {
		_data.push_back(0);
	}
	dataManager->writeData(_data);
	load();
}