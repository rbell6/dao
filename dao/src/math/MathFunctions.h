//
//  MathFunctions.h
//  dao
//
//  Created by Richard Bell on 11/24/18.
//  Copyright © 2018 apocryphal. All rights reserved.
//

#ifndef MathFunctions_h
#define MathFunctions_h

namespace dao {
	namespace math {
		inline float toRadians(float degrees) {
			return degrees * (M_PI / 180.f);
		}
	}
}


#endif /* MathFunctions_h */
