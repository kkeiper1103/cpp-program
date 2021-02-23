/*
 * Footorial02.cpp
 *
 *  Created on: Feb 22, 2021
 *      Author: kkeiper1103
 */

#include "Footorial02.h"

Footorial02::Footorial02() {
	// TODO Auto-generated constructor stub

}

Footorial02::~Footorial02() {
	// TODO Auto-generated destructor stub

	if( gXOut ) {
		SDL_FreeSurface( gXOut );
	}

	if( gWindow ) {
		SDL_DestroyWindow( gWindow );
	}
}


int Footorial02::run() {
	init();

	bool quit = false;

	SDL_Event e;
	while( !quit ) {

		while( SDL_PollEvent(&e) != 0) {
			if(e.type == SDL_QUIT) quit = true;
		}

		SDL_BlitSurface( gXOut, NULL, gScreenSurface, NULL );
		SDL_UpdateWindowSurface( gWindow );
	}


	return StatusCodes::SUCCESS;
}


int Footorial02::init() {
	gWindow = SDL_CreateWindow("Footorial 02", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);

	gScreenSurface = SDL_GetWindowSurface(gWindow);

	gXOut = SDL_LoadBMP("resources/images/x.bmp");

	return StatusCodes::SUCCESS;
}
