//
//  sowThistle.cpp
//  ZOO
//
//  Created by Aleksandra Jażdżewska on 13/04/2023.
//

#include "sowThistle.hpp"
#include <iostream>
#include <string>
using namespace std;

SowThistle::SowThistle(World *world, int positionX, int positionY, int age)
: Plant(sowThistle, world, 0, positionY, positionX, age){
};

void SowThistle::draw(){
    cout << "t";
};

string SowThistle::specieName(){
    return "sow_Thistle";
};

Organism* SowThistle::breed(int y, int x){
    return new SowThistle(this->getWorld(), x, y, 1);
};

void SowThistle::action(){
    int x = this->getPositionX();
    int y = this->getPositionY();
    for(int i=0; i < 3; i++){
        const int random = rand()%4;
        const int probOfSow = rand()%4;
        if(probOfSow<1){ //sowing with certain probability
            switch (random){
                case 0:
                    if(isCellValid(y, x+1)){
                        if(isCellOccupied(y, x+1))
                            break;
                        else{
                            breed(y, x+1);
                            getWorld()->getGrid()[y][x+1] = breed(y, x+1);
                            //getWorld()->setQuantityOfOrganisms(getWorld()->getQuantityOfOrganisms() + 1);
                           // counter++
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
                            getWorld()->getGrid()[y][x-1] = breed(y, x-1);
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
                            getWorld()->getGrid()[y+1][x] = breed(y+1, x);
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
                            getWorld()->getGrid()[y-1][x] = breed(y-1, x);
                            getWorld()->setQuantityOfOrganisms(getWorld()->getQuantityOfOrganisms() + 1);
                        }
                    }
                    else
                        this->action();
                    break;
            }
        }
    }
};



SowThistle::~SowThistle(){};
