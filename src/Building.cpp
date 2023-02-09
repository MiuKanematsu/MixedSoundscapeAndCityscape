//
//  Building.cpp
//  MixedSoundscapeAndCityscape
//
//  Created by Katsuya Endoh on 2023/02/09.
//

#include "Building.hpp"


Building::Building(ofVec2f _p, float _w, float _h) {
    p = ofVec2f(_p.x, _p.y);
    wid = _w;
    hei = _h;
    center = ofVec2f(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
    maxDist = 30;
}

void Building::update(float _x, float _y) {
    center.set(_x, _y);
    distance = ofDist(center.x, center.y, p.x, p.y);
    angle = atan2(p.y - center.y, p.x - center.x);
}

void Building::display() {
    float w = wid + distance / 40;
    float h = hei + distance / 40;
    float w2 = wid / 1.5;
    float h2 = hei / 1.5;
    float mappedDistance = ofMap(distance, 0, ofGetWindowWidth() / 2, 0, maxDist);
    
    ofPushStyle();
    ofPushMatrix();
    ofTranslate(p.x, p.y);
    ofNoFill();
    ofSetColor(255);
    ofDrawRectangle(0, 0, w2, h2);
    ofDrawLine( w2 / 2,  h2 / 2, mappedDistance * cos(angle) + w / 2, mappedDistance * sin(angle) + h / 2);
    ofDrawLine(-w2 / 2, -h2 / 2, mappedDistance * cos(angle) - w / 2, mappedDistance * sin(angle) - h / 2);
    ofDrawLine(-w2 / 2,  h2 / 2, mappedDistance * cos(angle) - w / 2, mappedDistance * sin(angle) + h / 2);
    ofDrawLine( w2 / 2, -h2 / 2, mappedDistance * cos(angle) + w / 2, mappedDistance * sin(angle) - h / 2);
    ofDrawRectangle(mappedDistance * cos(angle), mappedDistance * sin(angle), w, h);
    ofDrawBitmapString(to_string(center.x), 0, 0);
    ofPopMatrix();
    ofPopStyle();
}
