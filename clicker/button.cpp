#include "button.h"

Button::Button() {

}

Button::~Button() {

}

void Button::update(float deltatime) {
	if (onClick()) {
		if(task != nullptr) task();
		if (taskI != nullptr) taskI(id);
		animateClickDown();
	}
	if (input()->getMouseUp(0)) animateClickUp();
	
}

//on mouse over event
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
//set task
void Button::setTask(std::function<void()> _task) {
	this->task = _task;
}
//set taskI
void Button::setTaskI(std::function<void(int)> _taskI,int id) {
	this->taskI = _taskI;
	this->id = id;
}
//enlarge when clicked
void Button::animateClickDown() {
	this->scale = Point(1 - 5 /this->sprite()->size.x, 1 - 5 / this->sprite()->size.y);
}
//shrink when not clicked
void Button::animateClickUp() {
	this->scale = Point(1, 1);	
}