//
//  ShaderProgram.cpp
//  dao
//
//  Created by Richard Bell on 9/20/19.
//  Copyright © 2019 apocryphal. All rights reserved.
//

#include "ShaderProgram.hpp"

namespace dao {
	namespace graphics {
		
		ShaderProgram::ShaderProgram() {
			mId = glCreateProgram();
		}
		
		ShaderProgram::~ShaderProgram() {
			glDeleteProgram(mId);
		}
		
		void ShaderProgram::attachShader(Shader* shader) {
			glAttachShader(mId, shader->getId());
		}
		
		void ShaderProgram::link() {
			glLinkProgram(mId);
		}
		void ShaderProgram::validate() {
			glValidateProgram(mId);
		}
		
		GLint ShaderProgram::getUniformLocation(const GLchar* name) {
			return glGetUniformLocation(mId, name);
		}
		
		void ShaderProgram::setUniform(const GLchar* name, float* value, int count) {
			glUniform1fv(getUniformLocation(name), count, value);
		}
		void ShaderProgram::setUniform(const GLchar* name, const float value) {
			glUniform1f(getUniformLocation(name), value);
		}
		void ShaderProgram::setUniform(const GLchar* name, int* value, int count) {
			glUniform1iv(getUniformLocation(name), count, value);
		}
		void ShaderProgram::setUniform(const GLchar* name, const int value) {
			glUniform1i(getUniformLocation(name), value);
		}
		void ShaderProgram::setUniform(const GLchar* name, glm::vec2 vector) {
			glUniform2f(getUniformLocation(name), vector.x, vector.y);
		}
		void ShaderProgram::setUniform(const GLchar* name, glm::vec3 vector) {
			glUniform3f(getUniformLocation(name), vector.x, vector.y, vector.z);
		}
		void ShaderProgram::setUniform(const GLchar* name, glm::vec4 vector) {
			glUniform4f(getUniformLocation(name), vector.x, vector.y, vector.z, vector.w);
		}
		void ShaderProgram::setUniform(const GLchar* name, glm::mat4 matrix) {
			glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, glm::value_ptr(matrix));
		}
		
		void ShaderProgram::enable() const {
			glUseProgram(mId);
		}
		void ShaderProgram::disable() const {
			glUseProgram(0);
		}
	}
}
