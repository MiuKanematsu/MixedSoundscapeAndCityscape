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
    void addPoint(int i, float x, float y);
    vector<ofVec2f> getCenters();
    bool intersect(ofVec2f _p1, ofVec2f _p2, float _w, float _h);
    int getLineCount() { return lines.size(); };
protected:
    vector<vector<ofVec2f>> lines;
    ofColor c;
    float minDistance;
};

#endif /* BaseController_hpp */
