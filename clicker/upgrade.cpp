#include "upgrade.h"
#include <iostream>

Upgrade::Upgrade(int c, int g) {
	this->setCost(c);
	this->_cost = c;
	this->setGenerating(g);
	costText = new Text();
	levelText = new Text();
	genText = new Text();

	costText->position = Point(-50, -50);
	levelText->position = Point(-50, 50);
	genText->position = Point(-50, 25);

	costText->scale = Point(.25, .25);
	levelText->scale = Point(.25, .25);
	genText->scale = Point(.23, .23);

	this->addChild(costText);
	this->addChild(levelText);
	this->addChild(genText);
	this->updateText();
}

Upgrade::~Upgrade() {
	this->removeChild(costText);
	this->removeChild(levelText);
	delete costText;
	delete levelText;
}

void Upgrade::levelUp() {
	if (this->_cost < 9999999) {
		_level++;
		_cost = _baseCost * (1.5 * _level);
		
		updateText();
	}
}

void Upgrade::updateText() {

	costText->message("Cost: " + std::to_string(this->_cost));
	levelText->message("Level: " + std::to_string(this->_level));
}
void Upgrade::setGenMessage(std::string genMSG) {
	this->genText->message(genMSG);
}
void Upgrade::clear() {
	_level = 0;
	_cost = _baseCost * (1.5 * _level);
	this->updateText();
}