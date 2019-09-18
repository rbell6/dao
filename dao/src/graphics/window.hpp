//
//  window.hpp
//  dao
//
//  Created by Richard Bell on 10/14/18.
//  Copyright © 2018 apocryphal. All rights reserved.
//
#pragma once
#include <stdio.h>
#include <string.h>
#include <OpenGL/gl3.h>
#include <OpenGL/gl3ext.h>
#include <GLFW/glfw3.h>

namespace dao {
    namespace graphics {
		
#define MAX_KEYS 1024
#define MAX_BUTTONS 32
		
        class Window {
            int mWidth, mHeight;
            const char* mTitle;
			GLFWwindow* mWindow{nullptr};
			int resize_workaround;
			bool mKeys[MAX_KEYS];
			bool mKeyState[MAX_KEYS];
			bool mKeyTyped[MAX_KEYS];
			bool mMouseButtons[MAX_BUTTONS];
			bool mMouseState[MAX_BUTTONS];
			bool mMouseClicked[MAX_BUTTONS];
			double mx, my;
        public:
            Window(const char* title, int width, int height);
            ~Window();
			void resize(int width, int height) const;
            void clear() const;
            void update();
            bool closed() const;
			bool isKeyPressed(unsigned int keycode) const;
			bool isKeyTyped(unsigned int keycode) const;
			bool isMouseButtonPressed(unsigned int button) const;
			bool isMouseButtonClicked(unsigned int button) const;
			void getMousePosition(double& x, double& y) const;
			inline int getWidth() const { return mWidth; }
			inline int getHeight() const { return mHeight; }
        private:
            bool init();
			friend void window_resize(GLFWwindow* window, int width, int height);
			friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
			friend void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
			friend void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
        };
    }
}
