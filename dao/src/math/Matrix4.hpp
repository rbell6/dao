//
//  Matrix4.hpp
//  dao
//
//  Created by Richard Bell on 11/20/18.
//  Copyright © 2018 apocryphal. All rights reserved.
//

#ifndef Matrix4_hpp
#define Matrix4_hpp

#define _USE_MATH_DEFINES
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <math.h>
#include "Vector3.hpp"
#include "Vector4.hpp"
#include "MathFunctions.h"

namespace dao {
	namespace math {
		
		struct Matrix4 {
			glm::mat4 matrix;

			Matrix4();
			Matrix4(float diagonal);
			
			static Matrix4 identity();
			Matrix4& multiply(const Matrix4& other);
			friend Matrix4 operator *(Matrix4 left, const Matrix4& right);
			Matrix4& operator *=(const Matrix4& other);
			
			Vector3 multiply(const Vector3& other) const;
			friend Vector3 operator *(Matrix4 left, const Vector3& right);
			Vector4 multiply(const Vector4& other) const;
			friend Vector4 operator *(Matrix4 left, const Vector4& right);
			
			static Matrix4 orthographic(float left, float right, float bottom, float top, float near, float far);
			static Matrix4 perspective(float fov, float aspectRatio, float near, float far);
			
			static Matrix4 translation(const Vector3& translation);
			static Matrix4 rotation(float angle, const Vector3& axis);
			static Matrix4 scale(const Vector3& scale);
            static Matrix4 lookAt(Vector3 eye, Vector3 center, Vector3 up);
			
			const float* getElements() const { return glm::value_ptr(matrix); }
			//const Vector4* getColumns() const { return {}; }
		};
	}
}

#endif /* Matrix4_hpp */
