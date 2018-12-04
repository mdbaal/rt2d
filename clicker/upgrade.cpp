#include "upgrade.h"
#include <iostream>

Upgrade::Upgrade(int c,int g){
	this->setCost(c);
	this->setGenerating(g);


	costText = new Text();
	levelText = new Text();

	costText->position = Point(-50, -50);
	levelText->position = Point(-50, 50);

	costText->scale = Point(.3, .3);
	levelText->scale = Point(.3, .3);

	this->addChild(costText);
	this->addChild(levelText);
	this->updateText();
}

Upgrade::~Upgrade(){
	this->removeChild(costText);
	this->removeChild(levelText);
	delete costText;
	delete levelText;
}

void Upgrade::levelUp() {
		_level++;
		_cost +=  _level * _cost;
		updateText();
}

void Upgrade::updateText() {
	costText->message("Cost: " + std::to_string(this->_cost));
	levelText->message("Level: " + std::to_string(this->_level));
}