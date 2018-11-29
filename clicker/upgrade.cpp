#include "upgrade.h"

Upgrade::Upgrade(){
	costText = new Text();
	levelText = new Text();
	generatingText = new Text();
}

Upgrade::~Upgrade(){
	delete costText;
	delete levelText;
	delete generatingText;

}

void Upgrade::update(float deltatime) {

}

void Upgrade::levelUp() {


}

void Upgrade::updateText() {
	costText->message("Cost: " + this->cost);
	levelText->message("Level: " + this->level);
}