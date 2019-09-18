//
//  IndexBuffer.hpp
//  dao
//
//  Created by Richard Bell on 11/25/18.
//  Copyright © 2018 apocryphal. All rights reserved.
//

#ifndef IndexBuffer_hpp
#define IndexBuffer_hpp
#include <OpenGL/gl3.h>
#include <OpenGL/gl3ext.h>

namespace dao {
	namespace graphics {
		class IndexBuffer {
			GLuint mId;
			GLuint mCount;
		public:
			IndexBuffer(GLushort* data, GLsizei count);
			IndexBuffer(GLuint* data, GLsizei count);
			~IndexBuffer();
			void bind() const;
			void unbind() const;
			inline GLuint getCount() const { return mCount; }
		};
	}
}

#endif /* IndexBuffer_hpp */
