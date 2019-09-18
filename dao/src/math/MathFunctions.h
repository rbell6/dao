//
//  MathFunctions.h
//  dao
//
//  Created by Richard Bell on 11/24/18.
//  Copyright © 2018 apocryphal. All rights reserved.
//

#ifndef MathFunctions_h
#define MathFunctions_h
#include <glm/glm.hpp>

namespace dao {
	namespace math {
		inline float toRadians(float degrees) {
			return degrees * (M_PI / 180.f);
		}
        
        glm::vec3 multiplyMat4ByVec3(glm::mat4 m, glm::vec3 v) {
            return glm::vec3(
                m[0].x * v.x + m[1].x * v.y + m[2].x * v.z + m[3].x,
                m[0].y * v.x + m[1].y * v.y + m[2].y * v.z + m[3].y,
                m[0].z * v.x + m[1].z * v.y + m[2].z * v.z + m[3].z
            );
        }
	}
}


#endif /* MathFunctions_h */
