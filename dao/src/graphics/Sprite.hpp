//
//  Sprite.hpp
//  dao
//
//  Created by Richard Bell on 11/26/18.
//  Copyright © 2018 apocryphal. All rights reserved.
//

#ifndef Sprite_hpp
#define Sprite_hpp
#include "Renderable2D.hpp"

namespace dao {
	namespace graphics {
		class Sprite : public Renderable2D {
		public:
			Sprite(float x, float y, float width, float height, Vector4& color);
		};
	}
}

#endif /* Sprite_hpp */
