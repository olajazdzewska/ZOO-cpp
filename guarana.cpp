//
//  guarana.cpp
//  ZOO
//
//  Created by Aleksandra Jażdżewska on 13/04/2023.
//

#include "guarana.hpp"
#include <iostream>
#include <string>
using namespace std;

Guarana::Guarana(World *world, int positionX, int positionY, int age)
: Plant(guarana, world, 0, positionY, positionX, age){
};

void Guarana::draw(){
    cout << "g";
};

string Guarana::specieName(){
    return "guarana";
};

Organism* Guarana::breed(int y, int x){
    return new Guarana(this->getWorld(), x, y, 1);
};

Guarana::~Guarana(){};
