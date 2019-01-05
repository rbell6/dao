//
//  Texture.cpp
//  dao
//
//  Created by Richard Bell on 11/29/18.
//  Copyright © 2018 apocryphal. All rights reserved.
//

#include "Texture.hpp"

namespace dao {
	namespace graphics {
		Texture::Texture(const string& path): mPath(path) {
			mId = load();
		}
		Texture::~Texture() {}
		
		void Texture::bind() {
			glBindTexture(GL_TEXTURE_2D, mId);
		}
		void Texture::unbind() {
			glBindTexture(mId, 0);
		}
		
		// private
		GLuint Texture::load() {
			BYTE* pixels = ImageUtils::loadImage(mPath.c_str(), mWidth, mHeight);
			GLuint id;
			glGenTextures(1, &id);
			glBindTexture(GL_TEXTURE_2D, id);
			//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, mWidth, mHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, pixels);
			glBindTexture(GL_TEXTURE_2D, 0);
			//delete[] pixels;
			return id;
		}
	}
}
