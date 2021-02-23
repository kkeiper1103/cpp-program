/*
 * Footorial01.cpp
 *
 *  Created on: Feb 22, 2021
 *      Author: kkeiper1103
 */

#include "Footorial01.h"

Footorial01::Footorial01() {
	// TODO Auto-generated constructor stub

}

Footorial01::~Footorial01() {
	// TODO Auto-generated destructor stub
}


int Footorial01::run() {
	std::cout << "Loading Footorial 1" << std::endl;

	if( ! init() ) {
		std::cerr << "Failed to initialize" << std::endl;
		return StatusCodes::FAILURE;
	}

	if( ! loadMedia() ) {
		std::cerr << "Failed to Load Media" << std::endl;
		return StatusCodes::FAILURE;
	}

	SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);
	SDL_UpdateWindowSurface( gWindow );
	SDL_Delay( 2000 );

	close();

	return StatusCodes::SUCCESS;
}

bool Footorial01::init() {
	bool success = true;

	gWindow = SDL_CreateWindow("SDL Tutorial 01", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if(gWindow == nullptr) {
		std::cerr << "SDL Error: " << SDL_GetError() << std::endl;
		success = false;
	}
	else {
		gScreenSurface = SDL_GetWindowSurface( gWindow );
	}

	return success;
}

bool Footorial01::loadMedia() {
	bool success = true;

	gHelloWorld = SDL_LoadBMP("resources/images/hello_world.bmp");
	if(gHelloWorld == nullptr) {
		success = false;
		std::cerr << "Error: " << SDL_GetError() << std::endl;
	}

	return success;
}

void Footorial01::close() {
	SDL_FreeSurface(gHelloWorld);
	SDL_DestroyWindow(gWindow);
}
