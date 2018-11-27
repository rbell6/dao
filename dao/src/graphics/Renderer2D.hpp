//
//  Rederer2D.hpp
//  dao
//
//  Created by Richard Bell on 11/25/18.
//  Copyright © 2018 apocryphal. All rights reserved.
//

#ifndef Renderer2D_hpp
#define Renderer2D_hpp
#include <GL/glew.h>
#include "Renderable2D.hpp"
#include "../math/Math.h"

namespace dao {
	namespace graphics {
		class Renderer2D {
		public:
			virtual void begin() {};
			virtual void end() {};
			virtual void submit(const Renderable2D* renderable) = 0;
			virtual void flush() = 0;
		};
	}
}

#endif /* Rederer2D_hpp */
