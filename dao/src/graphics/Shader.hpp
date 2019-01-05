//
//  Shader.hpp
//  dao
//
//  Created by Richard Bell on 11/24/18.
//  Copyright © 2018 apocryphal. All rights reserved.
//

#ifndef Shader_hpp
#define Shader_hpp

#include <GL/glew.h>
#include <iostream>
#include <string>
#include "../math/Math.h"
#include "../utils/FileUtils.h"

using namespace std;

namespace dao {
	using namespace math;
	
	namespace graphics {
		class Shader {
			GLuint mId;
			string mVertexPath;
			string mFragmentPath;
		public:
			Shader(string vertexPath, string fragmentPath);
			~Shader();
			
			GLint getUniformLocation(const GLchar* name);
			void setUniform(const GLchar* name, float* value, int count);
			void setUniform(const GLchar* name, const float value);
			void setUniform(const GLchar* name, int* value, int count);
			void setUniform(const GLchar* name, const int value);
			void setUniform(const GLchar* name, const Vector2 &vector);
			void setUniform(const GLchar* name, const Vector3 &vector);
			void setUniform(const GLchar* name, const Vector4 &vector);
			void setUniform(const GLchar* name, const Matrix4 &matrix);
			
			void enable() const;
			void disable() const;
			inline GLuint id() { return mId; }
		private:
			GLuint load();
		};
	}
}

#endif /* Shader_hpp */
