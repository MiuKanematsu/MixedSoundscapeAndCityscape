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
    
    baseController->addPoint(100, 100);
    baseController->addPoint(200, 200);
    baseController->addPoint(200, 250); // 追加できない例
    baseController->addPoint(200, 400);
    baseController->addPoint(400, 400);
    baseController->deletePoint(0);
    baseController->deletePoints(2);
    baseController->addPoint(100, 100);
    
    riverController->addPoint(100, 100);
    riverController->addPoint(200, 200);
    riverController->addPoint(200, 250); // 追加できない例
    riverController->addPoint(200, 400);
    riverController->addPoint(400, 400);
    riverController->deletePoint(0);
    riverController->deletePoints(2);
    riverController->addPoint(100, 100);
}

//--------------------------------------------------------------
void ofApp::update(){
    baseController->update();
    riverController->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
//    baseController->drawLine();
//    baseController->drawPoints();
//    ofPushStyle();
//    ofSetColor(255, 0, 0);
//    ofDrawEllipse(baseController->getCenter(), 10, 10);
//    ofPopStyle();
    
    
    riverController->drawLine();
    riverController->drawPoints();
    ofPushStyle();
    ofSetColor(255, 0, 0);
    ofDrawEllipse(riverController->getCenter(), 10, 10);
    ofPopStyle();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

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

