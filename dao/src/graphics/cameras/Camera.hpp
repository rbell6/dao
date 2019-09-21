//
//  Camera.hpp
//  dao
//
//  Created by Richard Bell on 9/17/19.
//  Copyright © 2019 apocryphal. All rights reserved.
//

#ifndef Camera_hpp
#define Camera_hpp
#include "math/Math.h"

namespace dao {
    namespace graphics {
        using namespace math;
        const float YAW         = -90.0f;
        const float PITCH       =  0.0f;
        const float SPEED       =  2.5f;
        const float SENSITIVITY =  0.1f;
        const float ZOOM        =  45.0f;
        
        enum CameraMovement {
            FORWARD,
            BACKWARD,
            LEFT,
            RIGHT
        };
        
        class Camera {
            Vector3 mPosition;
            Vector3 mFront;
            Vector3 mUp;
            Vector3 mRight;
            Vector3 mWorldUp;
            
            float mYaw;
            float mPitch;
            float mMovementSpeed;
            float mMouseSensitivity;
            float mZoom;
        public:
            Camera(Vector3 position = Vector3(0.0f, 0.0f, 0.0f), Vector3 up = Vector3(0.0f, 1.0f, 0.0f), float yaw = YAW, float pitch = PITCH);
            Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch);
            
            inline Matrix4 getViewMatrix() {
                return Matrix4::lookAt(mPosition, mPosition + mFront, mUp);
            }
            
        private:
            void updateCameraVectors();
        };
    }
}

#endif /* Camera_hpp */
