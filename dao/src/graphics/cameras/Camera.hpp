//
//  Camera.hpp
//  dao
//
//  Created by Richard Bell on 9/17/19.
//  Copyright © 2019 apocryphal. All rights reserved.
//

#ifndef Camera_hpp
#define Camera_hpp
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace dao {
    namespace graphics {
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
            glm::vec3 mPosition;
            glm::vec3 mFront;
            glm::vec3 mUp;
            glm::vec3 mRight;
            glm::vec3 mWorldUp;
            
            float mYaw;
            float mPitch;
            float mMovementSpeed;
            float mMouseSensitivity;
            float mZoom;
        public:
            Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = YAW, float pitch = PITCH);
            Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch);
            
            inline glm::mat4 getViewMatrix() {
				return glm::lookAt(mPosition, mPosition + mFront, mUp);
            }
            
        private:
            void updateCameraVectors();
        };
    }
}

#endif /* Camera_hpp */
