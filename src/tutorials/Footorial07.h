/*
 * Footorial07.h
 *
 *  Created on: Feb 23, 2021
 *      Author: kkeiper1103
 */

#ifndef SRC_TUTORIALS_FOOTORIAL07_H_
#define SRC_TUTORIALS_FOOTORIAL07_H_

#include "TextureBasedFootorial.h"

#include <SDL2/SDL_thread.h>
#include <iostream>
#include <string>

struct PersonInfo {
	std::string first_name;
	std::string last_name;
	std::string email;
	std::string phone;

	int age;
};

class Footorial07: public TextureBasedFootorial {
public:
	Footorial07();
	virtual ~Footorial07();

	virtual void init();
	virtual void renderLogic();
	virtual void close();

private:
	SDL_Thread* theThread = nullptr;

	// we have to declare the PersonInfo somewhere where it will persist beyond the init call (or use calloc/malloc. yuck)
	PersonInfo user;
};


int printUserInfo( void* data );

#endif /* SRC_TUTORIALS_FOOTORIAL07_H_ */
