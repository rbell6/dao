//
//  main.cpp
//  dao
//
//  Created by Richard Bell on 10/14/18.
//  Copyright © 2018 apocryphal. All rights reserved.
//
#include <iostream>
#include <stdio.h>
#include <time.h>
#include "src/graphics/window.hpp"
#include "src/math/Math.h"
#include "src/graphics/Shader.hpp"
#include "src/graphics/layers/TileLayer.hpp"
#include "src/graphics/Sprite.hpp"
#include "src/utils/Timer.h"
#include "src/graphics/Texture.hpp"

using namespace dao;
using namespace graphics;
using namespace math;
using namespace std;

#define TEST_50K 1
#define TEST_SHAPE 0

int main(void) {
	Window window("Dao", 960, 540);
	glClearColor(0, 0, 0, 1.0f); //glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
	
	Shader* shader = new Shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	TileLayer layer(shader);
	Texture* t1 = new Texture("/Users/rbell/tmp/rbell.jpg");
	Texture* t2 = new Texture("/Users/rbell/tmp/bandr.jpg");
	
	GLint tids[] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	shader->enable();
	shader->setUniform("textures", tids, 10);
	shader->setUniform("pr_matrix", Matrix4::orthographic(-16.0f, 16.0f, -9.0f, 9.0f, -1.0f, 1.0f));

#if TEST_50K
	for (float y{-9.0f}; y < 9.0f; y += 0.1f) {
		for (float x{-16.0f}; x < 16.0f; x += 0.1f) {
			Vector4 color = Vector4(rand() % 1000 / 1000.f, 0, 1, 1);
			layer.add(new Sprite(x, y, 0.09f, 0.09f, color));
		}
	}
#elif TEST_SHAPE
	auto color = Vector4(0, 1, 1, 1);
	layer.add(new Sprite(0, 0, 1, 5, color));
#else
	for (float y{-9.0f}; y < 9.0f; y++) {
		for (float x{-16.0f}; x < 16.0f; x++) {
			Vector4 color = Vector4(rand() % 1000 / 1000.f, 0, 1, 1);
			//layer.add(new Sprite(x, y, 0.9f, 0.9f, color));
			layer.add(new Sprite(x, y, 0.9f, 0.9f, rand() % 2 == 0 ? t1 : t2));
		}
	}
#endif
	
	Timer timer, time;
	long long t = 0;
	int fps{0}, frames{0};
	while (not window.closed()) {
		timer.reset();
		window.clear();
		double x, y;
		window.getMousePosition(x, y);
		shader->enable();
		shader->setUniform("light_pos", Vector2((float)(x * 32.0f / (window.getWidth()/2) - 16.0f), (float)(9.0f - y * 18.0f / (window.getHeight()/2))));
		
		layer.render();
		
		window.update();
		
		frames++;
		if (time.elapsed().count() - t > 1000) {
			t += 1000;
			fps = frames;
			frames = 0;
			printf("%d fps\n", fps);
			cout << "width: " << window.getWidth() << " height: " << window.getHeight() << endl;
		}
	}
	delete t1;
	delete t2;
	delete shader;
	return 0;
}
