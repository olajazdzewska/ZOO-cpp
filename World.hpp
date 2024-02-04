//
//  World.hpp
//  ZOO
//
//  Created by Aleksandra Jażdżewska on 06/04/2023.
//
#pragma once
#ifndef World_hpp
#define World_hpp



#include <stdio.h>
#include "Organism.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#endif /* World_hpp */



class Organism;


class World{
    int cooldown=0;
    int maxSize;
    int currentSize = 0;
    int width;
    int height;
    int ture=0;
    int humanSAture=1;
    bool SAcanBeActivated = true;
    bool humanSA = false;
    bool SAisActivated = false;
    bool isHumanAlive = true;
    Organism*** grid;
    Organism** OrganismArr;
    Organism** deletedOrganismArr;
    int* initiativeArr;
    int quantityOfOrganism = 40;
    int organismCounter=0;
    int deletedOrgCount=0;
    vector<Organism*> deletedOrganisms;
    vector<Organism*> humanVector;
    
    
protected:
    void addNewOrganism(Organism* specie);
    void clearCell(int x, int y);
    void bubbleSort2(Organism** OrganismArr, int n);
    void initdeletedOrganismArr(Organism** deletedOrganismArr);
    void deleteOrg(Organism* specie);
    

    
public:
    void legend();
    
    World(int height, int width, std::ifstream &loadFile);
    void saveWorld();
    World loadWorld();
    
    World(int width=20, int height=20);
    Organism*** getGrid();
    Organism** getOrganismArr();
    
    bool getIsHumanAlive();
    void setIsHumanAliveFalse();
    int getWidth();
    int getHeight();
    void setTure(int newture);
    void setHumanSAture(int i);
    void createOrgAtPos(Organism* specie, int y, int x);
    void randomCellGenerator(Organism* specie);
    void collectSpecieFromGrid();
    bool isEmptyCellOnGrid();
    void makeTurn(Organism** OrganismArr);
    int getQuantityOfOrganisms();
    void setQuantityOfOrganisms(int q);
    int getorganismCounter();
    void setorganismCounter(int q);
    void collectOrgFromGrid();
    void createOrganisms();
    void printGrid();

    void remove(Organism* specie);
    void sethumanSAtrue();
    bool getSAisActivated();
    bool getSAcanBeActivated();
    Organism* getHuman();
    ~World();

    
};
