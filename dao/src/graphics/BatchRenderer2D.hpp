//
//  BatchRenderer2D.hpp
//  dao
//
//  Created by Richard Bell on 11/26/18.
//  Copyright © 2018 apocryphal. All rights reserved.
//

#ifndef BatchRenderer2D_hpp
#define BatchRenderer2D_hpp
#include <cstddef>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_access.hpp>
#include "Renderer2D.hpp"
#include "Renderable2D.hpp"
#include "buffers/IndexBuffer.hpp"

namespace dao {
	namespace graphics {
		
#define RENDERER_MAX_SPRITES 60000
#define RENDERER_VERTEX_SIZE sizeof(VertexData)
#define RENDERER_SPRITE_SIZE RENDERER_VERTEX_SIZE * 4
#define RENDERER_BUFFER_SIZE RENDERER_SPRITE_SIZE * RENDERER_MAX_SPRITES
#define RENDERER_INDICES_SIZE RENDERER_MAX_SPRITES * 6
#define SHADER_VERTEX_INDEX 0
#define SHADER_UV_INDEX 1
#define SHADER_TID_INDEX 2
#define SHADER_COLOR_INDEX 3
		
		class BatchRenderer2D : public Renderer2D {
			GLuint mVAO;
			GLuint mVBO;
			IndexBuffer* mIBO;
			GLsizei mIndexCount;
			VertexData* mBuffer;
            std::vector<GLuint> mTextureSlots;
			
			void init();
		public:
			BatchRenderer2D();
			virtual ~BatchRenderer2D();
			void begin() override;
			void submit(const Renderable2D* renderable) override;
			void end() override;
			void flush() override;
		};
	}
}


#endif /* BatchRenderer2D_hpp */
