//
//  Vector2.cpp
//  dao
//
//  Created by Richard Bell on 11/19/18.
//  Copyright © 2018 apocryphal. All rights reserved.
//

#include "Vector2.hpp"

namespace dao {
	namespace math {
		Vector2::Vector2(): data(0.0f, 0.0f) {}
		Vector2::Vector2(const float& x, const float& y): data(x, y) {}
		
		Vector2& Vector2::add(const Vector2& other) {
			data.x += other.data.x;
			data.y += other.data.y;
			return *this;
		}
		Vector2& Vector2::subtract(const Vector2& other) {
			data.x -= other.data.x;
			data.y -= other.data.y;
			return *this;
		}
		Vector2& Vector2::multiply(const Vector2& other) {
			data.x *= other.data.x;
			data.y *= other.data.y;
			return *this;
		}
		Vector2& Vector2::divide(const Vector2& other) {
			data.x /= other.data.x;
			data.y /= other.data.y;
			return *this;
		}
		
		Vector2 operator +(Vector2 left, const Vector2& right) {
			return left.add(right);
		}
		Vector2 operator -(Vector2 left, const Vector2& right) {
			return left.subtract(right);
		}
		Vector2 operator *(Vector2 left, const Vector2& right) {
			return left.multiply(right);
		}
		Vector2 operator /(Vector2 left, const Vector2& right) {
			return left.divide(right);
		}
		
		bool Vector2::operator ==(const Vector2& other) {
			return data.x == other.data.x and data.y == other.data.y;
		}
		
		bool Vector2::operator !=(const Vector2& other) {
			return !(*this == other);
		}
		
		Vector2& Vector2::operator +=(const Vector2& other) {
			return add(other);
		}
		Vector2& Vector2::operator -=(const Vector2& other) {
			return subtract(other);
		}
		Vector2& Vector2::operator *=(const Vector2& other) {
			return multiply(other);
		}
		Vector2& Vector2::operator /=(const Vector2& other) {
			return divide(other);
		}
		
		
		std::ostream& operator <<(std::ostream& stream, const Vector2& vector) {
			stream << "Vector2: (" << vector.data.x << ", " << vector.data.y << ")";
			return stream;
		}
	}
}
