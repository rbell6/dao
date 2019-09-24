//
//  BatchRenderer2D.cpp
//  dao
//
//  Created by Richard Bell on 11/26/18.
//  Copyright © 2018 apocryphal. All rights reserved.
//

#include "BatchRenderer2D.hpp"

namespace dao {
	namespace graphics {
		
		BatchRenderer2D::BatchRenderer2D() {
			init();
		}
		
		BatchRenderer2D::~BatchRenderer2D() {
			delete mIBO;
			glDeleteBuffers(1, &mVBO);
		}
		
		void BatchRenderer2D::begin() {
			glBindBuffer(GL_ARRAY_BUFFER, mVBO);
			mBuffer = (VertexData*) glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
		}
		
		void BatchRenderer2D::submit(const Renderable2D* renderable) {
			glm::vec3 position = renderable->getPosition();
			glm::vec2 size = renderable->getSize();
			glm::vec4 color = renderable->getColor();
			
			const vector<glm::vec2>& uv = renderable->getUV();
			const GLuint textureId = renderable->getTextureId();
			unsigned int uintColor{0};
			float textureSlot = 0.0f;
			
			if (textureId > 0) {
				
				bool found = false;
				for (int i = 0; i < mTextureSlots.size(); i++) {
					if (mTextureSlots[i] == textureId) {
						textureSlot = (float) (i + 1);
						found = true;
						break;
					}
				}
				if (!found) {
					if (mTextureSlots.size() >= 32) {
						end();
						flush();
						begin();
					}
					mTextureSlots.push_back(textureId);
					textureSlot = (float) (mTextureSlots.size());
				}
			} else {
				int r = color.x * 255.0f;
				int g = color.y * 255.0f;
				int b = color.z * 255.0f;
				int a = color.w * 255.0f;
				
				uintColor = a << 24 | b << 16 | g << 8 | r;
			}
			
			//Matrix4 m(*mTransformationBack);
			mBuffer->vertex = glm::vec3(*mTransformationBack * glm::vec4(position, 1));
			mBuffer->uv = uv[0];
			mBuffer->tid = textureSlot;
			mBuffer->color = uintColor;
			mBuffer++;
			
			mBuffer->vertex = glm::vec3(*mTransformationBack * glm::vec4(position.x, position.y + size.y, position.z, 1));
			mBuffer->uv = uv[1];
			mBuffer->tid = textureSlot;
			mBuffer->color = uintColor;
			mBuffer++;
			
			mBuffer->vertex = glm::vec3(*mTransformationBack * glm::vec4(position.x + size.x, position.y + size.y, position.z, 1));
			mBuffer->uv = uv[2];
			mBuffer->tid = textureSlot;
			mBuffer->color = uintColor;
			mBuffer++;
			
			mBuffer->vertex = glm::vec3(*mTransformationBack * glm::vec4(position.x + size.x, position.y, position.z, 1));
			mBuffer->uv = uv[3];
			mBuffer->tid = textureSlot;
			mBuffer->color = uintColor;
			mBuffer++;
			
			mIndexCount += 6;
		}
		
		void BatchRenderer2D::end() {
			glUnmapBuffer(GL_ARRAY_BUFFER);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}
		
		void BatchRenderer2D::flush() {
			for (int i = 0; i < mTextureSlots.size(); i++) {
				glActiveTexture(GL_TEXTURE0 + i);
				glBindTexture(GL_TEXTURE_2D, mTextureSlots[i]);
			}
			glBindVertexArray(mVAO);
			mIBO->bind();
			
			glDrawElements(GL_TRIANGLES, mIndexCount, GL_UNSIGNED_INT, NULL);
			
			mIBO->unbind();
			glBindVertexArray(0);
			mIndexCount = 0;
		}
		
		// private
		void BatchRenderer2D::init() {
			glGenVertexArrays(1, &mVAO);
			glGenBuffers(1, &mVBO);
			
			glBindVertexArray(mVAO);
			glBindBuffer(GL_ARRAY_BUFFER, mVBO);
			glBufferData(GL_ARRAY_BUFFER, RENDERER_BUFFER_SIZE, NULL, GL_DYNAMIC_DRAW);
			
			glEnableVertexAttribArray(SHADER_VERTEX_INDEX);
			glEnableVertexAttribArray(SHADER_UV_INDEX);
			glEnableVertexAttribArray(SHADER_TID_INDEX);
			glEnableVertexAttribArray(SHADER_COLOR_INDEX);
			
			glVertexAttribPointer(SHADER_VERTEX_INDEX, 3, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (const GLvoid*)0);
			glVertexAttribPointer(SHADER_UV_INDEX, 2, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (const GLvoid*)offsetof(VertexData, uv));
			glVertexAttribPointer(SHADER_TID_INDEX, 1, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (const GLvoid*)offsetof(VertexData, tid));
			glVertexAttribPointer(SHADER_COLOR_INDEX, 4, GL_UNSIGNED_BYTE, GL_TRUE, RENDERER_VERTEX_SIZE, (const GLvoid*) offsetof(VertexData, color));
			glBindBuffer(GL_ARRAY_BUFFER, 0);
			
			GLuint* indices = new GLuint[RENDERER_INDICES_SIZE];
			int offset{0};
			for (int i = 0; i < RENDERER_INDICES_SIZE; i += 6) {
				indices[  i  ] = (offset + 0);
				indices[i + 1] = (offset + 1);
				indices[i + 2] = (offset + 2);
				
				indices[i + 3] = (offset + 2);
				indices[i + 4] = (offset + 3);
				indices[i + 5] = (offset + 0);
				offset += 4;
			}
			mIBO = new IndexBuffer(indices, RENDERER_INDICES_SIZE);
			glBindVertexArray(0);
		}
	}
}
