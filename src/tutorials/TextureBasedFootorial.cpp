/*
 * TextureBasedFootorial.cpp
 *
 *  Created on: Feb 22, 2021
 *      Author: kkeiper1103
 */

#include "TextureBasedFootorial.h"

TextureBasedFootorial::TextureBasedFootorial() {
	int flags = IMG_INIT_PNG | IMG_INIT_JPG;

	if((IMG_Init(flags) & flags) != flags) {
		std::cerr << IMG_GetError() << std::endl;
	}

	SDL_CreateWindowAndRenderer(800, 600, SDL_WINDOW_SHOWN, &window, &renderer);

	SDL_SetWindowTitle(window, "Texture Based Footorial");
}

TextureBasedFootorial::~TextureBasedFootorial() {
	// TODO Auto-generated destructor stub

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	IMG_Quit();
}

int TextureBasedFootorial::run() {
	init();

	while(running) {
		handleEvents();


		SDL_RenderClear(renderer);
		renderLogic();
		SDL_RenderPresent(renderer);
	}

	close();

	return SUCCESS;
}

SDL_Texture* TextureBasedFootorial::loadTexture(const std::string &path) {
	SDL_Texture* texture = nullptr;

	SDL_Surface* surface = IMG_Load(path.c_str());
	if(surface) {
		texture = SDL_CreateTextureFromSurface(renderer, surface);

		SDL_FreeSurface(surface);
	}

	return texture;
}

void TextureBasedFootorial::handleEvents() {
	SDL_Event e;
	while(SDL_PollEvent(&e)) {
		if(e.type == SDL_QUIT) running = false;
	}
}
