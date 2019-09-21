//
//  Vector3.hpp
//  dao
//
//  Created by Richard Bell on 11/19/18.
//  Copyright © 2018 apocryphal. All rights reserved.
//

#ifndef Vector3_hpp
#define Vector3_hpp
#include <iostream>
#include <math.h>

namespace dao {
	namespace math {
		struct Vector3 {
			float x, y, z;
			Vector3();
			Vector3(const float& x, const float& y, const float& z);
            Vector3 normalized();
			Vector3& add(const Vector3& other);
			Vector3& subtract(const Vector3& other);
			Vector3& multiply(const Vector3& other);
			Vector3& divide(const Vector3& other);
			
			friend Vector3 operator +(Vector3 left, const Vector3& right);
			friend Vector3 operator -(Vector3 left, const Vector3& right);
			friend Vector3 operator *(Vector3 left, const Vector3& right);
			friend Vector3 operator /(Vector3 left, const Vector3& right);
			
			bool operator ==(const Vector3& other);
			bool operator !=(const Vector3& other);
			
			Vector3& operator +=(const Vector3& other);
			Vector3& operator -=(const Vector3& other);
			Vector3& operator *=(const Vector3& other);
			Vector3& operator /=(const Vector3& other);
            
            static Vector3 cross(Vector3 v1, Vector3 v2);
            static float dot(Vector3 v1, Vector3 v2);
			
			friend std::ostream& operator <<(std::ostream& stream, const Vector3& vector);
		};
	}
}


#endif /* Vector3_hpp */
