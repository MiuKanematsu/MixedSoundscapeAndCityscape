//
//  RiverParticle.hpp
//  MixedSoundscapeAndCityscape
//
//  Created by 兼松 美羽 on 2023/01/31.
//

#ifndef RiverParticle_hpp
#define RiverParticle_hpp

#include <stdio.h>
#include "ofMain.h"

class RiverParticle{
private:
    ofVec2f position, velocity, acceleration, targetPlay;
    float r, maxforce, maxspeed;
    int targetNum, targetMinDist;
    ofColor c;
public:
    RiverParticle(ofVec2f p);
    void init();
};

#endif /* RiverParticle_hpp */
