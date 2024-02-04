//
//  Human.hpp
//  ZOO
//
//  Created by Aleksandra Jażdżewska on 07/04/2023.
//

#ifndef Human_hpp
#define Human_hpp

#include <stdio.h>
#include "Animal.hpp"
#include <string>
using namespace std;
#endif /* Human_hpp */

class Human : public Animal{

    
public:
    
    Human(World* world, int positionX, int positionY, int age);
    virtual void draw() override;
    virtual void action() override;
    string specieName() override;
    virtual Organism* breed(int y, int x) override;

    
};
