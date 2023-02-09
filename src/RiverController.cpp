//
//  RiverController.cpp
//  MixedSoundscapeAndCityscape
//
//  Created by Katsuya Endoh on 2023/01/29.
//

#include "RiverController.hpp"

RiverController::RiverController(float _minDistance): BaseController(_minDistance) {
    c = ofColor(0, 255, 0);
}

void RiverController::drawRiver() {
    if (riverParticles.size() > 0) {
        ofPushStyle();
        for (auto river : riverParticles) {
            for (auto particle : river) {
                particle.display();
            }
        }
        ofPopStyle();
    }
}

void RiverController::update() {
    for (int i = 0; i < riverParticles.size(); i++) {
        vector<RiverParticle> &river = riverParticles.at(i);
        vector<ofVec2f> points = lines.at(i);
        for (auto &particle : river) {
            particle.seek(points);
            particle.update();
        }
    }
}

bool RiverController::addPoint(int riverIndex, float x, float y) {
    if (lines.size() == riverIndex) {
        lines.push_back(vector<ofVec2f>());
    }
    
    auto points = lines.at(riverIndex);
    if (points.size() > 0) {
        ofVec2f lastPoint = points.at(points.size() - 1);
        float dist = ofDist(x, y, lastPoint.x, lastPoint.y);
        if(dist > minDistance) addRivers(riverIndex, 5);
    }
    
    return BaseController::addPoint(riverIndex, x, y);
}

void RiverController::addRivers(int riverIndex, int num) {
    if (riverParticles.size() == riverIndex) {
        riverParticles.push_back(vector<RiverParticle>());
    }
    
    auto &river = riverParticles.at(riverIndex);
    auto points = lines.at(riverIndex);
    for (int i = 0; i < num; i++) {
        river.push_back(RiverParticle(points.at(0)));
    }
}

void RiverController::drawPoints(){
    ofPushStyle();
    ofSetColor(c);
    BaseController::drawPoints();
    ofPopStyle();
}
