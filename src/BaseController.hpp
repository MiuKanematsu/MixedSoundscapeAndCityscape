//
//  BaseController.hpp
//  MixedSoundscapeAndCityscape
//
//  Created by Katsuya Endoh on 2023/01/29.
//

#ifndef BaseController_hpp
#define BaseController_hpp

#include <stdio.h>
#include <iostream>
#include "ofMain.h"

class BaseController {
public:
    BaseController(float _minDistance);
    void update();
    void drawLine();
    void drawPoints();
    void addPoint(float x, float y);
    ofVec2f getCenter();

private:
    float minDistance;
    vector<ofVec2f> points;
};

#endif /* BaseController_hpp */
