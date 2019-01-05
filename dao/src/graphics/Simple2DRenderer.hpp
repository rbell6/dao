//
//  Simple2DRenderer.hpp
//  dao
//
//  Created by Richard Bell on 11/25/18.
//  Copyright © 2018 apocryphal. All rights reserved.
//

#ifndef Simple2DRenderer_hpp
#define Simple2DRenderer_hpp
#include <deque>
#include "Renderer2D.hpp"
#include "StaticSprite.hpp"

using namespace std;

namespace dao {
	namespace graphics {
		class Simple2DRenderer : public Renderer2D {
			deque<const StaticSprite*> mRenderQueue;
		public:
			virtual ~Simple2DRenderer();
			void submit(const Renderable2D* renderable) override;
			void flush() override;
		};
	}
}

#endif /* Simple2DRenderer_hpp */
