//
//  Application.h
//  dao
//
//  Created by Richard Bell on 1/4/19.
//  Copyright © 2019 apocryphal. All rights reserved.
//

#ifndef Application_h
#define Application_h
#include <glm/glm.hpp>
#include <stdio.h>
#include <time.h>
#include "graphics/window.hpp"
#include "utils/Timer.h"

namespace dao {
	class Application {
    protected:
        graphics::Window mWindow;
        Timer mTimer, mTime;
        int mExitCode{0};
        bool mShouldExit{false};
        glm::vec4 mClearColor{0, 0, 0, 1}; //0.8f, 0.8f, 0.8f, 1.0f
	public:
        Application(): mWindow("Dao", 960, 540) {}
        
        virtual void update() = 0;
        
        int run() {
            glClearColor(mClearColor.x, mClearColor.y, mClearColor.z, mClearColor.w);
            long long t = 0;
            int fps{0}, frames{0};
            while (!mWindow.closed()) {
                mTimer.reset();
                mWindow.clear();
                
                update();
                
                mWindow.update();
                
                frames++;
                if (mTime.elapsed().count() - t > 1000) {
                    t += 1000;
                    fps = frames;
                    frames = 0;
                    printf("%d fps\n", fps);
                }
            }
            return mExitCode;
        }
	};
}

#endif /* Application_h */
