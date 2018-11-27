//
//  Buffer.hpp
//  dao
//
//  Created by Richard Bell on 11/25/18.
//  Copyright © 2018 apocryphal. All rights reserved.
//

#ifndef Buffer_hpp
#define Buffer_hpp
#include <GL/glew.h>

namespace dao {
	namespace graphics {
		class Buffer {
			GLuint mId;
			GLuint mComponentCount;
		public:
			Buffer(GLfloat* data, GLsizei count, GLuint componentCount);
			~Buffer();
			void bind() const;
			void unbind() const;
			inline GLuint getComponentCount() const { return mComponentCount; }
		};
	}
}

#endif /* Buffer_hpp */
