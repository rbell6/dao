//
//  StaticSprite.cpp
//  dao
//
//  Created by Richard Bell on 11/26/18.
//  Copyright © 2018 apocryphal. All rights reserved.
//

#include "StaticSprite.hpp"

namespace dao {
	namespace graphics {
		StaticSprite::StaticSprite(float x, float y, float width, float height, Vector4& color, Shader& shader)
		: Renderable2D(Vector3(x, y, 0.0f), Vector2(width, height), color), mShader(shader) {
			mVertexArray = new VertexArray;
			GLfloat vertices[] = {
				0, 0, 0,
				0, height, 0,
				width, height, 0,
				width, 0, 0
			};
			GLfloat colors[] = {
				color.x, color.y, color.z, color.w,
				color.x, color.y, color.z, color.w,
				color.x, color.y, color.z, color.w,
				color.x, color.y, color.z, color.w
			};
			mVertexArray->addBuffer(new Buffer(vertices, 4 * 3, 3), 0);
			mVertexArray->addBuffer(new Buffer(colors, 4 * 4, 4), 1);
			
			GLuint indices[] = { 0, 1, 2, 2, 3, 0 };
			mIndexBuffer = new IndexBuffer(indices, 6);
		}
		
		StaticSprite::~StaticSprite() {
			delete mVertexArray;
			delete mIndexBuffer;
		}
	}
}
