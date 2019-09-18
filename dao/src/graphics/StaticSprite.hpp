//
//  StaticSprite.hpp
//  dao
//
//  Created by Richard Bell on 11/26/18.
//  Copyright © 2018 apocryphal. All rights reserved.
//

#ifndef StaticSprite_hpp
#define StaticSprite_hpp
#include <glm/glm.hpp>
#include "Renderable2D.hpp"

namespace dao {
	namespace graphics {
		class StaticSprite : public Renderable2D {
			VertexArray* mVertexArray{nullptr};
			IndexBuffer* mIndexBuffer{nullptr};
			Shader& mShader;
		public:
            StaticSprite(float x, float y, float width, float height, glm::vec4 color, Shader& shader);
			~StaticSprite();
			
			inline const VertexArray* getVAO() const { return mVertexArray; }
			inline const IndexBuffer* getIBO() const { return mIndexBuffer; }
			inline Shader& getShader() const { return mShader; }
		};
	}
}

#endif /* StaticSprite_hpp */
