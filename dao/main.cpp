//
//  main.cpp
//  dao
//
//  Created by Richard Bell on 10/14/18.
//  Copyright © 2018 apocryphal. All rights reserved.
//

#include <stdio.h>
#include "src/graphics/window.hpp"
#include "src/math/Math.h"
#include "src/graphics/Shader.hpp"
#include "src/graphics/layers/TileLayer.hpp"
//#include "src/graphics/Simple2DRenderer.hpp"
//#include "src/graphics/BatchRenderer2D.hpp"
//#include "src/graphics/Renderable2D.hpp"
//#include "src/graphics/StaticSprite.hpp"
#include "src/graphics/Sprite.hpp"
#include "src/utils/Timer.h"

using namespace dao;
using namespace graphics;
using namespace math;
using namespace std;

#define BATCH_RENDERER 1

int main(void) {
    
    Window window("Dao", 960, 540);
	glClearColor(0, 0, 0, 1.0f); //glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
	
	Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader.enable();
	TileLayer layer(&shader);
	auto color = Vector4(0.8f, 0.2f, 0.8f, 1);
	layer.add(new Sprite(0, 0, 2, 2, color));

	Timer timer, time;
	long long t = 0;
	int fps{0}, frames{0};
	while (not window.closed()) {
		timer.reset();
		window.clear();
		double x, y;
		window.getMousePosition(x, y);
		shader.setUniform("light_pos", Vector2((float)(x * 32.0f / 960.0f - 16.0f), (float)(9.0f - y * 18.0f / 540.0f)));
		
		layer.render();
		
        window.update();
		
		frames++;
		if (time.elapsed().count() - t > 1000) {
			t += 1000;
			fps = frames;
			frames = 0;
			printf("%d fps\n", fps);
		}
	}
	
    return 0;
}
