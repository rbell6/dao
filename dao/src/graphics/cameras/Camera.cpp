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
        Camera::Camera(math::Vector3 position, math::Vector3 up, float yaw, float pitch) : mFront(math::Vector3(0.0f, 0.0f, -1.0f)), mMovementSpeed(SPEED), mMouseSensitivity(SENSITIVITY), mZoom(ZOOM) {
            mPosition = position;
            mWorldUp = up;
            mYaw = yaw;
            mPitch = pitch;
            updateCameraVectors();
        }
        
        Camera::Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch) : mFront(math::Vector3(0.0f, 0.0f, -1.0f)), mMovementSpeed(SPEED), mMouseSensitivity(SENSITIVITY), mZoom(ZOOM) {
            mPosition = math::Vector3(posX, posY, posZ);
            mWorldUp = math::Vector3(upX, upY, upZ);
            mYaw = yaw;
            mPitch = pitch;
            updateCameraVectors();
        }
        
        void Camera::updateCameraVectors() {
            Vector3 front;
            front.data.x = cos(toRadians(mYaw)) * cos(toRadians(mPitch));
            front.data.y = sin(toRadians(mPitch));
            front.data.z = sin(toRadians(mYaw)) * cos(toRadians(mPitch));
            mFront = front.normalized();
            mRight = Vector3::cross(mFront, mWorldUp).normalized();
            mUp = Vector3::cross(mRight, mFront).normalized();
        }
    }
}
