#pragma once

#include "ofMain.h"
#include "ofxTuio.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
		
    
    //TUIOの物体(マーカー)に関係するイベントを追加
    //物体の追加を検知
    void objectAdded(ofxTuioObject & tuioObject);
    //物体の削除を検知
    void objectRemoved(ofxTuioObject & tuioObject);
    //物体の状態の更新を検知
    void objectUpdated(ofxTuioObject & tuioObject);
    
private:
    //TUIOのクライアントのインスタンス化
    myTuioClient tuio;
    //ログの出力用
    string log;
};
