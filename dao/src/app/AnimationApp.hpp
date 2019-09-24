//
//  AnimationApp.hpp
//  dao
//
//  Created by Richard Bell on 9/21/19.
//  Copyright © 2019 apocryphal. All rights reserved.
//

#ifndef AnimationApp_hpp
#define AnimationApp_hpp
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
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
		glm::mat4 mMatrix;
	public:
		AnimationApp(): mRootEntity(mShader), Application() {
			mMatrix = glm::ortho(-16.0f, 16.0f, -9.0f, 9.0f, -1.0f, 1.0f);
			mShader->enable();
			mShader->setUniform("projection", mMatrix);
			mRootEntity.getTileLayer().add(new graphics::Sprite(0, 0, 1.0f, 1.0f, glm::vec4(rand() % 1000 / 1000.f, 0, 1, 1)));
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
			mShader->setUniform("projection", glm::rotate(mMatrix, mAngle, glm::vec3(0, 0, 1)));
			mRootEntity.update();
		}
	};
}


#endif /* AnimationApp_hpp */
