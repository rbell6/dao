//
//  Shader.hpp
//  dao
//
//  Created by Richard Bell on 11/24/18.
//  Copyright © 2018 apocryphal. All rights reserved.
//

#ifndef Shader_hpp
#define Shader_hpp
#include <OpenGL/gl3.h>
#include <OpenGL/gl3ext.h>
#include <iostream>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "utils/FileUtils.h"

namespace dao {
	namespace graphics {
        using namespace std;
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
            void setUniform(const GLchar* name, glm::vec2 vector);
            void setUniform(const GLchar* name, glm::vec3 vector);
            void setUniform(const GLchar* name, glm::vec4 vector);
            void setUniform(const GLchar* name, glm::mat4 matrix);
			
			void enable() const;
			void disable() const;
			inline GLuint id() { return mId; }
		private:
			GLuint load();
		};
	}
}

#endif /* Shader_hpp */
