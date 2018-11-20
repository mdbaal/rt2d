/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @brief Description of My Awesome Game.
 *
 * @file main.cpp
 *
 * @mainpage My Awesome Game
 *
 * @section intro Introduction
 *
 * Detailed description of My Awesome Game.
 *
 * There's even a second paragraph.
 */
#include <rt2d/core.h>
#include "TestScene.h"


/// @brief main entry point
int main( void )
{
	// Core instance
	Core core;

	TestScene* s = new TestScene();

	while(s->isRunning()) { // check status of Scene every frame
		core.run(s); // update and render the current scene
	}

	//core.cleanup(); // cleanup ResourceManager (Textures + Meshes, but not Shaders)

	return 0;
}
