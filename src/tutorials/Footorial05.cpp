/*
 * Footorial05.cpp
 *
 *  Created on: Feb 22, 2021
 *      Author: kkeiper1103
 */

#include "Footorial05.h"

Footorial05::Footorial05() {
	// TODO Auto-generated constructor stub

}

Footorial05::~Footorial05() {
	// TODO Auto-generated destructor stub
}

void Footorial05::init() {
	image = loadTexture("resources/images/texture.png");
}

void Footorial05::renderLogic() {
	SDL_RenderCopy(renderer, image, nullptr, nullptr);
}

void Footorial05::close() {
	SDL_DestroyTexture(image);
}
