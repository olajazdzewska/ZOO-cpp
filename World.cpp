//
//  World.cpp
//  ZOO
//
//  Created by Aleksandra Jażdżewska on 06/04/2023.
//

#include "Animal.hpp"
#include "Wolf.hpp"
#include "World.hpp"
#include "sheep.hpp"
#include "turtle.hpp"
#include "fox.hpp"
#include "Organism.hpp"
#include "Plant.hpp"
#include "grass.hpp"
#include "antelope.hpp"
#include "guarana.hpp"
#include "sowThistle.hpp"
#include "belladonna.hpp"
#include "SosnowskyHogweed.hpp"
#include "Human.hpp"

#include "World.hpp"
#include "Wolf.hpp"
#include <stdlib.h>

void World::legend(){
    cout << "Aleksandra Jażdżewska 193601" << endl;
    cout << " 1 - start new game  " << endl;
    cout << " 2 - load saved game " << endl;
    cout << " u - save game  " << endl;
    cout << " q - quit the game " << endl;
    cout << " T - new turn " << endl;
    cout << " H - make human move using arrows" << endl;
    cout << " P - activate human special ability " << endl;
    cout << " |A - antelope| | S - sheep | |W - wolf | " << endl;
    cout << " | F - fox | | T - turtle | | H - human | " << endl;
    cout << " | ~ - grass | | g - guarana | | t - sow thistle" << endl;
    cout << " | b - belladonna | | s - sosnowsky hogweed | " << endl;
    cout << endl;
};

World::World(int width, int height){
    this->width = width;
    this->height = height;
   // this->grid[20][20] = grid[20][20];
    this->grid = new Organism**[height];
    for(int i=0; i<height; i++){
        this->grid[i] = new Organism*[width];
    }
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            this->grid[i][j] = NULL;
        }
    }

    this->OrganismArr = new Organism*[quantityOfOrganism]; //crerate new array

};


Organism*** World::getGrid(){
    return this->grid;
};

Organism* World::getHuman(){
    return humanVector[0];
};

bool World::getSAcanBeActivated(){
    return SAcanBeActivated;
};


int World::getWidth(){
    return width;
};

int World::getHeight(){
    return height;
};

void World::sethumanSAtrue(){
    humanSA = true;
};

bool World::isEmptyCellOnGrid(){
 //   to avoid infinite recursionb
    for(int i=0; i<getHeight(); i++){
        for(int j=0; j<getWidth(); j++){
            if(grid[i][j] == NULL)
                return true;
        }
    }
    return false;
};


void World::setTure(int newture){
    ture = newture;
};
void World::setHumanSAture(int i){
    humanSAture = i;
};

bool World::getSAisActivated(){
    return SAisActivated;
};

void World::setIsHumanAliveFalse(){
    isHumanAlive = false;
}

bool World::getIsHumanAlive(){
    return isHumanAlive;
};


void World::createOrgAtPos(Organism* specie, int y, int x){
    specie->setPositionXY(y, x); //wywalone zostaly prev = position!!!!
    specie->setPrevPositionX(x);
    specie->setPrevPositionY(y);
    this->grid[y][x] = specie;
    organismCounter++;
};

void World::randomCellGenerator(Organism* specie){
    int x, y;
    x = rand() % getWidth();
    y = rand() % getHeight();
    if(grid[y][x] == NULL){
        createOrgAtPos(specie, y, x);
    }
    else{
        if(isEmptyCellOnGrid())
            return randomCellGenerator(specie);
    }
};

void World::clearCell(int x, int y){
    grid[y][x] = NULL;
};

int World::getQuantityOfOrganisms(){
    return quantityOfOrganism;
}

void  World::setQuantityOfOrganisms(int q){
    quantityOfOrganism = q;
};

int World::getorganismCounter(){
    return organismCounter;
};

void World::setorganismCounter(int q){
    organismCounter = q;
};


void World::createOrganisms(){
    
    randomCellGenerator(new Sheep(this, -1, -1, 2));
    randomCellGenerator(new Sheep(this, -1, -1, 4));
    
    randomCellGenerator(new Fox(this, -1, -1, 1));
    randomCellGenerator(new Fox(this, -1, -1, 7));
    
    randomCellGenerator(new Turtle(this, -1, -1, 1));
    randomCellGenerator(new Turtle(this, -1, -1, 8));
    
    randomCellGenerator(new Antelope(this, -1, -1, 4));
    randomCellGenerator(new Antelope(this, -1, -1, 6));
    
    randomCellGenerator(new Wolf(this, -1, -1, 5));
    randomCellGenerator(new Wolf(this, -1, -1, 1));
    
    randomCellGenerator(new Grass(this, -1, -1, 2));
    
    randomCellGenerator(new Guarana(this, -1, -1, 6));
    
    randomCellGenerator(new SowThistle(this, -1, -1, 8));
    
    randomCellGenerator(new Belladonna(this, -1, -1, 3));
    
    randomCellGenerator(new SosnowskyHogweed(this, -1, -1, 7));
    
    randomCellGenerator(new Human(this, -1, -1, 9));
    
};



void World::printGrid(){


    char upperBorder[width+2];
    for(int i=0; i<width+2; i++){
        upperBorder[i] = '-';
        cout << upperBorder[i];
    }
    cout << endl;
    for(int i=0; i<height; i++){
        cout << "|";
        for(int j=0; j<width; j++){
            if(grid[i][j] != NULL){
                Organism *tmp = grid[i][j]; 
              //  if(tmp -> getProposedX() != 0){
                    tmp->draw();
                    tmp->~Organism();
              //  }
              //  else{ //!!!
              //      grid[i][j] = NULL;
              //  }
            }
            else
                cout << " ";
        }
        cout << "|" << endl;
    }
    for(int i=0; i<width+2; i++){
        upperBorder[i] = '-';
        cout << upperBorder[i];
    }

};


void World::collectOrgFromGrid(){
    int k=0;
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){

            if(grid[i][j] != NULL){
                if(grid[i][j]->getSpecieInt() != 0){ //dont take human
                    OrganismArr[k] = grid[i][j]; //iterate through whole grid and collect all non-null elements (specis)
                    k++;
                }
                else{ //take human
                    humanVector.push_back(grid[i][j]);
                }
            }
        }
    }
};

Organism** World::getOrganismArr(){
    return this->OrganismArr;
};


void World::remove(Organism* specie){

    if(specie->getSpecieInt() == 0){
        humanVector[0] = NULL;
        humanVector.clear();
        isHumanAlive = false;
        setIsHumanAliveFalse();
    }
    else{
        specie->setSpecieEnumDelete(specie->getSpecieEnum());
    }
    
    organismCounter--;
    deletedOrganisms.push_back(specie);
    
};


void World::bubbleSort2(Organism** OrganismArr, int n)
{
    bool sorted = true;
    //we are assuming that array is sorted
    
    for (int i = 0; i < n - 2; i++) {
        Organism* first = OrganismArr[i];
        Organism* next = OrganismArr[i + 1];
        if(first != NULL && next != NULL){
            if (first->getInitiative() > next->getInitiative()) {
                Organism* temp = OrganismArr[i];
                OrganismArr[i] = OrganismArr[i + 1];
                OrganismArr[i + 1] = temp;
                
                sorted = false;
                //now array is not sorted
            }
            else if(first->getInitiative() == next->getInitiative()){
                if (first->getAge() > next->getAge()) {
                    Organism* temp = OrganismArr[i];
                    OrganismArr[i] = OrganismArr[i + 1];
                    OrganismArr[i + 1] = temp;
                    
                    sorted = false;
                    //now array is not sorted
                }
            }
            //if there are no swaps then we can
            //say that array is sorted.
        }
        if (sorted == false)
        {
            //recursively calling until it was sorted.
            bubbleSort2(OrganismArr, n);
        }
    }
}

void World::deleteOrg(Organism* specie){
    delete specie;
}

void World::makeTurn(Organism** OrganismArr){
   
    system("clear");
    legend();
    ture++;

    collectOrgFromGrid(); //collect organisms to organismArr that will be sorted in next step

    bubbleSort2(OrganismArr, quantityOfOrganism); //sort organismArr by initiative and age

    
    if(humanSA && SAcanBeActivated){
        SAisActivated = true;
        int prevStrength = humanVector[0] -> getPrevStrength();
        int newStrength = humanVector[0]->getStrength();
        if( newStrength != prevStrength){
            cout << "Special ability activated. Huamn's strength " << newStrength << endl;
            
            humanVector[0] -> setStrength(--newStrength);
           // int x = humanVector[0] ->getStrength();
            humanSAture++;
           
        }
       
        if(newStrength == prevStrength){
            humanSA = false;
            SAcanBeActivated = false;
            SAisActivated = false;
            cooldown = 0;
            humanSAture=0;
        }
        
    }
    if(!SAcanBeActivated){
        cooldown++;
        if(cooldown == 5){
            SAcanBeActivated=true;
            humanSAture=1;
        }
    }
    
    int size = getQuantityOfOrganisms();
    for(int i = 0; i < size ; i++){
        Organism *tmp = OrganismArr[i];
        if(tmp != NULL && (tmp->getSpecieEnum() != Organism::deleted)){
            tmp->action();
            tmp->~Organism();
        }
    }
    
    for(auto &organismToDelete : deletedOrganisms){
        delete organismToDelete;
    }
    
    deletedOrganisms.clear();
    humanVector.clear();

    
    for(int i = 0; i < size ; i++){
        OrganismArr[i] = NULL;
    }
    
    
    printGrid();
    
};



//loading world
World::World(int height, int width, std::ifstream &loadFile) {
    
    this->width = width;
    this->height = height;
    this->grid = new Organism**[height];
    for(int i=0; i<height; i++){
        this->grid[i] = new Organism*[width];
    }
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            this->grid[i][j] = NULL;
        }
    }
    this->OrganismArr = new Organism*[quantityOfOrganism]; //crerate new array
    
    Organism* specie;
    string word;
    int prevX, prevY, prevAge;
    

    while(loadFile >> word){
        loadFile >> prevY >> prevX >> prevAge;
        if(!word.compare("sheep")){
            createOrgAtPos(new Sheep(this, -1, -1, prevAge), prevY, prevX);
        }
        else if(!word.compare("fox")){
            createOrgAtPos(new Fox(this, -1, -1, prevAge), prevY, prevX);
        }
        else if(!word.compare("turtle")){
            createOrgAtPos(new Turtle(this, -1, -1, prevAge), prevY, prevX);
        }
        else if(!word.compare("wolf")){
            createOrgAtPos(new Wolf(this, -1, -1, prevAge), prevY, prevX);
        }
        else if(!word.compare("antelope")){
            createOrgAtPos(new Antelope(this, -1, -1, prevAge), prevY, prevX);
        }
        else if(!word.compare("grass")){
            createOrgAtPos(new Grass(this, -1, -1, prevAge), prevY, prevX);
        }
        else if(!word.compare("guarana")){
            createOrgAtPos(new Guarana(this, -1, -1, prevAge), prevY, prevX);
        }
        else if(!word.compare("sow_Thistle")){
            createOrgAtPos(new SowThistle(this, -1, -1, prevAge), prevY, prevX);
        }
        else if(!word.compare("belladonna")){
            createOrgAtPos(new Belladonna(this, -1, -1, prevAge), prevY, prevX);
        }
        else if(!word.compare("Sosnowsky_Hogweed")){
            createOrgAtPos(new SosnowskyHogweed(this, -1, -1, prevAge), prevY, prevX);
        }
        else if(!word.compare("human")){
            createOrgAtPos(new Human(this, -1, -1, prevAge), prevY, prevX);
        }

    }
    
};

void World::saveWorld(){
    std::ofstream fileToSave;
    fileToSave.open("savedWorld.txt", std::ios::out);
    if(!fileToSave){
        cout << " Couldnt save the world" << endl;
        return;
    }
    else{
        fileToSave << ture << " " << humanSAture << "\n"; //moze zamiast humanSAture to human prevStrength i strength?
        fileToSave << height << " " << width << "\n";
        for(int i=0; i<height; i++){
            for(int j=0; j<width; j++){
                if(grid[i][j] != NULL){
                    Organism* tmp = grid[i][j];
                    fileToSave << tmp->specieName() << " " << tmp->getPositionY() << " " << tmp->getPositionX() << " " << tmp->getAge() << "\n";
                }
            }
        }

        fileToSave.close();
        cout << endl << "world saved" << endl;
    }
}

World::~World(){};
