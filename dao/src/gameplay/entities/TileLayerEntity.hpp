//
//  TileLayerEntity.hpp
//  dao
//
//  Created by Richard Bell on 9/18/19.
//  Copyright © 2019 apocryphal. All rights reserved.
//

#ifndef TileLayerEntity_hpp
#define TileLayerEntity_hpp
#include "Entity.hpp"
#include "graphics/layers/TileLayer.hpp"

namespace dao {
    namespace gameplay {
        class TileLayerEntity : public Entity {
            graphics::TileLayer mLayer;
        public:
            TileLayerEntity(graphics::ShaderProgram* shader): mLayer(shader) {}
            TileLayerEntity(graphics::TileLayer layer): mLayer(layer) {}
            
            void update() {
                mLayer.render();
            }
            
            inline graphics::TileLayer& getTileLayer() { return mLayer; }
        };
    }
}

#endif /* TileLayerEntity_hpp */
