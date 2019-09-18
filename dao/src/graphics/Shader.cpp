//
//  Shader.cpp
//  dao
//
//  Created by Richard Bell on 11/24/18.
//  Copyright © 2018 apocryphal. All rights reserved.
//

#include "Shader.hpp"

namespace dao {
	namespace graphics {
		Shader::Shader(string vertexPath, string fragmentPath): mVertexPath(vertexPath), mFragmentPath(fragmentPath) {
			mId = load();
		}
		
		Shader::~Shader() {
			glDeleteProgram(mId);
		}
		
		GLint Shader::getUniformLocation(const GLchar* name) {
			return glGetUniformLocation(mId, name);
		}
		
		void Shader::setUniform(const GLchar* name, float* value, int count) {
			glUniform1fv(getUniformLocation(name), count, value);
		}
		void Shader::setUniform(const GLchar* name, const float value) {
			glUniform1f(getUniformLocation(name), value);
		}
		void Shader::setUniform(const GLchar* name, int* value, int count) {
			glUniform1iv(getUniformLocation(name), count, value);
		}
		void Shader::setUniform(const GLchar* name, const int value) {
			glUniform1i(getUniformLocation(name), value);
		}
        void Shader::setUniform(const GLchar* name, glm::vec2 vector) {
			glUniform2f(getUniformLocation(name), vector.x, vector.y);
		}
        void Shader::setUniform(const GLchar* name, glm::vec3 vector) {
			glUniform3f(getUniformLocation(name), vector.x, vector.y, vector.z);
		}
        void Shader::setUniform(const GLchar* name, glm::vec4 vector) {
			glUniform4f(getUniformLocation(name), vector.x, vector.y, vector.z, vector.w);
		}
		void Shader::setUniform(const GLchar* name, glm::mat4 matrix) {
			glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, &matrix[0][0]);
		}
		
		void Shader::enable() const {
			glUseProgram(mId);
		}
		void Shader::disable() const {
			glUseProgram(0);
		}
		
		// private
		GLuint Shader::load() {
			GLuint program = glCreateProgram();
			GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
			GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);
			string vertSourceStr = FileUtils::read(mVertexPath);
			string fragSourceStr = FileUtils::read(mFragmentPath);
			const char* vertexSource = vertSourceStr.c_str();
			const char* fragmentSource = fragSourceStr.c_str();
			
			glShaderSource(vertex, 1, &vertexSource, nullptr);
			glCompileShader(vertex);
			
			GLint result;
			glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);
			if (result == GL_FALSE) {
				GLint length;
				glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
				char error[length];
				glGetShaderInfoLog(vertex, length, &length, error); // todo: do something with error
				cout << "failed to compile vertex shader! " << error << endl;
				glDeleteShader(vertex);
				return 0;
			}
			
			glShaderSource(fragment, 1, &fragmentSource, nullptr);
			glCompileShader(fragment);
			
			GLint resultFragment;
			glGetShaderiv(fragment, GL_COMPILE_STATUS, &resultFragment);
			if (resultFragment == GL_FALSE) {
				GLint length;
				glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
				char error[length];
				glGetShaderInfoLog(fragment, length, &length, error); // todo: do something with error
				cout << "failed to compile fragment shader! " << error << endl;
				glDeleteShader(fragment);
				return 0;
			}
			
			glAttachShader(program, vertex);
			glAttachShader(program, fragment);
			glLinkProgram(program);
			glValidateProgram(program);
			
			glDeleteShader(vertex);
			glDeleteShader(fragment);
			return program;
		}
	}
}
