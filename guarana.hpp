//
//  guarana.hpp
//  ZOO
//
//  Created by Aleksandra Jażdżewska on 13/04/2023.
//

#ifndef guarana_hpp
#define guarana_hpp

#include <stdio.h>
#include "Plant.hpp"
#endif /* guarana_hpp */
#include <string>
using namespace std;

class Guarana : public Plant{
    bool justBorn = false;
public:
    Guarana();
    Guarana(World* world, int positionX, int positionY, int age);
    virtual void draw() override;
    string specieName() override;
    virtual Organism* breed(int y, int x) override;
    ~Guarana();
};
