//
//  sheep.cpp
//  ZOO
//
//  Created by Aleksandra Jażdżewska on 13/04/2023.
//
#pragma once
#include "sheep.hpp"
#include <iostream>
#include <string>
using namespace std;

Sheep::Sheep(World *world, int positionX, int positionY, int age)
: Animal(sheep, world, 4, 4, positionX, positionY, age){
};


void Sheep::draw(){
    cout << "S";
};

string Sheep::specieName(){
    return "sheep";
}

Organism* Sheep::breed(int y, int x){
    return new Sheep(this->getWorld(), x, y, 1);
};

Sheep::~Sheep(){};
