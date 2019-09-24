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
//#include "src/app/AnimationApp.hpp"

int main(void) {
//	dao::app = new dao::AnimationApp();
	dao::app = new dao::Sprite50K();
    return dao::app->run();
}
