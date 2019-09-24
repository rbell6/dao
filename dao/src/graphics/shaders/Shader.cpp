//
//  Shader.cpp
//  dao
//
//  Created by Richard Bell on 9/20/19.
//  Copyright © 2019 apocryphal. All rights reserved.
//

#include "Shader.hpp"

namespace dao {
	namespace graphics {
		Shader::Shader(GLenum type, std::string source) {
			mId = glCreateShader(type);
			const char* source_cstr = source.c_str();
			glShaderSource(mId, 1, &source_cstr, nullptr);
		}
		
		Shader::~Shader() {
			glDeleteShader(mId);
		}
		
		bool Shader::compile() {
			GLint result;
			glCompileShader(mId);
			glGetShaderiv(mId, GL_COMPILE_STATUS, &result);
			if (result == GL_FALSE) {
				GLint length;
				glGetShaderiv(mId, GL_INFO_LOG_LENGTH, &length);
				char error[length];
				glGetShaderInfoLog(mId, length, &length, error); // todo: do something with error
				std::cout << "failed to compile shader! " << error << std::endl;
				return false;
			}
			return true;
		}
	}
}
