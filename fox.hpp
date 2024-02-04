//
//  fox.hpp
//  ZOO
//
//  Created by Aleksandra Jażdżewska on 13/04/2023.
//
#pragma once
#ifndef fox_hpp
#define fox_hpp

#include <stdio.h>
#include "Animal.hpp"
#include "World.hpp"
#endif /* fox_hpp */
#include <string>
using namespace std;

class Fox : public Animal{
    bool justBorn = false;
public:
    Fox();
    Fox(World* world, int positionX, int positionY, int age);
    bool checkIfStronger(int x, int y);
    virtual void draw() override;
    virtual void action() override;
    bool isSpecieStronger(int y, int x);
    virtual string specieName() override;
    virtual Organism* breed(int y, int x) override;
    ~Fox();
};
