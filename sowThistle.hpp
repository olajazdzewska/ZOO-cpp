//
//  sowThistle.hpp
//  ZOO
//
//  Created by Aleksandra Jażdżewska on 13/04/2023.
//

#ifndef sowThistle_hpp
#define sowThistle_hpp

#include <stdio.h>

#endif /* sowThistle_hpp */
#include "Plant.hpp"
#include <string>
using namespace std;

class SowThistle : public Plant{
    bool justBorn = false;
public:
    SowThistle();
    SowThistle(World* world, int positionX, int positionY, int age);
    virtual void draw() override;
    string specieName() override;
    virtual void action() override;
    virtual Organism* breed(int y, int x) override;
    ~SowThistle();
};
