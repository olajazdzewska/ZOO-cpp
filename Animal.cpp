//
//  Animal.cpp
//  ZOO
//
//  Created by Aleksandra Jażdżewska on 07/04/2023.
//

#include "Animal.hpp"
#include <stdlib.h>



Animal::Animal(Species specieEnum, World *world, int strength, int initiative, int positionY, int positionX, int age)
: Organism(specieEnum, world, strength, initiative, positionY, positionX, age){
};

void Animal::action(){
    setAge(getAge() + 1); //increasing age in ture
    
    int x = this->getPositionX();
    int y = this->getPositionY();
    const int random = rand() % 4;
    this->setPrevPositionX(x);
    this->setPrevPositionY(y);
    switch (random){
        case 0:
            if(isCellValid(y, x+1)){
                if(isCellOccupied(y, x+1))
                    collisions(y, x+1);
                else{
                    if(isSosnowskyNearby(y, x+1)){ //if sosnowsky is nearby then it kills animal
                        getWorld()->remove(this);
                        getWorld()->getGrid()[y][x] = NULL;
                    }
                    else{
                        this->setPositionX(x+1);
                        this->getWorld()->getGrid()[getPrevPositionY()][getPrevPositionX()] = NULL;
                    }
                }
            }
            else
                this->action();
            break;
        case 1:
            if(isCellValid(y, x-1)){
                if(isCellOccupied(y, x-1))
                    collisions(y, x-1);
                else{
                    if(isSosnowskyNearby(y, x-1)){ //if sosnowsky is nearby then it kills animal
                        getWorld()->remove(this);
                        getWorld()->getGrid()[y][x] = NULL;
                    }
                    else{
                        this->setPositionX(x-1);
                        this->getWorld()->getGrid()[getPrevPositionY()][getPrevPositionX()] = NULL;
                    }
                }
            }
            else
                this->action();
            break;
        case 2:
            if(isCellValid(y+1, x)){
                if(isCellOccupied(y+1, x))
                    collisions(y+1, x);
                else{
                    if(isSosnowskyNearby(y+1, x)){ //if sosnowsky is nearby then it kills animal
                        getWorld()->remove(this);
                        getWorld()->getGrid()[y][x] = NULL;
                    }
                    else{
                        this->setPositionY(y+1);
                        this->getWorld()->getGrid()[getPrevPositionY()][getPrevPositionX()] = NULL;
                    }
                }
            }
            else
                this->action();
            break;
        case 3:
            if(isCellValid(y-1, x)){
                if(isCellOccupied(y-1, x))
                    collisions(y-1, x);
                else{
                    if(isSosnowskyNearby(y-1, x)){ //if sosnowsky is nearby then it kills animal
                        getWorld()->remove(this);
                        getWorld()->getGrid()[y][x] = NULL;
                    }
                    else{
                        this->setPositionY(y-1);
                        this->getWorld()->getGrid()[getPrevPositionY()][getPrevPositionX()] = NULL;
                    }
                }
            }
            else
                this->action();
            break;
    }
    
};

Animal::~Animal(){};
