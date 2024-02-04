//
//  Animal.hpp
//  ZOO
//
//  Created by Aleksandra Jażdżewska on 07/04/2023.
//
#pragma once
#ifndef Animal_hpp
#define Animal_hpp

#include <stdio.h>
#include "Organism.hpp"
#include "World.hpp"

#endif /* Animal_hpp */

class Plant : public Organism {
public:
    virtual void action() override;
    Plant();
    Plant(Species specieEnum, World *world = NULL, int strength = 0, int positionY = -1, int positionX = -1, int age = 0);
    ~Plant();
    
};
