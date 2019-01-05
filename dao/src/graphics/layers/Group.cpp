//
//  Group.cpp
//  dao
//
//  Created by Richard Bell on 11/28/18.
//  Copyright © 2018 apocryphal. All rights reserved.
//

#include "Group.hpp"

namespace dao {
	namespace graphics {
		
		Group::Group(const Matrix4& transform): mTransform(transform) {}
		Group::~Group() {
			for (auto child : mChildren) {
				delete child;
			}
		}
		void Group::add(Renderable2D* child) {
			mChildren.push_back(child);
		}
		
		void Group::submit(Renderer2D* renderer) const {
			renderer->push(mTransform);
			for (const auto child : mChildren) {
				renderer->submit(child);
			}
			renderer->pop();
		}
	}
}
