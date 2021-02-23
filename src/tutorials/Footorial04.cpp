/*
 * Footorial04.cpp
 *
 *  Created on: Feb 22, 2021
 *      Author: kkeiper1103
 */

#include "Footorial04.h"

Footorial04::Footorial04() {
	// TODO Auto-generated constructor stub

	window = createDefaultWindow("Optimized Surfaces", 640, 480);
	screen = SDL_GetWindowSurface(window);

}

Footorial04::~Footorial04() {
	// TODO Auto-generated destructor stub
}

int Footorial04::run() {
	init();

	bool quit = false;
	SDL_Event e;

	SDL_Rect stretchRect = {
		x: 0,
		y: 0,
		w: 640,
		h: 480
	};

	while(!quit) {
		while(SDL_PollEvent(&e)) {
			if(e.type == SDL_QUIT) quit = true;
		}

		SDL_BlitScaled(optimized, nullptr, screen, &stretchRect);
		SDL_UpdateWindowSurface(window);
	}

	close();

	return SUCCESS;
}

SDL_Surface* Footorial04::loadSurface(const std::string &path) {
	SDL_Surface* surface = SDL_LoadBMP(path.c_str());

	if(surface) {
		surface = SDL_ConvertSurface(surface, screen->format, 0);
	}

	return surface;
}

void Footorial04::init() {
	optimized = loadSurface("resources/images/stretch.bmp");
}

void Footorial04::close() {
	SDL_FreeSurface(optimized);
	SDL_DestroyWindow(window);
}
