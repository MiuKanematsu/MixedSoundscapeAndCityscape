//
//  RiverParticle.cpp
//  MixedSoundscapeAndCityscape
//
//  Created by 兼松 美羽 on 2023/01/31.
//

#include "RiverParticle.hpp"

RiverParticle::RiverParticle(ofVec2f p) {
    position = ofVec2f(p.x, p.y);
    init();
}

void RiverParticle::init() {
    acceleration = ofVec2f(0, 0);
    velocity = ofVec2f(ofRandom(-2, 2), ofRandom(-2, 2));
    maxspeed = ofRandom(1, 3);
    maxforce = ofRandom(0.1, 0.9);
    r = ofRandom(3, 10);
    targetNum = 0;
    targetMinDist = 15;
    int n = 20;
    targetPlay = ofVec2f(ofRandom(-n, n), ofRandom(-n, n));
    //c = color(0,int(random(0,50)),int(random(180,255)));
    //c = color(int(random(180, 240)), int(random(30, 100)), 100);
    c = ofColor::fromHsb(
                         ofMap(ofRandom(180, 240), 0, 360, 0, 255),
                         ofMap(ofRandom(0, 20), 0, 100, 0, 255),
                         255);
}

void RiverParticle::update() {
    velocity += acceleration;
    velocity.limit(maxspeed);
    position += velocity;
    acceleration *= 0;
}

void RiverParticle::applyForce(ofVec2f force) {
    acceleration += force;
}

void RiverParticle::seek(vector<ofVec2f> targets) {
    ofVec2f target = targets.at(targetNum) + targetPlay;
    if (ofDist(target.x, target.y, position.x, position.y) < targetMinDist) {
        targetNum++;
        if (targets.size() == targetNum) {
            position = targets.at(0);
            init();
        }
    }
    ofVec2f desired = target - position;
    desired.normalize();
    desired *= maxspeed;
    ofVec2f steer = desired - velocity;
    steer.limit(maxforce);
    this->applyForce(steer);
}

void RiverParticle::display() {
    ofPushStyle();
    ofNoFill();
    ofSetColor(c);
    ofDrawEllipse(position.x, position.y, r, r);
    ofPopStyle();
}
