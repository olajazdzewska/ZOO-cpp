//
//  SosnowskyHogweed.cpp
//  ZOO
//
//  Created by Aleksandra Jażdżewska on 13/04/2023.
//

#include "SosnowskyHogweed.hpp"
#include <iostream>
#include <string>
using namespace std;

SosnowskyHogweed::SosnowskyHogweed(World *world, int positionX, int positionY, int age)
: Plant(Sosnowsky, world, 0, positionY, positionX, age){
};

void SosnowskyHogweed::draw(){
    cout << "s";
};

string SosnowskyHogweed::specieName(){
    return "Sosnowsky_Hogweed";
};

Organism* SosnowskyHogweed::breed(int y, int x){
    return new SosnowskyHogweed(this->getWorld(), x, y, 1);
};

SosnowskyHogweed::~SosnowskyHogweed(){};
