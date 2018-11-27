/**
 * Copyright 2018 Mirco Baalmans <mircobaalmans@live.nl>
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
#include "game.h"


/// @brief main entry point
int main( void )
{
	// Core instance
	Core core;
	

	Game* game = new Game();

	while(game->isRunning()) { // check status of Scene every frame
		core.run(game); // update and render the current scene
	}

	//core.cleanup(); // cleanup ResourceManager (Textures + Meshes, but not Shaders)

	return 0;
}
