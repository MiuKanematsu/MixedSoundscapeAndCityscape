//
//  BaseController.cpp
//  MixedSoundscapeAndCityscape
//
//  Created by Katsuya Endoh on 2023/01/29.
//

#include "BaseController.hpp"

BaseController::BaseController(float _minDistance) {
    this->minDistance = _minDistance;
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
        p += points.at(i);
    }
    p /= points.size();
    return p;
}

void BaseController::addPoint(float x, float y) {
    ofVec2f targetPoint = ofVec2f(x, y);
    
    if (points.size() == 0) {
        points.push_back(targetPoint);
    } else {
        ofVec2f lastPonint = points.at(points.size() - 1);
        float distance = lastPonint.distance(targetPoint);
        if (distance > minDistance) {
            points.push_back(targetPoint);
        }
    }
}
