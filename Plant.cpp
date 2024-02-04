//
//  Animal.cpp
//  ZOO
//
//  Created by Aleksandra Jażdżewska on 07/04/2023.
//

#include "Plant.hpp"
#include <stdlib.h>



Plant::Plant(Species specieEnum, World *world, int strength, int positionY, int positionX, int age)
: Organism(specieEnum, world, strength, 0, positionY, positionX, age){
};

void Plant::action(){
    int x = this->getPositionX();
    int y = this->getPositionY();
    const int random = rand()%4;
    const int probOfSow = rand()%4;
    if(probOfSow<=1){ //sowing with certain probability
        switch (random){
            case 0:
                if(isCellValid(y, x+1)){
                    if(isCellOccupied(y, x+1))
                        break;
                    else{
                        breed(y, x+1);
                        getWorld()->getGrid()[y][x+1] = breed(y, x+1);
                        getWorld()->setQuantityOfOrganisms(getWorld()->getQuantityOfOrganisms() + 1);
                    }
                }
                else
                    this->action();
                break;
            case 1:
                if(isCellValid(y, x-1)){
                    if(isCellOccupied(y, x-1))
                        break;
                    else{
                        breed(y, x-1);
                        getWorld()->getGrid()[y][x] = breed(y, x-1);
                        getWorld()->setQuantityOfOrganisms(getWorld()->getQuantityOfOrganisms() + 1);
                    }
                }
                else
                    this->action();
                break;
            case 2:
                if(isCellValid(y+1, x)){
                    if(isCellOccupied(y+1, x))
                        break;
                    else{
                        breed(y+1, x);
                        getWorld()->getGrid()[y][x] = breed(y+1, x);
                        getWorld()->setQuantityOfOrganisms(getWorld()->getQuantityOfOrganisms() + 1);
                    }
                }
                else
                    this->action();
                break;
            case 3:
                if(isCellValid(y-1, x)){
                    if(isCellOccupied(y-1, x))
                        break;
                    else{
                        breed(y-1, x);
                        getWorld()->getGrid()[y][x] = breed(y-1, x);
                        getWorld()->setQuantityOfOrganisms(getWorld()->getQuantityOfOrganisms() + 1);
                    }
                }
                else
                    this->action();
                break;
        }
    }
};

Plant::~Plant(){};
