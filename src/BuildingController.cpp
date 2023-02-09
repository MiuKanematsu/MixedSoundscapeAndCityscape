//
//  BuildingController.cpp
//  MixedSoundscapeAndCityscape
//
//  Created by 兼松 美羽 on 2023/01/29.
//

#include "BuildingController.hpp"

BuildingController::BuildingController(float _minDistance): BaseController(_minDistance) {
    c = ofColor(0, 0, 255);
}

void BuildingController::update(int _x, int _y) {
    for (auto &bd : buildings) {
        bd.update(_x, _y);
    }
}

void BuildingController::update(ofVec2f _p) {
    this->update(_p.x, _p.y);
}

void BuildingController::drawBuildings() {
    ofPushStyle();
    ofSetRectMode(ofRectMode::OF_RECTMODE_CENTER);
    for (auto bd : buildings) {
        bd.display();
    }
    ofPopStyle();
}

void BuildingController::addPoint(int i, float _x, float _y) {
    if (lines.size() == i) {
        lines.push_back(vector<ofVec2f>());
    }
    
    vector<ofVec2f> &points = lines.at(i);
    if (points.size() == 0) {
        points.push_back(ofVec2f(_x, _y));
    } else {
        bool isContact = false;
        for (ofVec2f p : points) {
            if (intersect(p, ofVec2f(_x, _y), minDistance, minDistance)) {
                isContact = true;
                break;
            }
        }
        if (!isContact) {
            points.push_back(ofVec2f(_x, _y));
            buildings.push_back(Building(ofVec2f(_x, _y), ofRandom(20, 100), ofRandom(20, 100)));
        }
    }
}

// *** debug draw method ***
void BuildingController::drawPoints() {
    ofPushStyle();
    ofSetColor(c);
    BaseController::drawPoints();
    ofPopStyle();
}
