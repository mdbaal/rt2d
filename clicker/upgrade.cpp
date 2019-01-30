#include "upgrade.h"
#include <iostream>

Upgrade::Upgrade(int c, int g) {
	this->setCost(c);
	this->_cost = c;
	this->setGenerating(g);
	costText = new Text();
	costNumber = new Text();
	levelText = new Text();
	levelNumber = new Text();
	genText = new Text();

	costText->position = Point(-50, -50);
	costNumber->position = Point(-50, -35);
	levelText->position = Point(-50, 35);
	levelNumber->position = Point(-50, 50);
	genText->position = Point(-50, 0);

	costText->scale = Point(.25, .25);
	costNumber->scale = Point(.25, .25);
	levelText->scale = Point(.25, .25);
	levelNumber->scale = Point(.25, .25);
	genText->scale = Point(.23, .23);

	costText->message("Cost: ");
	levelText->message("Level: ");

	this->addChild(costText);
	this->addChild(costNumber);
	this->addChild(levelText);
	this->addChild(levelNumber);
	this->addChild(genText);

	this->updateText();
}

Upgrade::~Upgrade() {
	this->removeChild(costText);
	this->removeChild(levelText);
	delete costText;
	delete costNumber;
	delete levelText;
}

void Upgrade::levelUp() {
	_level++;
	calculateCost();
	updateText();
}
void Upgrade::calculateCost() {
	if (_level == 0) {
		_cost = _baseCost;
		return;
	}
	_cost = _baseCost * (1.5 * _level);
}

void Upgrade::updateText() {

	costNumber->message(std::to_string(this->_cost));
	levelNumber->message(std::to_string(this->_level));
}
void Upgrade::setGenMessage(std::string genMSG) {
	this->genText->message(genMSG);
}
void Upgrade::clear() {
	_level = 0;
	calculateCost();
	updateText();
}