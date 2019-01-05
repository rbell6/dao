//
//  Shape.hpp
//  dao
//
//  Created by Richard Bell on 12/13/18.
//  Copyright © 2018 apocryphal. All rights reserved.
//

#ifndef Shape_hpp
#define Shape_hpp
#include "../../math/Vector2.hpp"

namespace dao {
	using namespace math;
	namespace graphics {
		class Shape {
			Vector2 position;
			int width, height;
		};
	}
}

#endif /* Shape_hpp */
