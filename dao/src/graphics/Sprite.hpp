//
//  Sprite.hpp
//  dao
//
//  Created by Richard Bell on 11/26/18.
//  Copyright © 2018 apocryphal. All rights reserved.
//

#ifndef Sprite_hpp
#define Sprite_hpp
#include <glm/glm.hpp>
#include "Renderable2D.hpp"
#include "Texture.hpp"

namespace dao {
	namespace graphics {
		class Sprite : public Renderable2D {
		public:
			Sprite(float x, float y, float width, float height, glm::vec4 color);
			Sprite(float x, float y, float width, float height, Texture* texture);
		};
	}
}

#endif /* Sprite_hpp */
