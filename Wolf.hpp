//
//  Wolf.hpp
//  ZOO
//
//  Created by Aleksandra Jażdżewska on 11/04/2023.
//
#pragma once
#ifndef Wolf_hpp
#define Wolf_hpp

#include <stdio.h>
#include "Animal.hpp"
#endif /* Wolf_hpp */
#include <string>
using namespace std;

class Wolf : public Animal{
    bool justBorn = false;
public:
    Wolf();
    Wolf(World* world, int positionX, int positionY, int age);
    virtual void draw() override;
    string specieName() override;
    virtual Organism* breed(int y, int x) override;
    ~Wolf();
};
