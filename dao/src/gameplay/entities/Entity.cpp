//
//  Entity.cpp
//  dao
//
//  Created by Richard Bell on 9/18/19.
//  Copyright © 2019 apocryphal. All rights reserved.
//

#include "Entity.hpp"

namespace dao {
    namespace gameplay {
        
        void Entity::update() {
            for (auto child : mChildren) {
                child->update();
            }
            for (auto it : mComponents) {
                it.second->update();
            }
        }
        
        void Entity::addChild(Entity* entity) {
            if (std::find(mChildren.begin(), mChildren.end(), entity) != mChildren.end()) {
                mChildren.push_back(entity);
                mChildrenByType[entity->TYPE].push_back(entity);
            }
        }
        
        void Entity::removeAllChildren() {
            for (auto child : mChildren) {
                removeChild(child);
            }
        }
        
        void Entity::removeChild(Entity* entity) {
            entity->setParent(nullptr);
            mChildren.remove(entity);
            mChildrenByType[entity->TYPE].remove(entity);
        }
        
        void Entity::removeFromParent() {
            mParent->removeChild(this);
            mParent = nullptr;
        }
    }
}
