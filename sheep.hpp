//
//  sheep.hpp
//  ZOO
//
//  Created by Aleksandra Jażdżewska on 13/04/2023.
//
#pragma once
#ifndef sheep_hpp
#define sheep_hpp

#include <stdio.h>

#endif /* sheep_hpp */
#include "Animal.hpp"
#include <string>
using namespace std;

class Sheep : public Animal{
    bool justBorn = false;
public:
    Sheep();

    Sheep(World* world, int positionX, int positionY, int age);
    virtual void draw() override;
    virtual string specieName() override;
    virtual Organism* breed(int y, int x) override;

    ~Sheep();
};
