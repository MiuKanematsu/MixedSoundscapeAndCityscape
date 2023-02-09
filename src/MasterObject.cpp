//
//  MasterObject.cpp
//  MixedSoundscapeAndCityscape
//
//  Created by Katsuya Endoh on 2023/02/09.
//

#include "MasterObject.hpp"

MasterObject::MasterObject() {
    wh = 100;
    speed = 0.7;
    angle = 0;
    this->setPosition(0, 0);
}

void MasterObject::setPosition(float _x, float _y) {
    x = _x;
    y = _y;
    radiusX = x;
    radiusY = y;
}

void MasterObject::draw() {
    ofPushStyle();
    ofFill();
    ofSetColor(255, 255, 0, 50);
    ofDrawEllipse(x, y, wh, wh);
    ofDrawBitmapString(to_string(x), x, y);
    ofPopStyle();
}

void MasterObject::move() {
    angle += ofDegToRad(speed);
    float dx = abs(ofGetWindowWidth() / 2 - radiusX);
    float dy = abs(ofGetWindowHeight() / 2 - radiusY);
    x = ofGetWindowWidth()  / 2 + cos(angle) * dx;
    y = ofGetWindowHeight() / 2 + sin(angle) * dy;
}

bool MasterObject::isInside(float _x, float _y, float _distance) {
    return ofDist(x, y, _x, _y) < _distance;
}

void MasterObject::update(float _x, float _y, float _distance) {
    if (isInside(_x, _y, _distance) && ofGetMousePressed()) {
        x = _x;
        y = _y;
        radiusX = x;
        radiusY = y;
        angle = atan2(y - ofGetWindowHeight() / 2, x - ofGetWindowWidth() / 2);
    } else {
        move();
    }
}

ofVec2f MasterObject::getPosition() {
    return ofVec2f(x, y);
}
