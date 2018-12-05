#include "exitButton.h"

ExitButton::ExitButton(){
	text = new Text();
	this->addChild(text);
	text->message("Exit");
	text->scale = Point(.5,.5);
	text->position = Point(-25, 0);
}

ExitButton::~ExitButton(){
	this->removeChild(text);
	delete text;

}