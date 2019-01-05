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
#include "../Renderable2D.hpp"
#include "../../math/Math.h"
using namespace std;

namespace dao {
	using namespace math;
	
	namespace graphics {
		class Group : public Renderable2D {
			vector<Renderable2D*> mChildren;
			Matrix4 mTransform;
		public:
			Group(const Matrix4& transform);
			~Group();
			void add(Renderable2D* child);
			void submit(Renderer2D* renderer) const override;
		};
	}
}

#endif /* Group_hpp */
