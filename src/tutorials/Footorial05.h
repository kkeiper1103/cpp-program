/*
 * Footorial05.h
 *
 *  Created on: Feb 22, 2021
 *      Author: kkeiper1103
 */

#ifndef SRC_TUTORIALS_FOOTORIAL05_H_
#define SRC_TUTORIALS_FOOTORIAL05_H_

#include "TextureBasedFootorial.h"

class Footorial05: public TextureBasedFootorial {
public:
	Footorial05();
	virtual ~Footorial05();

	virtual void init();
	virtual void renderLogic();
	virtual void close();

private:
	SDL_Texture* image = nullptr;
};

#endif /* SRC_TUTORIALS_FOOTORIAL05_H_ */
