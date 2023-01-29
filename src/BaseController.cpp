//
//  BaseController.cpp
//  MixedSoundscapeAndCityscape
//
//  Created by Katsuya Endoh on 2023/01/29.
//

#include "BaseController.hpp"

BaseController::BaseController(float _minDistance) {
    this->minDistance = _minDistance;
    points.push_back(ofVec2f(100, 100));
    points.push_back(ofVec2f(200, 200));
    points.push_back(ofVec2f(200, 300));
}

void BaseController::update() {
//    std::cout << "BaseController::update()" << std::endl;
}

void BaseController::drawLine() {
    ofPushStyle();
    ofSetColor(255);
    for (int i = 1; i < points.size(); i++) {
        ofVec2f p1 = points.at(i - 1);
        ofVec2f p2 = points.at(i);
        ofDrawLine(p1, p2);
    }
    ofPopStyle();
}

void BaseController::drawPoints(){
    ofPushStyle();
    ofSetColor(255);
    for (int i = 0; i < points.size(); i++) {
        ofDrawEllipse(points.at(i), 10, 10);
    }
    ofPopStyle();
}

ofVec2f BaseController::getCenter(){
    ofVec2f p = ofVec2f(0, 0);
    for (int i = 0; i < points.size(); i++) {
        p.x += points.at(i).x;
        p.y += points.at(i).y;
    }
    p.x = p.x / points.size();
    p.y = p.y / points.size();
    return p;
}
