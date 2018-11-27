//
//  Buffer.cpp
//  dao
//
//  Created by Richard Bell on 11/25/18.
//  Copyright © 2018 apocryphal. All rights reserved.
//

#include "Buffer.hpp"

namespace dao {
	namespace graphics {
		Buffer::Buffer(GLfloat* data, GLsizei count, GLuint componentCount): mComponentCount(componentCount) {
			glGenBuffers(1, &mId);
			glBindBuffer(GL_ARRAY_BUFFER, mId);
			glBufferData(GL_ARRAY_BUFFER, count * sizeof(GLfloat), data, GL_STATIC_DRAW);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}
		Buffer::~Buffer() {
			glDeleteBuffers(1, &mId);
		}
		
		void Buffer::bind() const {
			glBindBuffer(GL_ARRAY_BUFFER, mId);
		}
		void Buffer::unbind() const {
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}
	}
}
