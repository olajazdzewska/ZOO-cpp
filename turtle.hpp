//
//  turtle.hpp
//  ZOO
//
//  Created by Aleksandra Jażdżewska on 13/04/2023.
//
#pragma once
#ifndef turtle_hpp
#define turtle_hpp

#include <stdio.h>

#endif /* turtle_hpp */
#include "Animal.hpp"


#include <stdio.h>

using namespace std;

class Turtle : public Animal{
    bool justBorn = false;
public:
    Turtle();
    Turtle(World* world, int positionX, int positionY, int age);
    virtual void draw() override;
    virtual void action() override;
    virtual string specieName() override;
    virtual Organism* breed(int y, int x) override;
    ~Turtle();
};
