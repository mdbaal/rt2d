#include "counter.h"

Counter::Counter() {
	counterText = new Text();
	counterText->scale = Point(.5, .5);
	this->addChild(counterText);
}

Counter::~Counter(){

	this->removeChild(counterText);
	delete counterText;
}

void Counter::update(float deltatime) {
	
}

void Counter::upHumans(int i) {
	this->humans += i;
	this->counterText->message(std::to_string(this->humans));
}
