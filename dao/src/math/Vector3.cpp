//
//  Vector3.cpp
//  dao
//
//  Created by Richard Bell on 11/19/18.
//  Copyright © 2018 apocryphal. All rights reserved.
//

#include "Vector3.hpp"

namespace dao {
	namespace math {
		Vector3::Vector3(): data(0.0f, 0.0f, 0.0f) {}
		Vector3::Vector3(const float& x, const float& y, const float& z): data(x, y, z) {}
        
        Vector3 Vector3::normalized() {
            double magnitude = sqrt(pow(data.x, 2) + pow(data.y, 2) + pow(data.z, 2));
            return Vector3(data.x / magnitude, data.y / magnitude, data.z / magnitude);
        }
		
		Vector3& Vector3::add(const Vector3& other) {
			data.x += other.data.x;
			data.y += other.data.y;
			data.z += other.data.z;
			return *this;
		}
		Vector3& Vector3::subtract(const Vector3& other) {
			data.x -= other.data.x;
			data.y -= other.data.y;
			data.z -= other.data.z;
			return *this;
		}
		Vector3& Vector3::multiply(const Vector3& other) {
			data.x *= other.data.x;
			data.y *= other.data.y;
			data.z *= other.data.z;
			return *this;
		}
		Vector3& Vector3::divide(const Vector3& other) {
			data.x /= other.data.x;
			data.y /= other.data.y;
			data.z /= other.data.z;
			return *this;
		}
		
		Vector3 operator +(Vector3 left, const Vector3& right) {
			return left.add(right);
		}
		Vector3 operator -(Vector3 left, const Vector3& right) {
			return left.subtract(right);
		}
		Vector3 operator *(Vector3 left, const Vector3& right) {
			return left.multiply(right);
		}
		Vector3 operator /(Vector3 left, const Vector3& right) {
			return left.divide(right);
		}
		
		bool Vector3::operator ==(const Vector3& other) {
			return data.x == other.data.x and data.y == other.data.y and data.z == other.data.z;
		}
		
		bool Vector3::operator !=(const Vector3& other) {
			return !(*this == other);
		}
		
		Vector3& Vector3::operator +=(const Vector3& other) {
			return add(other);
		}
		Vector3& Vector3::operator -=(const Vector3& other) {
			return subtract(other);
		}
		Vector3& Vector3::operator *=(const Vector3& other) {
			return multiply(other);
		}
		Vector3& Vector3::operator /=(const Vector3& other) {
			return divide(other);
		}
		
        Vector3 Vector3::cross(Vector3 v1, Vector3 v2) {
            return Vector3(
                v1.data.y * v2.data.z - v1.data.z * v2.data.y,
                v1.data.x * v2.data.z - v1.data.z * v2.data.x,
                v1.data.x * v2.data.x - v1.data.x * v2.data.x
            );
        }
        
        float Vector3::dot(Vector3 v1, Vector3 v2) {
            float product = 0.0f;
            product += v1.data.x * v2.data.x;
            product += v1.data.y * v2.data.y;
            product += v1.data.z * v2.data.z;
            return product;
        }
		
		std::ostream& operator <<(std::ostream& stream, const Vector3& vector) {
			stream << "Vector3: (" << vector.data.x << ", " << vector.data.y << ", " << vector.data.z << ")";
			return stream;
		}
	}
}
