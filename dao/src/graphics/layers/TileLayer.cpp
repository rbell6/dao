//
//  TileLayer.cpp
//  dao
//
//  Created by Richard Bell on 11/27/18.
//  Copyright © 2018 apocryphal. All rights reserved.
//

#include "TileLayer.hpp"

namespace dao {
	namespace graphics {
		TileLayer::TileLayer(Shader* shader)
		: Layer(new BatchRenderer2D(), shader, glm::ortho(-16.0f, 16.0f, -9.0f, 9.0f, -1.0f, 1.0f)) {}
		
		TileLayer::~TileLayer() {}
	}
}
