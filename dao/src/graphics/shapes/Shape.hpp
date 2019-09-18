//
//  Shape.hpp
//  dao
//
//  Created by Richard Bell on 12/13/18.
//  Copyright © 2018 apocryphal. All rights reserved.
//

#ifndef Shape_hpp
#define Shape_hpp
#include <glm/glm.hpp>

namespace dao {
	namespace graphics {
		class Shape {
            glm::vec2 position;
			int width, height;
		};
	}
}

#endif /* Shape_hpp */
