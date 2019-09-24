//
//  Shader.hpp
//  dao
//
//  Created by Richard Bell on 9/20/19.
//  Copyright © 2019 apocryphal. All rights reserved.
//

#ifndef Shader_hpp
#define Shader_hpp
#include <OpenGL/gl3.h>
#include <OpenGL/gl3ext.h>
#include <string>
#include <iostream>

namespace dao {
	namespace graphics {
		class Shader {
			GLuint mId;
		public:
			Shader(GLenum type, std::string source);
			~Shader();
			bool compile();
			inline GLuint getId() { return mId; }
		};
		
		class VertexShader : public Shader {
			std::string getVertSource(const std::string& source) {
				return source.substr(0, source.find("//frag"));
			}
		public:
			VertexShader(std::string source): Shader(GL_VERTEX_SHADER, getVertSource(source)) {}
		};
		
		class FragmentShader : public Shader {
			std::string getFragSource(const std::string& source) {
				return source.substr(source.find("//frag"));
			}
		public:
			FragmentShader(std::string source): Shader(GL_FRAGMENT_SHADER, getFragSource(source)) {}
		};
	}
}

#endif /* Shader_hpp */
