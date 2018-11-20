#pragma once

#include <rt2d/scene.h>
#include "button.h"

class TestScene : public Scene {
public:
	TestScene();
	virtual ~TestScene();

	virtual void update(float deltatime);

	Button* b;
	void printHello();
};