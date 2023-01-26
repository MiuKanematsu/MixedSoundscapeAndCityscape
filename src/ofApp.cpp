#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //TUIOに関連するイベントリスナーの追加
        ofAddListener(tuio.objectAdded,this,&ofApp::objectAdded);
        ofAddListener(tuio.objectRemoved,this,&ofApp::objectRemoved);
        ofAddListener(tuio.objectUpdated,this,&ofApp::objectUpdated);
    
    //フレームレート設定
        ofSetFrameRate(60);
        //背景を黒に
        ofBackground(0,0,0);
         
        //ポート番号3333で、TUIOの通信開始
        tuio.start(3333);
         
        //ログのテキストを空に
        log="";
}

//--------------------------------------------------------------
void ofApp::update(){
    //TUIOのメッセージを受信
    tuio.getMessage();
}

//--------------------------------------------------------------
void ofApp::draw(){
    //カーソルの状態を表示
    tuio.drawCursors();
    //オブジェクトの状態を表示
    tuio.drawObjects();
    //ログを表示
    ofSetColor(0xffffff);
    ofDrawBitmapString(log, 20, 20);
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
    log = " new object: " + ofToString(tuioObject.getFiducialId())+
    " X: "+ofToString(tuioObject.getX())+
    " Y: "+ofToString(tuioObject.getY())+
    " angle: "+ofToString(tuioObject.getAngleDegrees());
}
void ofApp::objectRemoved(ofxTuioObject & tuioObject){
    //マーカー削除
    log = " object removed: " + ofToString(tuioObject.getFiducialId())+
    " X: "+ofToString(tuioObject.getX())+
    " Y: "+ofToString(tuioObject.getY())+
    " angle: "+ofToString(tuioObject.getAngleDegrees());
}
void ofApp::objectUpdated(ofxTuioObject & tuioObject){
    //マーカーの状態更新
    log = " object updated: " + ofToString(tuioObject.getFiducialId())+
    " X: "+ofToString(tuioObject.getX())+
    " Y: "+ofToString(tuioObject.getY())+
    " angle: "+ofToString(tuioObject.getAngleDegrees());
}

