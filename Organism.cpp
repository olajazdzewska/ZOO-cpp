//
//  Organism.cpp
//  ZOO
//
//  Created by Aleksandra Jażdżewska on 06/04/2023.
//
#pragma once
#include "Organism.hpp"
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;



Organism::Organism(Species specieEnum, World* world, int strength, int initiative, int positionY, int positionX, int age){

    this->specieEnum = specieEnum;
    this->world = world;
    this->strength = strength;
    this->initiative = initiative;
    this->positionY = positionY;
    this->positionX = positionX;
    this->age = age;

};

int Organism::getStrength(){
    return this->strength;
};

void Organism::setStrength(int x){
    this->strength = x;
};

int Organism::getPrevStrength(){
    return this->prevStrength;
};
void Organism::setPrevStrength(int x){
    prevStrength = x;
};

int Organism::getInitiative(){
    return this->initiative;
};



void Organism::setPositionXY(int y, int x){

    positionX = x;
    positionY = y;
    this->world->getGrid()[positionY][positionX] = this;

}

void Organism::setPositionX(int x){
    this->prevX = positionX;
    positionX = x;
    this->world->getGrid()[positionY][positionX] = this;
    this->world->getGrid()[positionY][prevX] = NULL;

};
int Organism::getPositionX(){
    return this->positionX;
};
void Organism::setPositionY(int y){

    this->prevY = positionY;
    positionY = y;
    this->world->getGrid()[positionY][positionX] = this;
    this->world->getGrid()[prevY][positionX] = NULL;

};
int Organism::getPositionY(){
    return this->positionY;
};

void Organism::setPrevPositionX(int x){
    prevX = x;
};
int Organism::getPrevPositionX(){
    return this->prevX;
};
void Organism::setPrevPositionY(int y){
    prevY = y;
};
int Organism::getPrevPositionY(){
    return this->prevY;
};

void Organism::setProposedX(int x){
    proposedX = x;
};
int Organism::getProposedX(){
    return proposedX;
};
void Organism::setProposedY(int y){
    proposedY = y;
};
int Organism::getProposedY(){
    return proposedY;
};

void Organism::setAge(int a){
    age = a;
}

int Organism::getAge(){
    return this->age;
};

void Organism::setWorld(World* world){
    this -> world = world;
};

World* Organism::getWorld(){
    return this->world;
};

Organism::Species Organism::getSpecieEnum(){
    return this->specieEnum;
}

void Organism::setSpecieEnumDelete(Species specieEnum){
    this->specieEnum = deleted;
};

int Organism::getSpecieInt(){
    return this->specieEnum;
}
    
bool Organism::isCellOccupied(int y, int x){

    if(this->world->getGrid()[y][x] == NULL){
        return false;
    }
    return true;
   
};

bool Organism::isCellValid(int y, int x){
    if(x >= this->getWorld()->getWidth() ||  x<0 || y >= this->getWorld()->getHeight() || y<0)
        return false;
    else
        return true;
}
    
string Organism::organismLegend(){
    return (specieName() + "  x: " + to_string(getPositionX()) + "  y: " + to_string(getPositionY()) + "  age: " + to_string(getAge()) );
};
 
void Organism::setOrganismsInfoArr(){
    string* organismsInfoArr = new string[getWorld()->getQuantityOfOrganisms()];
    for(int i=0; i<getWorld()->getQuantityOfOrganisms(); i++){
        organismsInfoArr[i] = organismLegend();
    }
};

string* Organism::getOrganismsInfoArr(){
    return organismsInfoArr;
}

void Organism::printOrganismsInfoArr(){
    for(int i=0; i<getWorld()->getQuantityOfOrganisms(); i++){
        cout << getOrganismsInfoArr()[i] << endl;
    }
};

bool Organism::isSosnowskyNearby(int y, int x){
    if(isCellValid(y, x + 1) && getWorld()->getGrid()[y][x+1] != NULL && getWorld()->getGrid()[y][x+1]->getSpecieEnum() == Sosnowsky){
        return true;
    }
    else if(isCellValid(y, x-1) && getWorld()->getGrid()[y][x-1] != NULL && getWorld()->getGrid()[y][x-1]->getSpecieEnum() == Sosnowsky){
        return true;
    }
    else if(isCellValid(y+1,x) && getWorld()->getGrid()[y+1][x] != NULL && getWorld()->getGrid()[y+1][x]->getSpecieEnum() == Sosnowsky){
        return true;
    }
    else if(isCellValid(y-1, x) && getWorld()->getGrid()[y-1][x] != NULL && getWorld()->getGrid()[y-1][x]->getSpecieEnum() == Sosnowsky){
        return true;
    }
    else{
        return false;
    }
};

void Organism::specialAbility(){

    int newStrength = 10;
    this->setStrength(newStrength);
};



int* Organism::NearestFreeCell(int x, int y){
    int position[2] = {-1, -1}; //y, x
    
    if(isCellValid(y, x+1) && getWorld()->getGrid()[y][x+1] == NULL ){
        position[0] = y;
        position[1] = x+1;
        return position;
    }
    else if(isCellValid(y, x-1) && getWorld()->getGrid()[y][x-1] == NULL ){
        position[0] = y;
        position[1] = x-1;
        return position;
    }
    else if(isCellValid(y+1, x) && getWorld()->getGrid()[y+1][x] == NULL ){
        position[0] = y+1;
        position[1] = x;
        return position;
    }
    else if(isCellValid(y-1, x) && getWorld()->getGrid()[y-1][x] == NULL ){
        position[0] = y-1;
        position[1] = x;
        return position;
    }
    else{
        position[0] = -1;
        position[1] = -1;
        return position;
    }
};


void Organism::putNewBorn(int x1, int y1, int x2, int y2){
    int* newPosition = NearestFreeCell(x1, y1);
    if(newPosition[0] == -1 && newPosition[1] == -1){ //if there is no free cell around one parent check cells around other parent
        newPosition = NearestFreeCell(x2, y2);
        if(newPosition[0] == -1 && newPosition[1] == -1){
            cout << "there is no place for newborn" << endl;
        }
        else{
            breed(newPosition[0], newPosition[1]);
            getWorld()->getGrid()[newPosition[0]][newPosition[1]] = breed(newPosition[0], newPosition[1]);
            getWorld()->setorganismCounter(getWorld()->getorganismCounter() + 1);
        }
    }
    else{ //if there is place then plaxce newBorn
        breed(newPosition[0], newPosition[1]);
        getWorld()->getGrid()[newPosition[0]][newPosition[1]] = breed(newPosition[0], newPosition[1]);
        
        
        getWorld()->setorganismCounter(getWorld()->getorganismCounter() + 1);
    }
   
}


void Organism::collisions(int y, int x){
    Organism *victim = getWorld()->getGrid()[y][x];
    Organism* atacker = this;
    
    if(victim != NULL && atacker != NULL && atacker->getSpecieEnum() != deleted && victim->getSpecieEnum() != deleted){
        cout << atacker->specieName() << " attacked " << victim->specieName() << endl;
        if(atacker->getSpecieInt() != victim->getSpecieInt()){ //if they are different species
            if(victim->getSpecieEnum() == turtle){
                if(atacker->getStrength() < 5){ //c: Reflects attacks of animal with strength less than 5. Attacker will return to the previous cell.
                    cout << "turtle reflected attack of " << atacker->specieName() << endl;
                }
                else{
                    getWorld()->remove(victim);
                    this->getWorld()->getGrid()[y][x] = NULL;
                    atacker->setPositionY(y); //set new cords to attacker
                    atacker->setPositionX(x);
                    this->getWorld()->getGrid()[y][x] = atacker; //set new cell to attacker
                    getWorld()->getGrid()[atacker->getPrevPositionY()][atacker->getPrevPositionX()] = NULL; //set null to prev position
                }
            }
            else if(victim->getSpecieEnum() == belladonna){
                getWorld()->remove(victim);
                this->getWorld()->getGrid()[y][x] = NULL;
                
                getWorld()->remove(atacker);
                this->getWorld()->getGrid()[atacker->getPositionY()][atacker->getPositionX()] = NULL;
                
                cout << "make special ability for belladonna" << endl;
            }
            else if(victim->getSpecieEnum() == guarana){
                atacker->setStrength(atacker->getStrength() + 3); //increase strength of attacker
                
                cout << "make special ability for guarana" << endl;
                cout << "the strength of " << atacker->specieName() << " equals to " << atacker->getStrength() << endl;
                
                getWorld()->remove(victim);
                this->getWorld()->getGrid()[y][x] = NULL;
                atacker->setPositionY(y); //set new cords to attacker
                atacker->setPositionX(x);
                this->getWorld()->getGrid()[y][x] = atacker; //set new cell to attacker
                getWorld()->getGrid()[atacker->getPrevPositionY()][atacker->getPrevPositionX()] = NULL; //set null to prev position

            }
            else if(victim->getSpecieEnum() == Sosnowsky){
                getWorld()->remove(victim);
                this->getWorld()->getGrid()[y][x] = NULL;
                
                getWorld()->remove(atacker);
                this->getWorld()->getGrid()[atacker->getPositionY()][atacker->getPositionX()] = NULL;
                
                cout << "make special ability for sosnovsky" << endl;
                
            }
            else if(victim->getSpecieEnum() == antelope){
                int probability = rand()%2;
                    if(probability == 0){ //antelope escapes

                            cout << "antelope escaped";
                        
                            victim->action();

                            this->getWorld()->getGrid()[y][x] = NULL;
                            atacker->setPositionY(y); //set new cords to attacker
                            atacker->setPositionX(x);
                            this->getWorld()->getGrid()[y][x] = atacker; //set new cell to attacker
                            getWorld()->getGrid()[atacker->getPrevPositionY()][atacker->getPrevPositionX()] = NULL;


                    }
                    else{ //antelope dosent escape
                        if(victim->getStrength() > atacker->getStrength()){ //attacker is defeated
                            cout << atacker->specieName() << " is defeated " << endl;
                            this->getWorld()->getGrid()[atacker->getPositionY()][atacker->getPositionX()] = NULL; //we delete atacker from the cell (cell before action)
                            getWorld()->remove(atacker);
                           
                        }
                        else{ //attacker wins
                            cout << atacker->specieName() << " wins " << endl;
                            getWorld()->remove(victim);
                            this->getWorld()->getGrid()[y][x] = NULL;
                            atacker->setPositionY(y); //set new cords to attacker
                            atacker->setPositionX(x);
                            this->getWorld()->getGrid()[y][x] = atacker; //set new cell to attacker
                            getWorld()->getGrid()[atacker->getPrevPositionY()][atacker->getPrevPositionX()] = NULL;
                        }
                    }
                
            }
            else{
                if(victim != NULL && atacker != NULL && atacker->getSpecieEnum() != deleted && victim->getSpecieEnum() != deleted){
                    if(victim->getStrength() > atacker->getStrength()){ //attacker is defeated
                        cout << atacker->specieName() << " is defeated " << endl;
                        this->getWorld()->getGrid()[atacker->getPositionY()][atacker->getPositionX()] = NULL; //we delete atacker from the cell (cell before action)
                        getWorld()->remove(atacker);
                        
                    }
                    else{ //attacker wins
                        
                        cout << atacker->specieName() << " wins " << endl;
                        getWorld()->remove(victim);
                        this->getWorld()->getGrid()[y][x] = NULL;
                        
                        atacker->setPositionY(y); //set new cords to attacker
                        atacker->setPositionX(x);
                        this->getWorld()->getGrid()[y][x] = atacker; //set new cell to attacker
                        getWorld()->getGrid()[atacker->getPrevPositionY()][atacker->getPrevPositionX()] = NULL;
                        
                    }
                }
            }
        }
        else{
            if(getWorld()->isEmptyCellOnGrid()){
                putNewBorn(victim->getPositionX(), victim->getPositionY(), atacker->getPositionX(), atacker->getPositionY()); //take parents positions and put newBorn there
                cout << endl << "breed of " << atacker->specieName() << endl;
                
            }
            else
                cout << "no empty place on grid for newborn to be put" << endl;
            
        }
    }

};

int* Organism::checkAction( int key){
       
        int x = this->getPositionX();
        int y = this->getPositionY();
        switch(key){
            case 'w':
                this->setProposedX(x);
                this->setProposedY(y-1);
                break;
            case 'a':
                this->setProposedX(x-1);
                this->setProposedY(y);

                break;
            case 'd':
                this -> setProposedX(x+1);
                this->setProposedY(y);

                break;
            case 's':
                this-> setProposedX(x);
                this->setProposedY(y+1);

                break;
    
        }
    return 0;
};

Organism::~Organism(){

};

//Organism::~Organism(){};
