//
//  MasterObject.hpp
//  MixedSoundscapeAndCityscape
//
//  Created by Katsuya Endoh on 2023/02/09.
//

#ifndef MasterObject_hpp
#define MasterObject_hpp

#include <stdio.h>
#include "ofMain.h"

class MasterObject {
protected:
    float x, y, wh, speed;
    float angle, radiusX, radiusY;
public:
    MasterObject();
    void setPosition(float _x, float _y);
    void draw();
    void move();
    bool isInside(float _x, float _y, float _distance);
    void update(float _x, float _y);
    ofVec2f getPosition();
};

#endif /* MasterObject_hpp */
