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
		Sprite::Sprite(float x, float y, float width, float height, Vector4 color)
		: Renderable2D(Vector3(x, y, 0), Vector2(width, height), color) {}
        
        Sprite::Sprite(Vector3 position, Vector2 size, Vector4 color): Renderable2D(position, size, color) {}
		
		Sprite::Sprite(float x, float y, float width, float height, Texture* texture)
		: Renderable2D(Vector3(x, y, 0), Vector2(width, height), Vector4(1, 0, 1, 1)) {
			mTexture = texture;
		}
        
        Sprite::Sprite(Vector3 position, Vector2 size, Texture* texture): Renderable2D(position, size, texture) {}
	}
}
