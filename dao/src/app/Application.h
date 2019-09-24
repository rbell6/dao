//
//  Application.h
//  dao
//
//  Created by Richard Bell on 1/4/19.
//  Copyright © 2019 apocryphal. All rights reserved.
//

#ifndef Application_h
#define Application_h
#include <stdio.h>
#include <time.h>
#include "graphics/window.hpp"
#include "math/Math.h"
#include "utils/Timer.h"

namespace dao {
	class Application {
    protected:
        graphics::Window mWindow;
        Timer mTimer, mTime;
        int mExitCode{0};
        bool mShouldExit{false};
        math::Vector4 mClearColor{0, 0, 0, 1}; //0.8f, 0.8f, 0.8f, 1.0f
        Application* mInstance;
		int mFPS{0}, mFrames{0};
		double mDelta{0}, mTotal{0};
	public:
        Application(): mWindow("Dao", 960, 540) {}
        
        virtual void update() = 0;
        
        int run() {
            glClearColor(mClearColor.data.x, mClearColor.data.y, mClearColor.data.z, mClearColor.data.w);
            long long t = 0;
            while (!mWindow.closed()) {
                mTimer.reset();
                mWindow.clear();
                
                update();
                
                mWindow.update();
                
                mFrames++;
                if (mTime.elapsed().count() - t > 1000) {
                    t += 1000;
                    mFPS = mFrames;
                    mFrames = 0;
                    std::printf("%d fps\n", mFPS);
                }
            }
            return mExitCode;
        }
	};
    Application* app;
}

#endif /* Application_h */
