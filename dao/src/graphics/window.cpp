//
//  window.cpp
//  dao
//
//  Created by Richard Bell on 10/14/18.
//  Copyright © 2018 apocryphal. All rights reserved.
//
#include "window.hpp"

namespace dao {
    namespace graphics {
		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
		void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
		
        Window::Window(const char* title, int width, int height) {
            mTitle = title;
            mWidth = width;
            mHeight = height;
			resize_workaround = 0;
            if (!init()) glfwTerminate();
			for (int i = 0; i < MAX_KEYS; i++) {
				mKeys[i] = false;
				mKeyState[i] = false;
				mKeyTyped[i] = false;
			}
			for (int i = 0; i < MAX_BUTTONS; i++) {
				mMouseButtons[i] = false;
				mMouseState[i] = false;
				mMouseClicked[i] = false;
			}
        }
        
        Window::~Window() {
            glfwTerminate();
        }
		
		void window_resize(GLFWwindow* window, int width, int height) {
			glViewport(0, 0, width, height);
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->mWidth = width;
			win->mHeight = height;
		}
        
        bool Window::init() {
            if (!glfwInit()) {
                printf("Failed to init GLFW");
                return false;
            }
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
			glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
            mWindow = glfwCreateWindow(mWidth, mHeight, mTitle, nullptr, nullptr);
            if (!mWindow) {
                glfwTerminate();
                printf("could not init GLFW window");
                return false;
            }
            glfwMakeContextCurrent(mWindow);
			glfwSetWindowUserPointer(mWindow, this);
//			glfwSetWindowSizeCallback(mWindow, window_resize);
			glfwSetFramebufferSizeCallback(mWindow, window_resize);
			glfwSetKeyCallback(mWindow, key_callback);
			glfwSetMouseButtonCallback(mWindow, mouse_button_callback);
			glfwSetCursorPosCallback(mWindow, cursor_position_callback);
			glfwSwapInterval(0);
			
			if (glewInit() != GLEW_OK) {
				printf("could not init glew");
				return false;
			}
            return true;
        }
		
		bool Window::isKeyPressed(unsigned int keycode) const {
			if (keycode >= MAX_KEYS) return false; // TODO: log this
			return mKeys[keycode];
		}
		
		bool Window::isKeyTyped(unsigned int keycode) const {
			if (keycode >= MAX_KEYS) return false;
			return mKeyTyped[keycode];
		}
		
		bool Window::isMouseButtonPressed(unsigned int button) const {
			if (button <= MAX_BUTTONS) return false;
			return mMouseButtons[button];
		}
		
		bool Window::isMouseButtonClicked(unsigned int button) const {
			if (button <= MAX_BUTTONS) return false;
			return mMouseClicked[button];
		}
		
		void Window::getMousePosition(double& x, double& y) const {
			x = mx;
			y = my;
		}
		
		void Window::resize(int width, int height) const {
			glfwSetWindowSize(mWindow, width, height);
		}
        
        void Window::clear() const {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }
        
        void Window::update() {
			for (int i = 0; i < MAX_KEYS; i++)
				mKeyTyped[i] = mKeys[i] && !mKeyState[i];
			for (int i = 0; i < MAX_BUTTONS; i++)
				mMouseClicked[i] = mMouseButtons[i] && !mMouseState[i];
			memcpy(mKeyState, mKeys, MAX_KEYS);
			memcpy(mMouseState, mMouseButtons, MAX_BUTTONS);
			
			GLenum error = glGetError();
			if (error != GL_NO_ERROR) {
				printf("OpenGL Error: %d\n", error);
			}
			// workaround mojave issue
			if (resize_workaround < 2) {
				int xpos, ypos;
				glfwGetWindowPos(mWindow, &xpos, &ypos);
				glfwSetWindowPos(mWindow, xpos + 1, ypos + 1);
				resize_workaround++;
			}
            glfwPollEvents();
			glfwGetFramebufferSize(mWindow, &mWidth, &mHeight);
			glViewport(0, 0, mWidth, mHeight);
            glfwSwapBuffers(mWindow);
        }
        
        bool Window::closed() const {
            return glfwWindowShouldClose(mWindow) == 1;
        }
		
		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
			auto win = (Window*) glfwGetWindowUserPointer(window);
			win->mKeys[key] = action != GLFW_RELEASE;
		}
		
		void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
			auto win = (Window*) glfwGetWindowUserPointer(window);
			win->mMouseButtons[button] = action != GLFW_RELEASE;
		}
		
		void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
			auto win = (Window*) glfwGetWindowUserPointer(window);
			win->mx = xpos;
			win->my = ypos;
		}
    }
}
