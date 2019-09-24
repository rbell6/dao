//
//  ShaderManager.hpp
//  dao
//
//  Created by Richard Bell on 9/20/19.
//  Copyright © 2019 apocryphal. All rights reserved.
//

#ifndef ShaderManager_hpp
#define ShaderManager_hpp
#include <string>
#include "ShaderSource.h"
#include "ShaderProgram.hpp"

namespace dao {
	namespace graphics {
		class ShaderManager {
		public:
			static ShaderProgram* createShaderProgram(const std::string& source) {
				VertexShader vertex(source);
				FragmentShader fragment(source);
				vertex.compile();
				fragment.compile();
				ShaderProgram* program = new ShaderProgram;
				program->attachShader(&vertex);
				program->attachShader(&fragment);
				program->link();
				program->validate();
				return program;
			}
		};
	}
}

#endif /* ShaderManager_hpp */
