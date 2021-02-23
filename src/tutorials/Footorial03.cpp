/*
 * Footorial03.cpp
 *
 *  Created on: Feb 22, 2021
 *      Author: kkeiper1103
 */

#include "Footorial03.h"

Footorial03::Footorial03() {
	// TODO Auto-generated constructor stub

	window = SDL_CreateWindow("Footorial 03", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
	surface = SDL_GetWindowSurface(window);
}

Footorial03::~Footorial03() {
	// TODO Auto-generated destructor stub

	SDL_DestroyWindow(window);
}

int Footorial03::run() {
	init();

	bool quit = false;

	SDL_Event e;

	currentSurface = keyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];

	while(!quit) {
		while(SDL_PollEvent(&e) != 0) {
			if(e.type == SDL_QUIT) quit = true;

			else if( e.type == SDL_KEYDOWN ) {
				switch(e.key.keysym.sym) {
				case SDLK_UP:
					currentSurface = keyPressSurfaces[KEY_PRESS_SURFACE_UP]; break;
				case SDLK_DOWN:
					currentSurface = keyPressSurfaces[KEY_PRESS_SURFACE_DOWN]; break;
				case SDLK_LEFT:
					currentSurface = keyPressSurfaces[KEY_PRESS_SURFACE_LEFT]; break;
				case SDLK_RIGHT:
					currentSurface = keyPressSurfaces[KEY_PRESS_SURFACE_RIGHT]; break;
				default:
					currentSurface = keyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT]; break;
				}
			}
		}

		SDL_BlitSurface(currentSurface, nullptr, surface, nullptr);
		SDL_UpdateWindowSurface(window);
	}

	close();

	return SUCCESS;
}

void Footorial03::init() {

	loadMedia();
}

bool Footorial03::loadMedia() {
	bool success = true;

	// load default
	keyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] = loadSurface("resources/images/press.bmp");
	keyPressSurfaces[KEY_PRESS_SURFACE_UP] = loadSurface("resources/images/up.bmp");
	keyPressSurfaces[KEY_PRESS_SURFACE_DOWN] = loadSurface("resources/images/down.bmp");
	keyPressSurfaces[KEY_PRESS_SURFACE_LEFT] = loadSurface("resources/images/left.bmp");
	keyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] = loadSurface("resources/images/right.bmp");


	return success;
}

void Footorial03::close() {

	for(unsigned i=0; i < sizeof(keyPressSurfaces) / sizeof(SDL_Surface*); ++i) {
		SDL_FreeSurface(keyPressSurfaces[i]);
	}
}

SDL_Surface* Footorial03::loadSurface(const std::string &path) {
	SDL_Surface* surface = SDL_LoadBMP(path.c_str());
	if(surface == nullptr)
		std::cerr << "Error Loading Image: " << path.c_str() << '\t' << SDL_GetError() << std::endl;

	return surface;
}
