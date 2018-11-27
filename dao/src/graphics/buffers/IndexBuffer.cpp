//
//  IndexBuffer.cpp
//  dao
//
//  Created by Richard Bell on 11/25/18.
//  Copyright © 2018 apocryphal. All rights reserved.
//

#include "IndexBuffer.hpp"

namespace dao {
	namespace graphics {
		IndexBuffer::IndexBuffer(GLushort* data, GLsizei count): mCount(count) {
			glGenBuffers(1, &mId);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mId);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLushort), data, GL_STATIC_DRAW);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}
		IndexBuffer::IndexBuffer(GLuint* data, GLsizei count): mCount(count) {
			glGenBuffers(1, &mId);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mId);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), data, GL_STATIC_DRAW);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}
		IndexBuffer::~IndexBuffer() {
			glDeleteBuffers(1, &mId);
		}
		void IndexBuffer::bind() const {
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mId);
		}
		void IndexBuffer::unbind() const {
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}
	}
}
