/*
 * Footorial02.h
 *
 *  Created on: Feb 22, 2021
 *      Author: kkeiper1103
 */

#ifndef SRC_TUTORIALS_FOOTORIAL02_H_
#define SRC_TUTORIALS_FOOTORIAL02_H_

#include "../Footorial.h"

class Footorial02: public Footorial {
public:
	Footorial02();
	virtual ~Footorial02();

	virtual int run();

private:
	SDL_Window* gWindow = nullptr;
	SDL_Surface* gScreenSurface = nullptr;
	SDL_Surface* gXOut = nullptr;

	int init();
};

#endif /* SRC_TUTORIALS_FOOTORIAL02_H_ */
