//
//  main.cpp
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
#include <string>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

#define sizeX 20
#define sizeY 20




int main(){
    srand((unsigned)time(NULL));
    system("clear");
    int height, width;
    bool canMove=true;
    char letter;
    
cout << "Aleksandra Jażdżewska 193601" << endl;
cout << " 1 - start new game  " << endl;
cout << " 2 - load saved game " << endl;
cout << " u - save game  " << endl;
cout << " q - quit the game " << endl;
cout << " t - new turn " << endl;
cout << " m - make human move using arrows" << endl;
cout << " p - activate human special ability " << endl;
cout << " |A - antelope| | S - sheep | |W - wolf | " << endl;
cout << " | F - fox | | T - turtle | | H - human | " << endl;
cout << " | ~ - grass | | g - guarana | | t - sow thistle" << endl;
cout << " | b - belladonna | | s - sosnowsky hogweed | " << endl;
    
    
        letter = getchar();
        if(letter == '1'){ //start new gane
                World world(sizeX, sizeY);
            
            
                world.createOrganisms();
                world.collectOrgFromGrid();
                world.printGrid();
            do{
                letter = getchar();
                if(letter == 'm' && world.getIsHumanAlive()){ //move human
                    
                    if(canMove){
                        char move;
                        cin >> move;
                        world.getHuman()->checkAction(move);
                        world.getHuman()->action();
                        canMove = false;
                    }
                    else{
                        cout << "you already have made a move" << endl;
                    }
                    
                }
                else if(letter == 'p' && world.getIsHumanAlive()){ //special ability
                    if(world.getSAcanBeActivated() && !world.getSAisActivated()){
                        world.getHuman()->setPrevStrength(world.getHuman()->getStrength());
                        world.sethumanSAtrue();
                        world.getHuman()->specialAbility();
                        cout << "Human's special ability activated" << endl;
                    }
                    else if(world.getSAisActivated()){
                        cout << "Special ability is already activated" << endl;
                    }
                    else{
                        cout << "you need to wait until human's cooldown ends to use special ability again " << endl;
                    }
                    
                }
                else if(letter == 't'){ //make turn
                    canMove = true;
                    world.makeTurn(world.getOrganismArr());
                }
                else if(letter == 's'){
                    world.collectOrgFromGrid();
                    world.saveWorld();
                }
                else if(letter == '2'){
                    std::ifstream loadFile;
                    loadFile.open("savedWorld.txt", std::ios::in);
                    if(!loadFile){
                        printf("There is no saved world.\n");
                       // exit(1);
                    }
                    int prevTure, prevHumanSAture;
                    loadFile >> prevTure >> prevHumanSAture;
                    loadFile >> height >> width;
                    // Konstruktor zapisanego świata
                    World savedWorld(height, width, loadFile);
                    
                    
                    
                   
                    
                    savedWorld.setTure(prevTure);
                    savedWorld.setHumanSAture(prevHumanSAture);
                    savedWorld.collectOrgFromGrid();
                    savedWorld.printGrid();
                    do{
                        letter = getchar();
                        if(letter == 'm' && savedWorld.getIsHumanAlive()){ //move human
                            
                            if(canMove){
                                char move;
                                cin >> move;
                                savedWorld.getHuman()->checkAction(move);
                                savedWorld.getHuman()->action();
                                canMove = false;
                            }
                            else{
                                cout << "you already have made a move" << endl;
                            }
                            
                        }
                        else if(letter == 'p' && savedWorld.getIsHumanAlive()){ //special ability
                            if(savedWorld.getSAcanBeActivated() && !savedWorld.getSAisActivated()){
                                savedWorld.getHuman()->setPrevStrength(savedWorld.getHuman()->getStrength());
                                savedWorld.sethumanSAtrue();
                                savedWorld.getHuman()->specialAbility();
                                cout << "Human's special ability activated" << endl;
                            }
                            else if(savedWorld.getSAisActivated()){
                                cout << "Special ability is already activated" << endl;
                            }
                            else{
                                cout << "you need to wait until human's cooldown ends to use special ability again " << endl;
                            }
                            
                        }
                        else if(letter == 't'){ //make turn
                            canMove = true;
                            savedWorld.makeTurn(savedWorld.getOrganismArr());
                        }
                        else if(letter == 's'){
                            savedWorld.saveWorld();
                        }
                        
                    }while(letter != 'q');
                }
              //  world.collectOrgFromGrid();
                
            }while(letter != 'q');
           // getchar();
        }
        else if(letter == '2'){ //load saved game
            std::ifstream loadFile; 
            loadFile.open("savedWorld.txt", std::ios::in);
            if(!loadFile){
                printf("There is no saved world.\n");
               // exit(1);
            }
            int prevTure, prevHumanSAture;
            loadFile >> prevTure >> prevHumanSAture;
            loadFile >> height >> width;
            // Konstruktor zapisanego świata
            World savedWorld(height, width, loadFile);
            
            
            
           
            
            savedWorld.setTure(prevTure);
            savedWorld.setHumanSAture(prevHumanSAture);
            savedWorld.collectOrgFromGrid();
            savedWorld.printGrid();
            do{
                letter = getchar();
                if(letter == 'm' && savedWorld.getIsHumanAlive()){ //move human
                    
                    if(canMove){
                        char move;
                        cin >> move;
                        savedWorld.getHuman()->checkAction(move);
                        savedWorld.getHuman()->action();
                        canMove = false;
                    }
                    else{
                        cout << "you already have made a move" << endl;
                    }
                    
                }
                else if(letter == 'p' && savedWorld.getIsHumanAlive()){ //special ability
                    if(savedWorld.getSAcanBeActivated() && !savedWorld.getSAisActivated()){
                        savedWorld.getHuman()->setPrevStrength(savedWorld.getHuman()->getStrength());
                        savedWorld.sethumanSAtrue();
                        savedWorld.getHuman()->specialAbility();
                        cout << "Human's special ability activated" << endl;
                    }
                    else if(savedWorld.getSAisActivated()){
                        cout << "Special ability is already activated" << endl;
                    }
                    else{
                        cout << "you need to wait until human's cooldown ends to use special ability again " << endl;
                    }
                    
                }
                else if(letter == 't'){ //make turn
                    canMove = true;
                    savedWorld.makeTurn(savedWorld.getOrganismArr());
                }
                else if(letter == 's'){
                    savedWorld.saveWorld();
                }
                
            }while(letter != 'q');
        }
       
    
    return 0;
}


