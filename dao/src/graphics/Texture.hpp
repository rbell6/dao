//
//  Texture.hpp
//  dao
//
//  Created by Richard Bell on 11/29/18.
//  Copyright © 2018 apocryphal. All rights reserved.
//

#ifndef Texture_hpp
#define Texture_hpp
#include <OpenGL/gl3.h>
#include <OpenGL/gl3ext.h>
#include <string>
#include <FreeImage.h>
#include "utils/ImageUtils.h"

using namespace std;

namespace dao {
	namespace graphics {
		class Texture {
			string mPath;
			GLuint mId;
			GLsizei mWidth{0}, mHeight{0};
		public:
			Texture(const string& path);
			~Texture();
			void bind();
			void unbind();
			
			inline const GLuint getId() const { return mId; }
			inline const unsigned int getWidth() const { return mWidth; }
			inline const unsigned int getHeight() const { return mWidth; }
			
		private:
			GLuint load();
		};
	}
}

#endif /* Texture_hpp */
