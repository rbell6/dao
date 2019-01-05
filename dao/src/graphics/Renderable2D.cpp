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
		
		Renderable2D::Renderable2D(Vector3 position, Vector2 size, Vector4 color)
		: mPosition(position), mSize(size), mColor(color) {
			setUVDefaults(); 
		}
	}
}
