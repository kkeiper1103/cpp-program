/*
 * Footorial06.cpp
 *
 *  Created on: Feb 22, 2021
 *      Author: kkeiper1103
 */

#include "Footorial06.h"

Footorial06::Footorial06() {
	// TODO Auto-generated constructor stub

}

Footorial06::~Footorial06() {
	// TODO Auto-generated destructor stub
}

void Footorial06::init() {
	image = loadTexture("resources/images/viewport.png");

	SDL_GetWindowSize(window, &screen_width, &screen_height);
}

void Footorial06::renderLogic() {
	SDL_Rect topLeftViewport = {
		0, 0, screen_width / 2, screen_height / 2
	};
	SDL_RenderSetViewport(renderer, &topLeftViewport);
	SDL_RenderCopy(renderer, image, nullptr, nullptr);


	SDL_Rect topRightViewport = {
		screen_width / 2, 0,
		screen_width / 2, screen_height / 2
	};
	SDL_RenderSetViewport(renderer, &topRightViewport);
	SDL_RenderCopy(renderer, image, nullptr, nullptr);


	SDL_Rect bottomViewport = {
		0, screen_height / 2,
		screen_width, screen_height / 2
	};
	SDL_RenderSetViewport(renderer, &bottomViewport);
	SDL_RenderCopy(renderer, image, nullptr, nullptr);
}

void Footorial06::close() {
	SDL_DestroyTexture(image);
}
