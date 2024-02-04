//
//  grass.hpp
//  ZOO
//
//  Created by Aleksandra Jażdżewska on 13/04/2023.
//

#ifndef grass_hpp
#define grass_hpp

#include <stdio.h>
#endif /* grass_hpp */

#include "Plant.hpp"
#include <string>
using namespace std;


class Grass : public Plant{
    bool justBorn = false;
public:
    Grass();
    Grass(World* world, int positionX, int positionY, int age);
    virtual void draw() override;
    string specieName() override;
    virtual Organism* breed(int y, int x) override;
    ~Grass();
};
