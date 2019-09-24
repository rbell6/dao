//
//  Matrix4.cpp
//  dao
//
//  Created by Richard Bell on 11/20/18.
//  Copyright © 2018 apocryphal. All rights reserved.
//

#include "Matrix4.hpp"

namespace dao {
	namespace math {
		Matrix4::Matrix4() {
			for (int i = 0; i < 4 * 4; i++)
				glm::value_ptr(matrix)[i] = 0.0f;
		}
		Matrix4::Matrix4(float diagonal) {
			for (int i = 0; i < 4 * 4; i++)
				glm::value_ptr(matrix)[i] = 0.0f;
			glm::value_ptr(matrix)[0 + 0 * 4] = diagonal;
			glm::value_ptr(matrix)[1 + 1 * 4] = diagonal;
			glm::value_ptr(matrix)[2 + 2 * 4] = diagonal;
			glm::value_ptr(matrix)[3 + 3 * 4] = diagonal;
		}
		
		Matrix4 Matrix4::identity() {
			return Matrix4(1.0f);
		}
		
		Matrix4& Matrix4::multiply(const Matrix4& other) {
			// column major ordering (elements[row + col * 4])
			float data[16];
			for (int y = 0; y < 4; y++) {
				for (int x = 0; x < 4; x++) {
					float sum = 0.0f;
					for (int e = 0; e < 4; e++) {
						sum += glm::value_ptr(matrix)[x + e * 4] * other.getElements()[e + y * 4];
					}
					data[x + y * 4] = sum;
				}
			}
			memcpy(glm::value_ptr(matrix), data, 4 * 4 * sizeof(float));
			return *this;
		}
		
		Matrix4 operator *(Matrix4 left, const Matrix4& right) { // take const ref?
			return left.multiply(right);
		}
		
		Vector3 Matrix4::multiply(const Vector3& other) const {
			return Vector3(
				matrix[0].x * other.data.x + matrix[1].x * other.data.y + matrix[2].x * other.data.z + matrix[3].x,
				matrix[0].y * other.data.x + matrix[1].y * other.data.y + matrix[2].y * other.data.z + matrix[3].y,
				matrix[0].z * other.data.x + matrix[1].z * other.data.y + matrix[2].z * other.data.z + matrix[3].z
			);
		}
		Vector4 Matrix4::multiply(const Vector4& other) const {
			return Vector4(
				matrix[0].x * other.data.x + matrix[1].x * other.data.y + matrix[2].x * other.data.z + matrix[3].x * other.data.w,
				matrix[0].y * other.data.x + matrix[1].y * other.data.y + matrix[2].y * other.data.z + matrix[3].y * other.data.w,
				matrix[0].z * other.data.x + matrix[1].z * other.data.y + matrix[2].z * other.data.z + matrix[3].z * other.data.w,
				matrix[0].w * other.data.x + matrix[1].w * other.data.y + matrix[2].y * other.data.z + matrix[3].w * other.data.w
			);
		}
		Vector3 operator *(Matrix4 left, const Vector3& right) {
			return left.multiply(right);
		}
		Vector4 operator *(Matrix4 left, const Vector4& right) {
			return left.multiply(right);
		}
		
		Matrix4& Matrix4::operator *=(const Matrix4& other) {
			return multiply(other);
		}
		
		Matrix4 Matrix4::orthographic(float left, float right, float bottom, float top, float near, float far) {
			Matrix4 result(1.0f);
			glm::value_ptr(result.matrix)[0 + 0 * 4] = 2.0f / (right - left);
			glm::value_ptr(result.matrix)[1 + 1 * 4] = 2.0f / (top - bottom);
			glm::value_ptr(result.matrix)[2 + 2 * 4] = 2.0f / (near - far);
			// result.elements[3 + 3 * 4] = 2.0f / (right - left);
			
			glm::value_ptr(result.matrix)[0 + 3 * 4] = (left + right) / (left - right);
			glm::value_ptr(result.matrix)[1 + 3 * 4] = (bottom + top) / (bottom - top);
			glm::value_ptr(result.matrix)[2 + 3 * 4] = (far + near) / (far - near);
			return result;
		}
		Matrix4 Matrix4::perspective(float fov, float aspectRatio, float near, float far) {
			Matrix4 result(1.0f);
			float q = 1.0f / (float)tan(toRadians(0.5f * fov));
			float a = q / aspectRatio;
			float b = (near + far)  / (near - far);
			float c = (2.0f * near * far) / (near - far);
			glm::value_ptr(result.matrix)[0 + 0 * 4] = a;
			glm::value_ptr(result.matrix)[1 + 1 * 4] = q;
			glm::value_ptr(result.matrix)[2 + 2 * 4] = b;
			glm::value_ptr(result.matrix)[3 + 2 * 4] = -1.0f;
			glm::value_ptr(result.matrix)[2 + 3 * 4] = c;
			return result; // return c?
		}
		
		Matrix4 Matrix4::translation(const Vector3& translation) {
			Matrix4 result(1.0f);
			glm::value_ptr(result.matrix)[0 + 3 * 4] = translation.data.x;
			glm::value_ptr(result.matrix)[1 + 3 * 4] = translation.data.y;
			glm::value_ptr(result.matrix)[2 + 3 * 4] = translation.data.z;
			return result;
		}
		
		Matrix4 Matrix4::rotation(float angle, const Vector3& axis) {
			Matrix4 result(1.0f);
			float r = toRadians(angle);
			float c = cos(r);
			float s = sin(r);
			float omc = 1.0f - c;
			
			float x = axis.data.x;
			float y = axis.data.y;
			float z = axis.data.z;
			
			glm::value_ptr(result.matrix)[0 + 0 * 4] = x * omc + c;
			glm::value_ptr(result.matrix)[1 + 0 * 4] = y * x * omc + z * s;
			glm::value_ptr(result.matrix)[2 + 0 * 4] = x * z * omc - z * s;
			
			glm::value_ptr(result.matrix)[0 + 1 * 4] = x * y * omc - z * s;
			glm::value_ptr(result.matrix)[1 + 1 * 4] = y * omc + c;
			glm::value_ptr(result.matrix)[2 + 1 * 4] = y * z * omc + x * s;
			
			glm::value_ptr(result.matrix)[0 + 2 * 4] = x * z * omc + z * s;
			glm::value_ptr(result.matrix)[1 + 2 * 4] = y * z * omc - x * s;
			glm::value_ptr(result.matrix)[2 + 2 * 4] = z * omc + c;
			
			return result;
		}
		
		Matrix4 Matrix4::scale(const Vector3& scale) {
			Matrix4 result(1.0f);
			glm::value_ptr(result.matrix)[0 + 0 * 4] = scale.data.x;
			glm::value_ptr(result.matrix)[1 + 1 * 4] = scale.data.y;
			glm::value_ptr(result.matrix)[2 + 2 * 4] = scale.data.z;
			return result;
		}
        
        Matrix4 Matrix4::lookAt(Vector3 eye, Vector3 center, Vector3 up) {
            Vector3 f = (center - eye).normalized();
            Vector3 u = up.normalized();
            Vector3 s = Vector3::cross(f, u).normalized();
            u = Vector3::cross(s, f);
            Matrix4 result = Matrix4::identity();
            result.matrix[0].x = s.data.x;
            result.matrix[1].x = s.data.y;
            result.matrix[2].x = s.data.z;
            
            result.matrix[0].y = u.data.x;
            result.matrix[1].y = u.data.x;
            result.matrix[2].y = u.data.x;
            
            result.matrix[0].z = -f.data.x;
            result.matrix[1].z = -f.data.x;
            result.matrix[2].z = -f.data.x;
            
            result.matrix[3].x = -Vector3::dot(s, eye);
            result.matrix[3].y = -Vector3::dot(u, eye);
            result.matrix[3].z = Vector3::dot(f, eye);
            return result;
        }
	}
}
