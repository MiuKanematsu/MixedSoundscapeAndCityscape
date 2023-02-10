//
//  MountainController.cpp
//  MixedSoundscapeAndCityscape
//
//  Created by Katsuya Endoh on 2023/02/09.
//

#include "MountainController.hpp"

ofPoint* ofVec2fsToVerts(vector<ofVec2f> vecs) {
    ofPoint* points = new ofPoint[vecs.size()];
    for (int i = 0; i < vecs.size(); i++) {
        points[i] = ofPoint(vecs.at(i));
    }
    return points;
}

ofVec2f calcCenter(vector<ofVec2f> vecs) {
    ofVec2f center(0, 0);
    for (auto vec : vecs) {
        center += vec;
    }
    center /= vecs.size();
    return center;
}

/**
 * 周期的パーリンノイズ
 * 参考文献: https://note.com/deconbatch/n/nc14219bfacc6
 * @param {*} rad
 * @param {*} t
 * @returns
 */
float cyclicNoise(float rad, float t) {
  float xInit = 1000;
  float yInit = 1000;
  float rBase = 100;
  return ofNoise(
    xInit + rBase * cos(rad) * 0.02 + t,
    yInit + rBase * sin(rad) * 0.02 + t
    );
}


MountainController::MountainController(float _minDistance): BaseController(_minDistance) {
    c = ofColor(0, 255, 0);
}

void MountainController::drawArea() {
    ofPushStyle();
    ofSetColor(100, 200, 250, 100);
    ofFill();
    for (auto line : lines) {
        ofBeginShape();
        for (auto point : line) {
            ofVertex(point);
        }
        ofEndShape();
    }
    ofPopStyle();
}

void MountainController::draw() {
    int maxAreaLevel = 5;
    ofPushStyle();
    ofFill();
    ofSetColor(255, 255 / maxAreaLevel);
    for (int i = 0; i < lines.size(); i++) {
        auto line = lines.at(i);
        // MEMO: https://github.com/openframeworks/openFrameworks/issues/901
        ofPolyline poly;
        poly.close();
        ofVec2f center = calcCenter(line);
        for (auto point : line) {
            poly.addVertex(point.x - center.x, point.y - center.y);
        }
        
        int divideCount = 5;
        for (int j = 0; j < poly.size(); j++) {
            ofVec2f v1 = poly.getVertices().at(j);
            int nextIndex = j == poly.size() - 1 ? 0 : j + 1;
            ofVec2f v2 = poly.getVertices().at(nextIndex);
            ofVec2f lineVec = v2 - v1;
            for (int k = 1; k < divideCount; k++) {
                ofVec2f dividedVec = lineVec / divideCount * k;
                ofVec2f insertedVec = v1 + dividedVec;
                ofVec2f normalizedVec = insertedVec.getNormalized();
                insertedVec += normalizedVec * (cyclicNoise(atan2(normalizedVec.x, normalizedVec.y), 1) * 15);
                poly.insertVertex(insertedVec.x, insertedVec.y, 0, j + 1);
                j++;
            }
        }
        
        float maxArea = ofGetWindowWidth() * ofGetWindowHeight() / 10;
        float area = poly.getArea() > maxArea ? maxArea : poly.getArea();
        int areaLevel = int(ofMap(area, 0, maxArea, 1, maxAreaLevel));
        ofPushMatrix();
        ofTranslate(center);
        for (int j = 1; j <= areaLevel; j++) {
            ofPushMatrix();
            ofBeginShape();
            float s = j / float(areaLevel);
            ofScale(s);
            for (auto ver : poly.getVertices()) {
                ofVertex(ver.x, ver.y);
            }
            ofEndShape();
            ofPopMatrix();
        }
        ofPopMatrix();
    }
    ofPopStyle();
}
