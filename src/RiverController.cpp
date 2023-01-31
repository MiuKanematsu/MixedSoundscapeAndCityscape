//
//  RiverController.cpp
//  MixedSoundscapeAndCityscape
//
//  Created by Katsuya Endoh on 2023/01/29.
//

#include "RiverController.hpp"

RiverController::RiverController(float _minDistance): BaseController(_minDistance) {
}

void RiverController::addRivers(int num) {
    for (int i = 0; i < num; i++) {
        riverParticles.push_back(RiverParticle(points.at(0)));
    }
}

void RiverController::drawPoints(){
    ofPushStyle();
    ofSetColor(c);
    // TODO: superを修正
//    super.drawPoints();
    ofPopStyle();
}
