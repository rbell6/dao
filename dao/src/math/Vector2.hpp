//
//  Vector2.hpp
//  dao
//
//  Created by Richard Bell on 11/19/18.
//  Copyright © 2018 apocryphal. All rights reserved.
//

#ifndef Vector2_hpp
#define Vector2_hpp
#include <iostream>
#include <glm/glm.hpp>

namespace dao {
	namespace math {
		struct Vector2 {
			glm::vec2 data;
			Vector2();
			Vector2(const float& x, const float& y);
			Vector2& add(const Vector2& other);
			Vector2& subtract(const Vector2& other);
			Vector2& multiply(const Vector2& other);
			Vector2& divide(const Vector2& other);
			
			friend Vector2 operator +(Vector2 left, const Vector2& right);
			friend Vector2 operator -(Vector2 left, const Vector2& right);
			friend Vector2 operator *(Vector2 left, const Vector2& right);
			friend Vector2 operator /(Vector2 left, const Vector2& right);
			
			bool operator ==(const Vector2& other);
			bool operator !=(const Vector2& other);
			
			Vector2& operator +=(const Vector2& other);
			Vector2& operator -=(const Vector2& other);
			Vector2& operator *=(const Vector2& other);
			Vector2& operator /=(const Vector2& other);
			
			friend std::ostream& operator <<(std::ostream& stream, const Vector2& vector);
		};
	}
}

#endif /* Vector2_hpp */
