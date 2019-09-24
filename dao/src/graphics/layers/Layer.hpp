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
#include "graphics/Renderer2D.hpp"
#include "graphics/Renderable2D.hpp"
#include "graphics/shaders/ShaderProgram.hpp"
#include "math/Math.h"

namespace dao {
	namespace graphics {
		using namespace math;
		class Layer {
		protected:
			Renderer2D* mRenderer;
			std::vector<Renderable2D*> mRenderables;
			ShaderProgram* mShader;
			Matrix4 mProjectionMatrix;
		public:
			Layer(Renderer2D* renderer, ShaderProgram* shader, Matrix4 projectionMatrix);
			virtual ~Layer();
			virtual void add(Renderable2D* renderable);
			void render();
		};
	}
}

#endif /* Layer_hpp */
