//
//  SosnowskyHogweed.hpp
//  ZOO
//
//  Created by Aleksandra Jażdżewska on 13/04/2023.
//

#ifndef SosnowskyHogweed_hpp
#define SosnowskyHogweed_hpp

#include <stdio.h>

#endif /* SosnowskyHogweed_hpp */
#include "Plant.hpp"
#include <string>
using namespace std;

class SosnowskyHogweed : public Plant{
    bool justBorn = false;
public:
    SosnowskyHogweed();
    SosnowskyHogweed(World* world, int positionX, int positionY, int age);
    virtual void draw() override;
    string specieName() override;
    virtual Organism* breed(int y, int x) override;
    ~SosnowskyHogweed();
};
