/*
 * Footorial.h
 *
 *  Created on: Feb 22, 2021
 *      Author: kkeiper1103
 */

#ifndef SRC_FOOTORIAL_H_
#define SRC_FOOTORIAL_H_

#include <iostream>

#include <SDL2/SDL.h>

#include "StatusCodes.h"

class Footorial {
public:
	Footorial();
	virtual ~Footorial();

	virtual int run() =0;

	inline SDL_Window* createDefaultWindow(const std::string& title, int width = 800, int height = 640) {
		return SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	}

};

#endif /* SRC_FOOTORIAL_H_ */
