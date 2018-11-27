//
//  TileLayer.hpp
//  dao
//
//  Created by Richard Bell on 11/27/18.
//  Copyright © 2018 apocryphal. All rights reserved.
//

#ifndef TileLayer_hpp
#define TileLayer_hpp

#include "Layer.hpp"
#include "../BatchRenderer2D.hpp"

namespace dao {
	namespace graphics {
		class TileLayer : public Layer {
		public:
			TileLayer(Shader* shader);
			~TileLayer();
		};
	}
}

#endif /* TileLayer_hpp */
