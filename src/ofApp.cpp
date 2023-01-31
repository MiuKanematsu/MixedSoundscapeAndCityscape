#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //TUIOに関連するイベントリスナーの追加
    ofAddListener(tuio.AddTuioObject,this,&ofApp::objectAdded);
    ofAddListener(tuio.RemoveTuioObject,this,&ofApp::objectRemoved);
    ofAddListener(tuio.UpdateTuioObject,this,&ofApp::objectUpdated);
    
    //フレームレート設定
    ofSetFrameRate(60);
    //背景を黒に
    ofBackground(0,0,0);
     
    //ポート番号3333で、TUIOの通信開始
    tuio.connect();
     
    //ログのテキストを空に
    log="";
}

//--------------------------------------------------------------
void ofApp::update(){
    riverController->update();
    buildingController->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    riverController->drawLine();
    riverController->drawPoints();
    ofPushStyle();
    ofSetColor(255, 0, 0);
    ofDrawEllipse(riverController->getCenter(), 10, 10);
    ofPopStyle();
    
    buildingController->drawLine();
    buildingController->drawPoints();
    ofPushStyle();
    ofSetColor(255, 0, 0);
    ofDrawEllipse(buildingController->getCenter(), 10, 10);
    ofPopStyle();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'r') {
        currentScapeType = ScapeType::RIVER;
    } else if (key == 'b') {
        currentScapeType = ScapeType::BUILDING;
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
        riverController->addPoint(x, y);
    } else if (currentScapeType == ScapeType::BUILDING) {
        buildingController->addPoint(x, y);
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

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
    log = " new object: " + ofToString(tuioObject.getSymbolID())+
    " X: "+ofToString(tuioObject.getX())+
    " Y: "+ofToString(tuioObject.getY())+
    " angle: "+ofToString(tuioObject.getAngleDegrees());
}
void ofApp::objectRemoved(ofxTuioObject & tuioObject){
    //マーカー削除
    log = " object removed: " + ofToString(tuioObject.getSymbolID())+
    " X: "+ofToString(tuioObject.getX())+
    " Y: "+ofToString(tuioObject.getY())+
    " angle: "+ofToString(tuioObject.getAngleDegrees());
}
void ofApp::objectUpdated(ofxTuioObject & tuioObject){
    //マーカーの状態更新
    log = " object updated: " + ofToString(tuioObject.getSymbolID())+
    " X: "+ofToString(tuioObject.getX())+
    " Y: "+ofToString(tuioObject.getY())+
    " angle: "+ofToString(tuioObject.getAngleDegrees());
}

