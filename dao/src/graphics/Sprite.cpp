//
//  Sprite.cpp
//  dao
//
//  Created by Richard Bell on 11/26/18.
//  Copyright © 2018 apocryphal. All rights reserved.
//

#include "Sprite.hpp"

namespace dao {
	namespace graphics {
		Sprite::Sprite(float x, float y, float width, float height, glm::vec4 color)
		: Renderable2D(glm::vec3(x, y, 0), glm::vec2(width, height), color) {}
        
        Sprite::Sprite(glm::vec3 position, glm::vec2 size, glm::vec4 color): Renderable2D(position, size, color) {}
		
		Sprite::Sprite(float x, float y, float width, float height, Texture* texture)
		: Renderable2D(glm::vec3(x, y, 0), glm::vec2(width, height), glm::vec4(1, 0, 1, 1)) {
			mTexture = texture;
		}
        
        Sprite::Sprite(glm::vec3 position, glm::vec2 size, Texture* texture): Renderable2D(position, size, texture) {}
	}
}
