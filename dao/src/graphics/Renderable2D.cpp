//
//  Renderable2D.cpp
//  dao
//
//  Created by Richard Bell on 11/25/18.
//  Copyright © 2018 apocryphal. All rights reserved.
//

#include "Renderable2D.hpp"

namespace dao {
	namespace graphics {
		Renderable2D::Renderable2D() {
			{ setUVDefaults(); }
		}
		
		Renderable2D::Renderable2D(glm::vec3 position, glm::vec2 size, glm::vec4 color)
		: mPosition(position), mSize(size), mColor(color) {
			setUVDefaults(); 
		}
        
        Renderable2D::Renderable2D(glm::vec3 position, glm::vec2 size, Texture* texture): mPosition(position), mSize(size), mTexture(texture) {}
	}
}
