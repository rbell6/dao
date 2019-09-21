//
//  main.cpp
//  dao
//
//  Created by Richard Bell on 10/14/18.
//  Copyright © 2018 apocryphal. All rights reserved.
//
#include "src/app/Sprite50K.h"

int main(void) {
    dao::app = new dao::Sprite50K();
    return dao::app->run();
}
