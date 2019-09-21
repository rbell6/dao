//
//  Renderable2D.hpp
//  dao
//
//  Created by Richard Bell on 11/25/18.
//  Copyright © 2018 apocryphal. All rights reserved.
//

#ifndef Renderable2D_hpp
#define Renderable2D_hpp
#include <vector>
#include "buffers/Buffer.hpp"
#include "buffers/IndexBuffer.hpp"
#include "buffers/VertexArray.hpp"
#include "../math/Math.h"
#include "Shader.hpp"
#include "Renderer2D.hpp"
#include "Texture.hpp"
using namespace std;

namespace dao {
	namespace graphics {
		using namespace math;
		
		struct VertexData {
			Vector3 vertex;
			Vector2 uv;
			float tid;
			unsigned int color;
		};
		
		class Renderable2D {
		protected:
			Vector3 mPosition;
			Vector2 mSize;
			Vector4 mColor;
			vector<Vector2> mUV;
			Texture* mTexture{nullptr};
			
			Renderable2D();
		public:
			Renderable2D(Vector3 position, Vector2 size, Vector4 color);
            Renderable2D(Vector3 position, Vector2 size, Texture* texture);
			
			virtual void submit(Renderer2D* renderer) const {
				renderer->submit(this);
			}
			
			inline const Vector3& getPosition() const { return mPosition; }
			inline const Vector2& getSize() const { return mSize; }
			inline const Vector4& getColor() const { return mColor; }
			inline const vector<Vector2>& getUV() const { return mUV; }
			inline const GLuint getTextureId() const { return mTexture == nullptr ? 0 : mTexture->getId(); }
		private:
			void setUVDefaults() {
				mUV.push_back(Vector2(0, 0));
				mUV.push_back(Vector2(0, 1));
				mUV.push_back(Vector2(1, 1));
				mUV.push_back(Vector2(1, 0));
			}
		};
	}
}

#endif /* Renderable2D_hpp */
