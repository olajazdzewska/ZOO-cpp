//
//  belladonna.hpp
//  ZOO
//
//  Created by Aleksandra Jażdżewska on 13/04/2023.
//

#ifndef belladonna_hpp
#define belladonna_hpp

#include <stdio.h>

#endif /* belladonna_hpp */
#include "Plant.hpp"
#include <string>
using namespace std;

class Belladonna : public Plant{
    bool justBorn = false;
public:
    Belladonna();
    Belladonna(World* world, int positionX, int positionY, int age);
    virtual void draw() override;
    string specieName() override;
    virtual Organism* breed(int y, int x) override;
    ~Belladonna();
};
