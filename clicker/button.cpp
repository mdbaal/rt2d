#include "button.h"

Button::Button() {

}
//give sprite to button and give task to excecute on click
Button::Button(std::string sprite, std::function<void()> task) {
	this->addSprite(sprite);
	this->task = task;
}

Button::~Button() {

}

void Button::update(float deltatime) {
	if (onClick()) {
		task();
	}
}

//on moouse over event
bool Button::onMouseOver() {
	if (input()->getMouseY() > (this->position.y - this->sprite()->size.y / 2) && input()->getMouseY() < this->position.y + this->sprite()->size.y / 2) {
		if (input()->getMouseX() > (this->position.x - this->sprite()->size.x / 2) && input()->getMouseX() < this->position.x + this->sprite()->size.x / 2) {
			return true;
		}
	}
	return false;
}
//on click event
bool Button::onClick() {
	if (input()->getMouseDown(0)) {
		if (onMouseOver()) return true;
	}
	return false;
}