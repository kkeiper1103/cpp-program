/*
 * Footorial03.h
 *
 *  Created on: Feb 22, 2021
 *      Author: kkeiper1103
 */

#ifndef SRC_TUTORIALS_FOOTORIAL03_H_
#define SRC_TUTORIALS_FOOTORIAL03_H_

#include "../Footorial.h"

#include "../KeyPressSurfaces.h"

class Footorial03: public Footorial {
public:
	Footorial03();
	virtual ~Footorial03();

	virtual int run();

private:
	SDL_Window* window = nullptr;
	SDL_Surface* surface = nullptr;

	SDL_Surface* keyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];
	SDL_Surface* currentSurface = nullptr;

	void init();
	bool loadMedia();
	void close();

	SDL_Surface* loadSurface( const std::string& path );
};

#endif /* SRC_TUTORIALS_FOOTORIAL03_H_ */
