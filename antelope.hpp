//
//  antelope.hpp
//  ZOO
//
//  Created by Aleksandra Jażdżewska on 13/04/2023.
//

#ifndef antelope_hpp
#define antelope_hpp

#include <stdio.h>

#endif /* antelope_hpp */
#include "Animal.hpp"
#include <string>
using namespace std;

class Antelope : public Animal{
    bool justBorn = false;
public:
    Antelope();
    Antelope(World* world, int positionX, int positionY, int age);
    virtual void action() override;
    virtual void draw() override;
    string specieName() override;
    virtual Organism* breed(int y, int x) override;
    ~Antelope();
};
