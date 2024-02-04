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

class Animal : public Organism {
public:
    virtual void action() override;
    Animal();
    Animal(Species specieEnum, World *world = NULL, int strength = 0, int initiative = 0, int positionX = -1, int positionY = -1, int age = 0);
     ~Animal();
    
};
