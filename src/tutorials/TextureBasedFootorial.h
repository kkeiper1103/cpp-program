/*
 * TextureBasedFootorial.h
 *
 *  Created on: Feb 22, 2021
 *      Author: kkeiper1103
 */

#ifndef SRC_TUTORIALS_TEXTUREBASEDFOOTORIAL_H_
#define SRC_TUTORIALS_TEXTUREBASEDFOOTORIAL_H_

#include "../Footorial.h"

#include <SDL2/SDL_image.h>

class TextureBasedFootorial: public Footorial {
public:
	TextureBasedFootorial();
	virtual ~TextureBasedFootorial();

	virtual int run();

	virtual void init() = 0;
	virtual void close() = 0;
	virtual void renderLogic() = 0;

	SDL_Texture* loadTexture( const std::string& path );

protected:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	bool running = true;


	// this means derived classes can define handleEvents(), but not call TextureBasedFootorial::handleEvents() before doing their own thing
	virtual void handleEvents();
};

#endif /* SRC_TUTORIALS_TEXTUREBASEDFOOTORIAL_H_ */
