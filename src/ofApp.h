#pragma once

#include "ofMain.h"
#include "ofxTuio.h"
#include <BaseController.hpp>
#include <RiverController.hpp>
#include <BuildingController.hpp>
#include <MasterObject.hpp>

enum ScapeType {
    RIVER = 1,
    BUILDING = 2,
    MOUNTAIN = 3,
};

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
    bool debugDraw = false;
    //TUIOのクライアントのインスタンス化
    ofxTuioReceiver tuio;
    //ログの出力用
    string log;
    ScapeType currentScapeType = ScapeType::RIVER;
    
    RiverController *riverController = new RiverController(100);
    BuildingController *buildingController = new BuildingController(100);
    MasterObject masterObj;
};
