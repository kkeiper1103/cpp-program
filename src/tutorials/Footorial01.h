/*
 * Footorial01.h
 *
 *  Created on: Feb 22, 2021
 *      Author: kkeiper1103
 */

#ifndef SRC_TUTORIALS_FOOTORIAL01_H_
#define SRC_TUTORIALS_FOOTORIAL01_H_

#include "../Footorial.h"

class Footorial01 : public Footorial {
public:
	Footorial01();
	virtual ~Footorial01();

	virtual int run();

	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 640;

private:
	bool init();
	bool loadMedia();
	void close();

	SDL_Window* gWindow = nullptr;
	SDL_Surface* gScreenSurface = nullptr;
	SDL_Surface* gHelloWorld = nullptr;
};

#endif /* SRC_TUTORIALS_FOOTORIAL01_H_ */
