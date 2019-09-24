//
//  Camera.cpp
//  dao
//
//  Created by Richard Bell on 9/17/19.
//  Copyright © 2019 apocryphal. All rights reserved.
//

#include "Camera.hpp"
//https://learnopengl.com/code_viewer_gh.php?code=includes/learnopengl/camera.h
namespace dao {
    namespace graphics {
        Camera::Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch) : mFront(glm::vec3(0.0f, 0.0f, -1.0f)), mMovementSpeed(SPEED), mMouseSensitivity(SENSITIVITY), mZoom(ZOOM) {
            mPosition = position;
            mWorldUp = up;
            mYaw = yaw;
            mPitch = pitch;
            updateCameraVectors();
        }
        
        Camera::Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch) : mFront(glm::vec3(0.0f, 0.0f, -1.0f)), mMovementSpeed(SPEED), mMouseSensitivity(SENSITIVITY), mZoom(ZOOM) {
            mPosition = glm::vec3(posX, posY, posZ);
            mWorldUp = glm::vec3(upX, upY, upZ);
            mYaw = yaw;
            mPitch = pitch;
            updateCameraVectors();
        }
        
        void Camera::updateCameraVectors() {
            glm::vec3 front;
            front.x = cos(glm::radians(mYaw)) * cos(glm::radians(mPitch));
            front.y = sin(glm::radians(mPitch));
            front.z = sin(glm::radians(mYaw)) * cos(glm::radians(mPitch));
			mFront = glm::normalize(front);
			mRight = glm::normalize(glm::cross(mFront, mWorldUp));
			mUp = glm::normalize(glm::cross(mRight, mFront));
        }
    }
}
