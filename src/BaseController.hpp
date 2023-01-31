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
    void deletePoint(int i);
    void deletePoints(int length);
    
private:
    float minDistance;

protected:
    vector<ofVec2f> points;
    ofColor c;
};

#endif /* BaseController_hpp */
