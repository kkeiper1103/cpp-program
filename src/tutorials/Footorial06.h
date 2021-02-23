/*
 * Footorial06.h
 *
 *  Created on: Feb 22, 2021
 *      Author: kkeiper1103
 */

#ifndef SRC_TUTORIALS_FOOTORIAL06_H_
#define SRC_TUTORIALS_FOOTORIAL06_H_

#include "TextureBasedFootorial.h"

class Footorial06: public TextureBasedFootorial {
public:
	Footorial06();
	virtual ~Footorial06();

	virtual void init();
	virtual void renderLogic();
	virtual void close();

private:
	SDL_Texture* image = nullptr;

	int screen_width,
		screen_height;
};

#endif /* SRC_TUTORIALS_FOOTORIAL06_H_ */
