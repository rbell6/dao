//
//  Renderable2D.hpp
//  dao
//
//  Created by Richard Bell on 11/25/18.
//  Copyright © 2018 apocryphal. All rights reserved.
//

#ifndef Renderable2D_hpp
#define Renderable2D_hpp

#include "buffers/Buffer.hpp"
#include "buffers/IndexBuffer.hpp"
#include "buffers/VertexArray.hpp"
#include "../math/Math.h"
#include "Shader.hpp"

namespace dao {
	namespace graphics {
		using namespace math;
		
		struct VertexData {
			Vector3 vertex;
			unsigned int color;
		};
		
		class Renderable2D {
			// maybe should make protected
			Vector3 mPosition;
			Vector2 mSize;
			Vector4 mColor;
		public:
			Renderable2D(Vector3 position, Vector2 size, Vector4 color);
//			~Renderable2D();
			
			inline const Vector3& getPosition() const { return mPosition; }
			inline const Vector2& getSize() const { return mSize; }
			inline const Vector4& getColor() const { return mColor; }
			
		};
	}
}

#endif /* Renderable2D_hpp */
