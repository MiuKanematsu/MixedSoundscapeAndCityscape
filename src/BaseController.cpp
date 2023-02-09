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
    for (int i = 0; i < lines.size(); i++) {
        vector<ofVec2f> points = lines.at(i);
        for (int j = 1; j < points.size(); j++) {
            ofVec2f p1 = points.at(j - 1);
            ofVec2f p2 = points.at(j);
            ofDrawLine(p1, p2);
        }
    }
    ofPopStyle();
}

void BaseController::drawPoints(){
    ofPushStyle();
    ofSetColor(255);
    for (int i = 0; i < lines.size(); i++) {
        vector<ofVec2f> points = lines.at(i);
        for (int j = 0; j < points.size(); j++) {
            ofDrawEllipse(points.at(j), 10, 10);
        }
    }
    ofPopStyle();
}

vector<ofVec2f> BaseController::getCenters(){
    vector<ofVec2f> centers;
    for (int i = 0; i < lines.size(); i++) {
        ofVec2f center = ofVec2f(0, 0);
        vector<ofVec2f> points = lines.at(i);
        for (int j = 0; j < points.size(); j++) {
            center += points.at(j);
        }
        center /= points.size();
        centers.push_back(center);
    }
    return centers;
}

bool BaseController::addPoint(int i, float x, float y) {
    ofVec2f targetPoint = ofVec2f(x, y);
    
    if (i >= lines.size()) {
        lines.push_back(vector<ofVec2f>());
    }
    
    vector<ofVec2f> &points = lines.at(i);
    if (points.size() == 0) {
        points.push_back(targetPoint);
        return true;
    }
    
    ofVec2f lastPonint = points.at(points.size() - 1);
    float distance = lastPonint.distance(targetPoint);
    if (distance > minDistance) {
        points.push_back(targetPoint);
        return true;
    }
    
    return false;
}

bool BaseController::intersect(ofVec2f _p1, ofVec2f _p2, float _w, float _h) {
    return (_p1.x - _w / 2 < _p2.x + _w / 2 && _p1.x + _w / 2 > _p2.x - _w / 2 &&
            _p1.y - _h / 2 < _p2.y + _h / 2 && _p1.y + _h / 2 > _p2.y - _h / 2);
}
