//
//  Wolf.cpp
//  ZOO
//
//  Created by Aleksandra Jażdżewska on 11/04/2023.
//

#include "Wolf.hpp"
#include <iostream>
#include <string>
using namespace std;


Wolf::Wolf(World *world, int positionX, int positionY, int age)
: Animal(wolf, world, 9, 5, positionX, positionY, age){
};

void Wolf::draw(){
    cout << "W";
};

string Wolf::specieName(){
    return "wolf";
};

Organism* Wolf::breed(int y, int x){
    return new Wolf(this->getWorld(), x, y, 1);
};

Wolf::~Wolf(){};
