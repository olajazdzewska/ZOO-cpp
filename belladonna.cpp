//
//  belladonna.cpp
//  ZOO
//
//  Created by Aleksandra Jażdżewska on 13/04/2023.
//

#include "belladonna.hpp"
#include <iostream>
#include <string>
using namespace std;

Belladonna::Belladonna(World *world, int positionX, int positionY, int age)
: Plant(belladonna, world, 0, positionY, positionX, age){
};

void Belladonna::draw(){
    cout << "b";
};

string Belladonna::specieName(){
    return "belladonna";
};

Organism* Belladonna::breed(int y, int x){
    return new Belladonna(getWorld(), x, y, 1);
};

Belladonna::~Belladonna(){};
