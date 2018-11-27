//
//  Layer.hpp
//  dao
//
//  Created by Richard Bell on 11/27/18.
//  Copyright © 2018 apocryphal. All rights reserved.
//

#ifndef Layer_hpp
#define Layer_hpp

#include <vector>
#include "../Renderer2D.hpp"
#include "../Renderable2D.hpp"
#include "../Shader.hpp"
#include "../../math/Math.h"

using namespace dao::math;
using namespace std;

namespace dao {
	namespace graphics {
		class Layer {
		protected:
			Renderer2D* mRenderer;
			vector<Renderable2D*> mRenderables;
			Shader* mShader;
			Matrix4 mProjectionMatrix;
		public:
			Layer(Renderer2D* renderer, Shader* shader, Matrix4 projectionMatrix);
			virtual ~Layer();
			virtual void add(Renderable2D* renderable);
			void render();
		};
	}
}

#endif /* Layer_hpp */
