//
//  Organism.hpp
//  ZOO
//
//  Created by Aleksandra Jażdżewska on 06/04/2023.
//


//collision of plants????
// czy neighbour to tez na skos???
#pragma once
#ifndef Organism_hpp
#define Organism_hpp

#include <stdio.h>
#include "World.hpp"
#include <string>
using namespace std;
#endif /* Organism_hpp */


class World;

class Organism{

    int strength = 0;
    int initiative = 0;
    int age = 0;
    World* world = NULL;
    int prevX = -1;
    int prevY = -1;
    int positionX = -1;
    int positionY = -1;
    string* organismsInfoArr;
    int proposedX = -1;
    int proposedY = -1;
    int prevStrength = 0;


public:


    enum Species{
        human,
        wolf,
        sheep,
        fox,
        turtle,
        antelope,
        cyberSheep,
        grass,
        sowThistle,
        guarana,
        belladonna,
        Sosnowsky,
        deleted
    };
    
protected:
    
    Species specieEnum;
    void collisions(int y, int x);
    bool isCellOccupied(int y, int x);
    bool isCellValid(int y, int x);
    string organismLegend();
    void addOrg(Organism* specie, int x, int y);
    void printOrganismsInfoArr();
    int* NearestFreeCell(int x, int y);
    void putNewBorn(int x1, int y1, int x2, int y2);
    bool isSosnowskyNearby(int y, int x);

    
public:
    int getStrength();
    void setStrength(int x);
    int getPrevStrength();
    void setPrevStrength(int x);
    int getInitiative();

    void setPositionX(int x);
    int getPositionX();
    void setPositionY(int y);
    int getPositionY();
    void setPrevPositionX(int x);
    int getPrevPositionX();
    void setPrevPositionY(int y);
    int getPrevPositionY();
    void setPositionXY(int y, int x);
    void setProposedX(int x);
    int getProposedX();
    void setProposedY(int y);
    int getProposedY();
    int getAge();
    void setAge(int a);
    void setWorld(World* world);
    World* getWorld();
    Species getSpecieEnum();
    void setSpecieEnumDelete(Species specieEnum);
    int getSpecieInt();
    Organism(){};
    Organism(Species specieEnum, World *world = NULL, int strength = 0, int initiative = 0, int positionY = -1, int positionX = -1, int age = 0);
    virtual void action() = 0;
    virtual void draw() = 0;
    virtual Organism* breed(int y, int x) = 0;
    virtual string specieName() = 0;
    void setOrganismsInfoArr();
    string* getOrganismsInfoArr();
    int* checkAction( int key);
    void specialAbility();
    virtual ~Organism(); 
    

    
};
