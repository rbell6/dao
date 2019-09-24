//
//  Vector4.cpp
//  dao
//
//  Created by Richard Bell on 11/19/18.
//  Copyright © 2018 apocryphal. All rights reserved.
//

#include "Vector4.hpp"

namespace dao {
	namespace math {
		Vector4::Vector4(const float& x, const float& y, const float& z, const float& w): data(x, y, z, w) {}
		
		Vector4& Vector4::add(const Vector4& other) {
			data.x += other.data.x;
			data.y += other.data.y;
			data.z += other.data.z;
			data.w += other.data.w;
			return *this;
		}
		Vector4& Vector4::subtract(const Vector4& other) {
			data.x -= other.data.x;
			data.y -= other.data.y;
			data.z -= other.data.z;
			data.w -= other.data.w;
			return *this;
		}
		Vector4& Vector4::multiply(const Vector4& other) {
			data.x *= other.data.x;
			data.y *= other.data.y;
			data.z *= other.data.z;
			data.w *= other.data.w;
			return *this;
		}
		Vector4& Vector4::divide(const Vector4& other) {
			data.x /= other.data.x;
			data.y /= other.data.y;
			data.z /= other.data.z;
			data.w /= other.data.w;
			return *this;
		}
		
		Vector4 operator +(Vector4 left, const Vector4& right) {
			return left.add(right);
		}
		Vector4 operator -(Vector4 left, const Vector4& right) {
			return left.subtract(right);
		}
		Vector4 operator *(Vector4 left, const Vector4& right) {
			return left.multiply(right);
		}
		Vector4 operator /(Vector4 left, const Vector4& right) {
			return left.divide(right);
		}
		
		bool Vector4::operator ==(const Vector4& other) {
			return (
				data.x == other.data.x and
				data.y == other.data.y and
				data.z == other.data.z and
				data.w == other.data.w
			);
		}
		
		bool Vector4::operator !=(const Vector4& other) {
			return !(*this == other);
		}
		
		Vector4& Vector4::operator +=(const Vector4& other) {
			return add(other);
		}
		Vector4& Vector4::operator -=(const Vector4& other) {
			return subtract(other);
		}
		Vector4& Vector4::operator *=(const Vector4& other) {
			return multiply(other);
		}
		Vector4& Vector4::operator /=(const Vector4& other) {
			return divide(other);
		}
		
		
		std::ostream& operator <<(std::ostream& stream, const Vector4& vector) {
			stream << "Vector4: (" << vector.data.x << ", " << vector.data.y << ", " << vector.data.z << ", " << vector.data.w << ")";
			return stream;
		}
	}
}
