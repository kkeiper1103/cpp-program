/*
 * Footorial08.h
 *
 *  Created on: Feb 23, 2021
 *      Author: kkeiper1103
 */

#ifndef SRC_TUTORIALS_FOOTORIAL08_H_
#define SRC_TUTORIALS_FOOTORIAL08_H_

#include "../Footorial.h"

#include <SDL2/SDL_opengl.h>
#include <GL/glu.h>

#include <vector>

struct GL_Color {
	float r;
	float g;
	float b;
	float a;
};

struct GL_Point {
	float x;
	float y;
};

class Footorial08: public Footorial {
public:
	Footorial08();
	virtual ~Footorial08();

	virtual int run();

private:
	void init();
	void close();

	void handleEvents(SDL_Event* e);
	void update();
	void render();

	bool running = true;
	SDL_Window* window = nullptr;
	SDL_GLContext context;

	std::vector<GL_Point> quad = {
		{-.5f, -.5f}, {.5f, -.5f}, {.5f, .5f}, {-.5f, .5f}
	};
	GL_Color color = { .8f, 0.f, .3f, 1.f };
	uint8_t angleOfRotation = 0;
};

#endif /* SRC_TUTORIALS_FOOTORIAL08_H_ */
