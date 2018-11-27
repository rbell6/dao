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
		Sprite::Sprite(float x, float y, float width, float height, Vector4& color)
		: Renderable2D(Vector3(x, y, 0), Vector2(width, height), color) {}
	}
}
