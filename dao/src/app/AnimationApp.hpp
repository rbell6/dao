//
//  AnimationApp.hpp
//  dao
//
//  Created by Richard Bell on 9/21/19.
//  Copyright © 2019 apocryphal. All rights reserved.
//

#ifndef AnimationApp_hpp
#define AnimationApp_hpp
#include "Application.h"
#include "graphics/shaders/ShaderManager.hpp"
#include "graphics/layers/TileLayer.hpp"
#include "graphics/Sprite.hpp"
#include "gameplay/entities/TileLayerEntity.hpp"

namespace dao {
	class AnimationApp : public Application {
		graphics::ShaderProgram* mShader = graphics::ShaderManager::createShaderProgram(graphics::shaders::basic);
		gameplay::TileLayerEntity mRootEntity;
		float mAngle = 0.0;
		Matrix4 mMatrix;
	public:
		AnimationApp(): mRootEntity(mShader), Application() {
			mMatrix = Matrix4::orthographic(-16.0f, 16.0f, -9.0f, 9.0f, -1.0f, 1.0f);
			mShader->enable();
			mShader->setUniform("projection", mMatrix);
			math::Vector4 color = math::Vector4(rand() % 1000 / 1000.f, 0, 1, 1);
			mRootEntity.getTileLayer().add(new graphics::Sprite(0, 0, 1.0f, 1.0f, color));
		}
		
		~AnimationApp() {
			delete mShader;
		}
		
		void update() override {
			double x, y;
			if (mAngle++ > 360) {
				mAngle = 0;
			}
			mWindow.getMousePosition(x, y);
			mShader->enable();
			mShader->setUniform("light_pos", {0, 0});
			mShader->setUniform("projection", mMatrix * Matrix4::rotation(mAngle, Vector3(0, 0, 1)));
			mRootEntity.update();
		}
	};
}


#endif /* AnimationApp_hpp */
