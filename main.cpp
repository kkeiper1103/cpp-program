/*
 * main.cpp
 *
 *  Created on: Feb 22, 2021
 *      Author: kkeiper1103
 */

#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include <SDL2/SDL.h>

#include "src/StatusCodes.h"
#include "src/Footorial.h"

#include "src/tutorials/index.h"

// sdl2main expects this signature. Can't use `int main()`
int main(int argc, char* argv[]) {

	int userChoice;
	std::vector<std::string> choices = {
		"Loading a Bitmap",
		"Handling Events",
		"Loading Multiple Surfaces",
		"Optimizing Surfaces",
		"Loading a PNG via SDL_image",
		"Using Viewports",
		"Multithreading",
		"OpenGL Quads"
	};

	for(int i=0; i < choices.size(); ++i) {
		std::cout << (i + 1) << ": " << choices.at(i) << std::endl;
	}

	std::cout << "Choice: ";
	std::cin >> userChoice;

	std::unique_ptr<Footorial> tutorial;

	switch(userChoice) {
	case 1:
		tutorial = std::make_unique<Footorial01>();
		break;
	case 2:
		tutorial = std::make_unique<Footorial02>();
		break;
	case 3:
		tutorial = std::make_unique<Footorial03>();
		break;
	case 4:
		tutorial = std::make_unique<Footorial04>();
		break;
	case 5:
		tutorial = std::make_unique<Footorial05>();
		break;
	case 6:
		tutorial = std::make_unique<Footorial06>();
		break;
	case 7:
		tutorial = std::make_unique<Footorial07>();
		break;
	case 8:
		tutorial = std::make_unique<Footorial08>();
		break;
	}

	return tutorial->run();
}
