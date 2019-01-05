//
//  Simple2DRenderer.cpp
//  dao
//
//  Created by Richard Bell on 11/25/18.
//  Copyright © 2018 apocryphal. All rights reserved.
//

#include "Simple2DRenderer.hpp"
#include "Renderable2D.hpp"

namespace dao {
	namespace graphics {
		Simple2DRenderer::~Simple2DRenderer() {}
		
		void Simple2DRenderer::submit(const Renderable2D* renderable) {
			mRenderQueue.push_back((StaticSprite*)renderable);
		}
		void Simple2DRenderer::flush() {
			while (not mRenderQueue.empty()) {
				const StaticSprite* sprite = mRenderQueue.front();
				sprite->getVAO()->bind();
				sprite->getIBO()->bind();
				
				sprite->getShader().setUniform("ml_matrix", Matrix4::translation(sprite->getPosition()));
				glDrawElements(GL_TRIANGLES, sprite->getIBO()->getCount(), GL_UNSIGNED_INT, 0);
				
				sprite->getIBO()->unbind();
				sprite->getVAO()->unbind();
				mRenderQueue.pop_front();
			}
		}
	}
}
