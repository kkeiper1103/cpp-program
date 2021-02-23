/*
 * Footorial04.h
 *
 *  Created on: Feb 22, 2021
 *      Author: kkeiper1103
 */

#ifndef SRC_TUTORIALS_FOOTORIAL04_H_
#define SRC_TUTORIALS_FOOTORIAL04_H_

#include "../Footorial.h"

class Footorial04 : public Footorial {
public:
	Footorial04();
	virtual ~Footorial04();

	virtual int run();

	void init();
	void close();

	SDL_Surface* loadSurface( const std::string& path );

private:
	SDL_Window* window = nullptr;
	SDL_Surface* screen = nullptr;

	SDL_Surface* optimized = nullptr;
};

#endif /* SRC_TUTORIALS_FOOTORIAL04_H_ */
