//
//  Layer.cpp
//  dao
//
//  Created by Richard Bell on 11/27/18.
//  Copyright © 2018 apocryphal. All rights reserved.
//

#include "Layer.hpp"

namespace dao {
	namespace graphics {
		
		Layer::Layer(Renderer2D* renderer, Shader* shader, Matrix4 projectionMatrix)
		: mRenderer(renderer), mShader(shader), mProjectionMatrix(projectionMatrix) {
			mShader->enable();
			mShader->setUniform("pr_matrix", mProjectionMatrix);
			mShader->disable();
		}
		
		Layer::~Layer() {
			delete mRenderer;
			//delete mShader; //todo:figure out this bug
			for (auto r : mRenderables) {
				delete r;
			}
		}
		
		void Layer::add(Renderable2D* renderable) {
			mRenderables.push_back(renderable);
		}
		
		void Layer::render() {
			mShader->enable();
			mRenderer->begin();
			for (const auto renderable : mRenderables) {
				mRenderer->submit(renderable);
			}
			mRenderer->end();
			mRenderer->flush();
			//mShader->disable(); //todo: decide where this happens
		}
	}
}
