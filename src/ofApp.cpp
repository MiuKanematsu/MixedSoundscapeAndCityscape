#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFullscreen(true);
    
    //ポート番号3333で、TUIOの通信開始
    tuio.setup(new ofxTuioUdpReceiver(3333));
    //TUIOに関連するイベントリスナーの追加
    ofAddListener(tuio.AddTuioObject, this,&ofApp::objectAdded);
    ofAddListener(tuio.RemoveTuioObject, this,&ofApp::objectRemoved);
    ofAddListener(tuio.UpdateTuioObject, this,&ofApp::objectUpdated);
    tuio.connect();
    
    //フレームレート設定
    ofSetFrameRate(60);
    //背景を黒に
    ofBackground(0, 0, 0);
    
    //ログのテキストを空に
    masterObj = MasterObject();
    masterObj.setPosition(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
}

//--------------------------------------------------------------
void ofApp::update(){
    riverController->update();
    buildingController->update(masterObj.getPosition());
    masterObj.update(ofGetMouseX(), ofGetMouseY(), 100);
}

//--------------------------------------------------------------
void ofApp::draw(){
    if (debugDraw) {
        riverController->drawLine();
        riverController->drawPoints();
        
        ofPushStyle();
        ofSetColor(255, 0, 0);
        for (auto center : riverController->getCenters()) {
            ofDrawEllipse(center, 10, 10);
        }
        ofPopStyle();
        
        buildingController->drawLine();
        buildingController->drawPoints();
        ofPushStyle();
        ofSetColor(255, 0, 0);
        for (auto center : buildingController->getCenters()) {
            ofDrawEllipse(center, 10, 10);
        }
        ofPopStyle();
        
        mountainController->drawLine();
        mountainController->drawPoints();
        ofPushStyle();
        ofSetColor(255, 0, 0);
        for (auto center : mountainController->getCenters()) {
            ofDrawEllipse(center, 10, 10);
        }
        ofPopStyle();
        
        mountainController->drawArea();
    }
    
    buildingController->drawBuildings();
    riverController->drawRiver();
    mountainController->draw();
    masterObj.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'r') {
        currentScapeType = ScapeType::RIVER;
    } else if (key == 'b') {
        currentScapeType = ScapeType::BUILDING;
    }  else if (key == 'm') {
        currentScapeType = ScapeType::MOUNTAIN;
    } else if (key == ' ') {
        currentScapeType = ScapeType::MASTER;
    } else if (key == 'd') {
        debugDraw = !debugDraw;
    } else if (key == 's') {
        cout << riverController->getLineCount() << endl;
        cout << "test" << endl;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    if (currentScapeType == ScapeType::RIVER) {
        riverController->addPoint(riverController->getLineCount() - 1, x, y);
    } else if (currentScapeType == ScapeType::BUILDING) {
        buildingController->addPoint(buildingController->getLineCount() - 1, x, y);
    } else if (currentScapeType == ScapeType::MOUNTAIN) {
        mountainController->addPoint(mountainController->getLineCount() - 1, x, y);
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if (currentScapeType == ScapeType::RIVER) {
        riverController->addPoint(riverController->getLineCount(), x, y);
    } else if (currentScapeType == ScapeType::BUILDING) {
        buildingController->addPoint(buildingController->getLineCount(), x, y);
    } else if (currentScapeType == ScapeType::MOUNTAIN) {
        mountainController->addPoint(mountainController->getLineCount(), x, y);
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::objectAdded(ofxTuioObject & tuioObject){
    //マーカー追加
    string log = " new object: " + ofToString(tuioObject.getSymbolID())+
    " X: " + ofToString(tuioObject.getX())+
    " Y: " + ofToString(tuioObject.getY())+
    " angle: " + ofToString(tuioObject.getAngleDegrees());
    
    // TODO: ここにIDとの対応関係を追加
    if (tuioObject.getSymbolID() == 3) {
        riverController->addPoint(riverController->getLineCount(),
                                  tuioObject.getScreenX(ofGetWindowWidth()),
                                  tuioObject.getScreenY(ofGetWindowHeight()));
        cout << log << endl;
    }
}

void ofApp::objectRemoved(ofxTuioObject & tuioObject){
    //マーカー削除
    string log = " object removed: " + ofToString(tuioObject.getSymbolID())+
    " X: " + ofToString(tuioObject.getX())+
    " Y: " + ofToString(tuioObject.getY())+
    " angle: " + ofToString(tuioObject.getAngleDegrees());
//    cout << log << endl;
}

void ofApp::objectUpdated(ofxTuioObject & tuioObject){
    //マーカーの状態更新
    string log = " object updated: " + ofToString(tuioObject.getSymbolID())+
    " X: " + ofToString(tuioObject.getX())+
    " Y: " + ofToString(tuioObject.getY())+
    " angle: " + ofToString(tuioObject.getAngleDegrees());
    
    // TODO: ここにIDとの対応関係を追加
    if (tuioObject.getSymbolID() == 3) {
        riverController->addPoint(riverController->getLineCount() - 1,
                                  tuioObject.getScreenX(ofGetWindowWidth()),
                                  tuioObject.getScreenY(ofGetWindowHeight()));
        cout << log << endl;
    }
}
