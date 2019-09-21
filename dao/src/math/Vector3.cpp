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
		Vector3::Vector3(): x(0.0f), y(0.0f), z(0.0f) {}
		Vector3::Vector3(const float& x, const float& y, const float& z): x(x), y(y), z(z) {}
        
        Vector3 Vector3::normalized() {
            double magnitude = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
            return Vector3(x / magnitude, y / magnitude, z / magnitude);
        }
		
		Vector3& Vector3::add(const Vector3& other) {
			x += other.x;
			y += other.y;
			z += other.z;
			return *this;
		}
		Vector3& Vector3::subtract(const Vector3& other) {
			x -= other.x;
			y -= other.y;
			z -= other.z;
			return *this;
		}
		Vector3& Vector3::multiply(const Vector3& other) {
			x *= other.x;
			y *= other.y;
			z *= other.z;
			return *this;
		}
		Vector3& Vector3::divide(const Vector3& other) {
			x /= other.x;
			y /= other.y;
			z /= other.z;
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
			return x == other.x and y == other.y and z == other.z;
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
                v1.y * v2.z - v1.z * v2.y,
                v1.x * v2.z - v1.z * v2.x,
                v1.x * v2.x - v1.x * v2.x
            );
        }
        
        float Vector3::dot(Vector3 v1, Vector3 v2) {
            float product = 0.0f;
            product += v1.x * v2.x;
            product += v1.y * v2.y;
            product += v1.z * v2.z;
            return product;
        }
		
		std::ostream& operator <<(std::ostream& stream, const Vector3& vector) {
			stream << "Vector3: (" << vector.x << ", " << vector.y << ", " << vector.z << ")";
			return stream;
		}
	}
}
