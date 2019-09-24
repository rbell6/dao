//
//  main.cpp
//  dao
//
//  Created by Richard Bell on 10/14/18.
//  Copyright © 2018 apocryphal. All rights reserved.
//
#include <iostream>
#include <stdio.h>
#include "app/Sprite50K.h"
#include "src/app/AnimationApp.hpp"

int main(void) {
#ifdef DEBUG
	std::cout << "which app do you want to run?" << std::endl;
	std::cout << "\t1: 50k+ Sprites" << std::endl;
	std::cout << "\t2: Animation experiments\n" << std::endl;
	std::cout << "> ";
	int selection = getchar();
	switch (selection) {
		default:
		case 1:
			dao::app = new dao::Sprite50K();
			break;
		case 2:
			dao::app = new dao::AnimationApp();
	}
#else
	dao::app = new dao::Sprite50K();
#endif
	
    return dao::app->run();
}
