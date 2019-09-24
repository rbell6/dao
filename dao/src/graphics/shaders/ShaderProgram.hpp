//
//  ShaderProgram.hpp
//  dao
//
//  Created by Richard Bell on 9/20/19.
//  Copyright © 2019 apocryphal. All rights reserved.
//

#ifndef ShaderProgram_hpp
#define ShaderProgram_hpp
#include <OpenGL/gl3.h>
#include <OpenGL/gl3ext.h>
#include <iostream>
#include <string>
#include "math/Math.h"
#include "graphics/shaders/Shader.hpp"

namespace dao {
	namespace graphics {
		using namespace math;
		
		class ShaderProgram {
			GLuint mId;
		public:
			ShaderProgram();
			~ShaderProgram();
			GLint getUniformLocation(const GLchar* name);
			void setUniform(const GLchar* name, float* value, int count);
			void setUniform(const GLchar* name, const float value);
			void setUniform(const GLchar* name, int* value, int count);
			void setUniform(const GLchar* name, const int value);
			void setUniform(const GLchar* name, const Vector2 &vector);
			void setUniform(const GLchar* name, const Vector3 &vector);
			void setUniform(const GLchar* name, const Vector4 &vector);
			void setUniform(const GLchar* name, const Matrix4 &matrix);
			void attachShader(Shader* shader);
			void link();
			void validate();
			void enable() const;
			void disable() const;
			inline GLuint id() { return mId; }
		};
	}
}

#endif /* ShaderProgram_hpp */
