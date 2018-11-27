//
//  VertexArray.hpp
//  dao
//
//  Created by Richard Bell on 11/25/18.
//  Copyright © 2018 apocryphal. All rights reserved.
//

#ifndef VertexArray_hpp
#define VertexArray_hpp
#include <GL/glew.h>
#include <vector>
#include "Buffer.hpp"
using namespace std;

namespace dao {
	namespace graphics {
		class VertexArray {
			GLuint mId;
			vector<Buffer*> mBuffers;
		public:
			VertexArray();
			~VertexArray();
			void addBuffer(Buffer* buffer, GLuint index);
			void bind() const;
			void unbind() const;
		};
	}
}

#endif /* VertexArray_hpp */
