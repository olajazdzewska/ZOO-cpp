//
//  turtle.cpp
//  ZOO
//
//  Created by Aleksandra Jażdżewska on 13/04/2023.
//

#include "turtle.hpp"
#include <iostream>
#include <string>

using namespace std;

Turtle::Turtle(World *world, int positionX, int positionY, int age)
: Animal(turtle, world, 2, 1, positionX, positionY, age){
};

void Turtle::draw(){
    cout << "T";
};

string Turtle::specieName(){
    return "turtle";
};

Organism* Turtle::breed(int y, int x){
    return new Turtle(this->getWorld(), x, y, 1);
};

void Turtle::action(){
    setAge(getAge() + 1); //increasing age in ture
    
    int x = this->getPositionX();
    int y = this->getPositionY();
    const int prob = rand()%4;
    this->setPrevPositionX(x);
    this->setPrevPositionY(y);
    
    if(prob>2){
        //this->action();
        const int random = rand() % 4;
//        this->setPrevPositionX(x);
//        this->setPrevPositionY(y);
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
    }
    

}

Turtle::~Turtle(){};
