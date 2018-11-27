//
//  VertexArray.cpp
//  dao
//
//  Created by Richard Bell on 11/25/18.
//  Copyright © 2018 apocryphal. All rights reserved.
//

#include "VertexArray.hpp"

namespace dao {
	namespace graphics {
		VertexArray::VertexArray() {
			glGenVertexArrays(1, &mId);
		}
		
		VertexArray::~VertexArray() {
			for (int i = 0; i < mBuffers.size(); i++) {
				delete mBuffers[i];
			}
			glDeleteVertexArrays(1, &mId);
		}
		
		void VertexArray::addBuffer(Buffer* buffer, GLuint index) {
			bind();
			buffer->bind();
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(index, buffer->getComponentCount(), GL_FLOAT, GL_FALSE, 0, 0);
			
			buffer->unbind();
			unbind();
		}
		
		void VertexArray::bind() const {
			glBindVertexArray(mId);
		}
		void VertexArray::unbind() const {
			glBindVertexArray(0);
		}
	}
}

