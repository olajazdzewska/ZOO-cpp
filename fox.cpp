//
//  fox.cpp
//  ZOO
//
//  Created by Aleksandra Jażdżewska on 13/04/2023.
//

#include "fox.hpp"
#include "World.hpp"
#include <iostream>
#include <string>

using namespace std;

Fox::Fox(World *world, int positionX, int positionY, int age)
: Animal(fox, world, 3, 7, positionX, positionY, age){
};

void Fox::draw(){
    cout << "F";
};

string Fox::specieName(){
    return "fox";
};

Organism* Fox::breed(int y, int x){
    return new Fox(this->getWorld(), x, y, 1);
};

bool Fox::checkIfStronger(int x, int y){
    if(getWorld()->getGrid()[y][x+1] == NULL )
        return false;
    if(getWorld()->getGrid()[y][x+1] != NULL && getWorld()->getGrid()[y][x+1]->getStrength() <= this->getStrength())
        return false;
    else
        return true;
}

void Fox::action(){
    setAge(getAge() + 1); //increasing age in ture
    
    int x = this->getPositionX();
    int y = this->getPositionY();
    const int random = rand() % 4;
    this->setPrevPositionX(x);
    this->setPrevPositionY(y);
    if(!checkIfStronger(x+1, y) || !checkIfStronger(x-1, y) || !checkIfStronger(x, y+1) || !checkIfStronger(x, y-1)){ //check if fox is not sourranded by stronger animals
        switch (random){
            case 0:
                if(isCellValid(y, x+1)){ //check if cell is on the grid, if not, do axtion and choose valid cell
                    if(isCellOccupied(y, x+1) && getWorld()->getGrid()[y][x+1]->getStrength() <= getStrength())
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
                    if(isCellOccupied(y, x-1) && getWorld()->getGrid()[y][x-1]->getStrength() <= getStrength())
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
                    if(isCellOccupied(y+1, x) && getWorld()->getGrid()[y+1][x]->getStrength() <= getStrength())
                        break;
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
                    if(isCellOccupied(y-1, x) && getWorld()->getGrid()[y-1][x]->getStrength() <= getStrength())
                        break;
                    else{
                        if(isSosnowskyNearby(y-1, x)){ //if sosnowsky is nearby then it kills animal
                            getWorld()->remove(this);
                            getWorld()->getGrid()[y][x] = NULL;
                        }
                        else {
                            this->setPositionY(y-1);
                            this->getWorld()->getGrid()[getPrevPositionY()][getPrevPositionX()] = NULL;
                        }
                    }
                }
                else
                    this->action();
                break;
        }
    }
};


Fox::~Fox(){};
