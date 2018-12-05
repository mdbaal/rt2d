#ifndef EXITBUTTON_H
#define EXITBUTTON_H

#include "button.h"
#include <rt2d/text.h>

class ExitButton : public Button{
public:
	ExitButton();
	virtual ~ExitButton();
private:
	Text* text = nullptr;
};

#endif //EXITBUTTON_H