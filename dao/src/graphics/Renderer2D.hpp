//
//  Rederer2D.hpp
//  dao
//
//  Created by Richard Bell on 11/25/18.
//  Copyright © 2018 apocryphal. All rights reserved.
//

#ifndef Renderer2D_hpp
#define Renderer2D_hpp
#include <OpenGL/gl3.h>
#include <OpenGL/gl3ext.h>
#include <vector>

namespace dao {
	namespace graphics {
		
		class Renderable2D; // trying to avoid recursive #include
		
		class Renderer2D {
		protected:
			std::vector<glm::mat4> mTransformationStack;
			const glm::mat4* mTransformationBack;
			Renderer2D() {
				mTransformationStack.push_back(glm::mat4(1.0f));
				mTransformationBack = &mTransformationStack.back();
			}
		public:
			void push(glm::mat4 matrix, bool replace = false) {
				mTransformationStack.push_back(replace ? matrix : mTransformationStack.back() * matrix);
				mTransformationBack = &mTransformationStack.back();
			}
			
			void pop() {
				if (mTransformationStack.size() > 1) {
					mTransformationStack.pop_back();
				}
				mTransformationBack = &mTransformationStack.back();
				//todo: should log this
			}
			
			virtual ~Renderer2D() = default;
			virtual void begin() {};
			virtual void end() {};
			virtual void submit(const Renderable2D* renderable) = 0;
			virtual void flush() = 0;
		};
	}
}

#endif /* Rederer2D_hpp */
