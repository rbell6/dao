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
#include <glm/glm.hpp>
#include "buffers/Buffer.hpp"
#include "buffers/IndexBuffer.hpp"
#include "buffers/VertexArray.hpp"
#include "Shader.hpp"
#include "Renderer2D.hpp"
#include "Texture.hpp"

namespace dao {
	namespace graphics {
		
		struct VertexData {
			glm::vec3 vertex;
			glm::vec2 uv;
			float tid;
			unsigned int color;
		};
		
		class Renderable2D {
		protected:
			glm::vec3 mPosition;
			glm::vec2 mSize;
			glm::vec4 mColor;
			std::vector<glm::vec2> mUV;
			Texture* mTexture{nullptr};
			
			Renderable2D();
		public:
			Renderable2D(glm::vec3 position, glm::vec2 size, glm::vec4 color);
            Renderable2D(glm::vec3 position, glm::vec2 size, Texture* texture);
			
			virtual void submit(Renderer2D* renderer) const {
				renderer->submit(this);
			}
			
			inline const glm::vec3& getPosition() const { return mPosition; }
			inline const glm::vec2& getSize() const { return mSize; }
			inline const glm::vec4& getColor() const { return mColor; }
			
			inline void setPosition(glm::vec3 position) { mPosition = position; }
			inline void setSize(glm::vec2 size) { mSize = size; }
			inline void setColor(glm::vec4 color) { mColor = color; }
			
			inline const std::vector<glm::vec2>& getUV() const { return mUV; }
			inline const GLuint getTextureId() const { return mTexture == nullptr ? 0 : mTexture->getId(); }
		private:
			void setUVDefaults() {
				mUV.push_back(glm::vec2(0, 0));
				mUV.push_back(glm::vec2(0, 1));
				mUV.push_back(glm::vec2(1, 1));
				mUV.push_back(glm::vec2(1, 0));
			}
		};
	}
}

#endif /* Renderable2D_hpp */
