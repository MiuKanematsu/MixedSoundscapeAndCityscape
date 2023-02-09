//
//  Building.hpp
//  MixedSoundscapeAndCityscape
//
//  Created by Katsuya Endoh on 2023/02/09.
//

#ifndef Building_hpp
#define Building_hpp

#include <stdio.h>
#include "ofMain.h"

class Building {
private:
    ofVec2f center, p;
    float wid, hei, distance, angle, maxDist;
    ofColor c;
public:
    Building(ofVec2f _p, float _w, float _h);
    void update(float _x, float _y);
    void display();
};

#endif /* Building_hpp */
