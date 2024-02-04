//
//  antelope.cpp
//  ZOO
//
//  Created by Aleksandra Jażdżewska on 13/04/2023.
//

#include "antelope.hpp"
#include <iostream>
#include <string>
using namespace std;

Antelope::Antelope(World *world, int positionX, int positionY, int age)
: Animal(antelope, world, 4, 4, positionX, positionY, age){
};

void Antelope::draw(){
    cout << "A";
};

string Antelope::specieName(){
    return "antelope";
};

Organism* Antelope::breed(int y, int x){
    return new Antelope(this->getWorld(), x, y, 1);
};

void Antelope::action(){
    setAge(getAge() + 1); //increasing age in ture
    
    int x = this->getPositionX();
    int y = this->getPositionY();
    const int random = rand() % 8;
    this->setPrevPositionX(x);
    this->setPrevPositionY(y);
    switch (random){
        case 0:
            if(isCellValid(y, x+2)){
                if(isCellOccupied(y, x+2))
                    collisions(y, x+2);
                else{
                    if(isSosnowskyNearby(y, x+2)){ //if sosnowsky is nearby then it kills animal
                        getWorld()->remove(this);
                        getWorld()->getGrid()[y][x] = NULL;
                    }
                    else{
                        this->setPositionX(x+2);
                        this->getWorld()->getGrid()[getPrevPositionY()][getPrevPositionX()] = NULL;
                    }
                }
            }
            else
                this->action();
            break;
        case 1:
            if(isCellValid(y, x-2)){
                if(isCellOccupied(y, x-2))
                    collisions(y, x-2);
                else{
                    if(isSosnowskyNearby(y, x-2)){ //if sosnowsky is nearby then it kills animal
                        getWorld()->remove(this);
                        getWorld()->getGrid()[y][x] = NULL;
                    }
                    else{
                        this->setPositionX(x-2);
                        this->getWorld()->getGrid()[getPrevPositionY()][getPrevPositionX()] = NULL;
                    }
                }
            }
            else
                this->action();
            break;
        case 2:
            if(isCellValid(y+2, x)){
                if(isCellOccupied(y+2, x))
                    collisions(y+2, x);
                else{
                    if(isSosnowskyNearby(y+2, x)){ //if sosnowsky is nearby then it kills animal
                        getWorld()->remove(this);
                        getWorld()->getGrid()[y][x] = NULL;
                    }
                    else{
                        this->setPositionY(y+2);
                        this->getWorld()->getGrid()[getPrevPositionY()][getPrevPositionX()] = NULL;
                    }
                }
            }
            else
                this->action();
            break;
        case 3:
            if(isCellValid(y-2, x)){
                if(isCellOccupied(y-2, x))
                    collisions(y-2, x);
                else{
                    if(isSosnowskyNearby(y-2, x)){ //if sosnowsky is nearby then it kills animal
                        getWorld()->remove(this);
                        getWorld()->getGrid()[y][x] = NULL;
                    }
                    else{
                        this->setPositionY(y-2);
                        this->getWorld()->getGrid()[getPrevPositionY()][getPrevPositionX()] = NULL;
                    }
                }
            }
            else
                this->action();
            break;
        case 4:
            if(isCellValid(y+1, x+1)){
                if(isCellOccupied(y+1, x+1))
                    collisions(y+1, x+1);
                else{
                    if(isSosnowskyNearby(y+1, x+1)){ //if sosnowsky is nearby then it kills animal
                        getWorld()->remove(this);
                        getWorld()->getGrid()[y][x] = NULL;
                    }
                    else{
                        this->setPositionX(x+1);
                        this->setPositionY(y+1);
                        this->getWorld()->getGrid()[getPrevPositionY()][getPrevPositionX()] = NULL;
                    }
                }
            }
            else
                this->action();
            break;
        case 5:
            if(isCellValid(y+1, x-1)){
                if(isCellOccupied(y+1, x-1))
                    collisions(y+1, x-1);
                else{
                    if(isSosnowskyNearby(y+1, x-1)){ //if sosnowsky is nearby then it kills animal
                        getWorld()->remove(this);
                        getWorld()->getGrid()[y][x] = NULL;
                    }
                    else{
                        this->setPositionX(x-1);
                        this->setPositionY(y+1);
                        this->getWorld()->getGrid()[getPrevPositionY()][getPrevPositionX()] = NULL;
                    }
                }
            }
            else
                this->action();
            break;
        case 6:
            if(isCellValid(y-1, x-1)){
                if(isCellOccupied(y-1, x-1))
                    collisions(y-1, x-1);
                else{
                    if(isSosnowskyNearby(y-1, x-1)){ //if sosnowsky is nearby then it kills animal
                        getWorld()->remove(this);
                        getWorld()->getGrid()[y][x] = NULL;
                    }
                    else{
                        this->setPositionX(x-1);
                        this->setPositionY(y-1);
                        this->getWorld()->getGrid()[getPrevPositionY()][getPrevPositionX()] = NULL;
                    }
                }
            }
            else
                this->action();
            break;
        case 7:
            if(isCellValid(y-1, x+1)){
                if(isCellOccupied(y-1, x+1))
                    collisions(y-1, x+1);
                else{
                    if(isSosnowskyNearby(y-1, x+1)){ //if sosnowsky is nearby then it kills animal
                        getWorld()->remove(this);
                        getWorld()->getGrid()[y][x] = NULL;
                    }
                    else{
                        this->setPositionX(x+1);
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

Antelope::~Antelope(){};
