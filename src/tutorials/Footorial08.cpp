/*
 * Footorial08.cpp
 *
 *  Created on: Feb 23, 2021
 *      Author: kkeiper1103
 */

#include "Footorial08.h"

Footorial08::Footorial08() {
	// TODO Auto-generated constructor stub

}

Footorial08::~Footorial08() {
	// TODO Auto-generated destructor stub
}

int Footorial08::run() {
	init();

	SDL_Event e;
	while(running) {
		handleEvents(&e);

		update();
		render();
	}

	close();

	return SUCCESS;
}

void Footorial08::init() {
	window = SDL_CreateWindow("OpenGL Example", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN|SDL_WINDOW_OPENGL);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);


	context = SDL_GL_CreateContext(window);
	SDL_GL_SetSwapInterval(1);

	//
	GLenum error = GL_NO_ERROR;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClearColor(0.f, 0.f, 0.f, 1.f);
}

void Footorial08::close() {
	SDL_DestroyWindow(window);
}

void Footorial08::handleEvents(SDL_Event *e) {
	while(SDL_PollEvent(e)) {
		if(e->type == SDL_QUIT) running = false;
	}
}

void Footorial08::update() {
	++angleOfRotation;

	if(angleOfRotation == 360) angleOfRotation = 0;
}

void Footorial08::render() {
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );


	glColor3f(color.r, color.g, color.b);


	glBegin(GL_QUADS);
	glVertex2f(quad[0].x, quad[0].y);
	glVertex2f(quad[1].x, quad[1].y);
	glVertex2f(quad[2].x, quad[2].y);
	glVertex2f(quad[3].x, quad[3].y);
	glEnd();


	SDL_GL_SwapWindow(window);
}
