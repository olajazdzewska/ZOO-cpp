//
//  grass.cpp
//  ZOO
//
//  Created by Aleksandra Jażdżewska on 13/04/2023.
//

#include "grass.hpp"
#include <iostream>
#include <string>
using namespace std;

Grass::Grass(World *world, int positionX, int positionY, int age)
: Plant(grass, world, 0, positionY, positionX, age){
};

void Grass::draw(){
    cout << "~";
};

string Grass::specieName(){
    return "grass";
};


Organism* Grass::breed(int y, int x){
    return new Grass(this->getWorld(), x, y, 1);
};

Grass::~Grass(){};
