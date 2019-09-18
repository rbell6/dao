//
//  Sprite50K.h
//  dao
//
//  Created by Richard Bell on 1/4/19.
//  Copyright © 2019 apocryphal. All rights reserved.
//

#ifndef Sprite50K_h
#define Sprite50K_h
#include "Application.h"
#include "graphics/Shader.hpp"
#include "graphics/layers/TileLayer.hpp"
#include "graphics/Sprite.hpp"

namespace dao {
    class Sprite50K: public Application {
        graphics::Shader* mShader;
        graphics::TileLayer mPrimaryLayer;
    public:
        Sprite50K()
        : mShader(new graphics::Shader("src/shaders/basic.vert", "src/shaders/basic.frag")), mPrimaryLayer(mShader), Application() {
            mShader->enable();
            mShader->setUniform("pr_matrix", Matrix4::orthographic(-16.0f, 16.0f, -9.0f, 9.0f, -1.0f, 1.0f));
            
            for (float y{-9.0f}; y < 9.0f; y += 0.1f) {
                for (float x{-16.0f}; x < 16.0f; x += 0.1f) {
                    math::Vector4 color = math::Vector4(rand() % 1000 / 1000.f, 0, 1, 1);
                    mPrimaryLayer.add(new graphics::Sprite(x, y, 0.09f, 0.09f, color));
                }
            }
        }
        
        ~Sprite50K() {
            delete mShader;
        }
        
        void update() override {
            double x, y;
            mWindow.getMousePosition(x, y);
            mShader->enable();
            mShader->setUniform("light_pos", math::Vector2((float)(x * 32.0f / (mWindow.getWidth()/2) - 16.0f), (float)(9.0f - y * 18.0f / (mWindow.getHeight()/2))));
            mPrimaryLayer.render();
        }
    };
}

#endif /* Sprite50K_h */
