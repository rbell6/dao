//
//  Group.hpp
//  dao
//
//  Created by Richard Bell on 11/28/18.
//  Copyright © 2018 apocryphal. All rights reserved.
//

#ifndef Group_hpp
#define Group_hpp
#include <vector>
#include <glm/glm.hpp>
#include "../Renderable2D.hpp"

namespace dao {
	
	namespace graphics {
		class Group : public Renderable2D {
			std::vector<Renderable2D*> mChildren;
			glm::mat4 mTransform;
		public:
			Group(glm::mat4 transform);
			~Group();
			void add(Renderable2D* child);
			void submit(Renderer2D* renderer) const override;
		};
	}
}

#endif /* Group_hpp */
