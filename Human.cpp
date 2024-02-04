//
//  Human.cpp
//  ZOO
//
//  Created by Aleksandra Jażdżewska on 07/04/2023.
//
#include "Human.hpp"
#include <stdio.h>
#include <string>




Human::Human(World *world, int positionX, int positionY, int age)
: Animal(human, world, 5, 4, positionX, positionY, age){
};


void Human::action(){
    int x1 = this->getPositionX();
    int y1 = this->getPositionY();
    this->setPrevPositionX(x1);
    this->setPrevPositionY(y1);
    int y2 = this->getProposedY();
    int x2 = this->getProposedX();
    
    if(isCellValid(y2, x2)){
        if(isCellOccupied(y2, x2)){
            collisions(y2, x2);
            cout << "Human's collision" << endl;
            system("clear");
            getWorld()->legend();
            getWorld()->printGrid();
        }
        else{
            if(isSosnowskyNearby(y2, x2)){
                getWorld()->remove(this);
                cout << "human got killed by going too close to sosnowsky " << endl;
                getWorld()->getGrid()[y1][x1] = NULL;
                system("clear");
                getWorld()->legend();
                getWorld()->printGrid();
                getWorld()->setIsHumanAliveFalse();
                //isAlive = false;
            }
            else{
                setPositionY(y2);
                setPositionX(x2);
                system("clear");
                getWorld()->legend();
                getWorld()->getGrid()[y2][x2] = this;
                getWorld()->getGrid()[y1][x1] = NULL;
                getWorld()->printGrid();
            }
        }
    }
};



string Human::specieName(){
    return "human";
};

void Human::draw(){
    cout << "H";
};

Organism* Human::breed(int y, int x){
    return 0;
};
