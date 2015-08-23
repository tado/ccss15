#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	receiver.setup(PORT);
    ofSetFrameRate(60);
    ofSetBackgroundAuto(false);
    ofBackground(0);
    ofSetCircleResolution(64);
}

//--------------------------------------------------------------
void ofApp::update(){

}


//--------------------------------------------------------------
void ofApp::draw(){
    // 画面をフェード
    ofSetRectMode(OF_RECTMODE_CORNER);
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    ofSetColor(0, 30);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    // バッファーされたOSCメッセージを処理
    while(receiver.hasWaitingMessages()){
        ofxOscMessage m;
        receiver.getNextMessage(&m);
        
        if(m.getAddress() == "/message"){
            // ノート番号取得
            float noteNum = getValueFromKey(m.getArgAsString(0), "note:");
            // 定位(pan)取得
            float pan = getValueFromKey(m.getArgAsString(0), "pan:");

            // とりだしたノート番号を高さに四角を描く
            int x = ofMap(pan, -1.0, 1.0, ofGetWidth()/4.0, ofGetWidth()/4.0*3.0);
            int y = ofMap(noteNum, 60, 90, ofGetHeight(), 0);
            ofSetColor(255, 250);
            ofEnableBlendMode(OF_BLENDMODE_ADD);
            ofSetColor(ofColor::fromHsb(ofMap(y, 0, ofGetHeight(), 0, 255), 180, 255));
            ofSetRectMode(OF_RECTMODE_CENTER);
            ofRect(x, y, ofGetWidth()/3.0, ofGetHeight() / 20.0);
        }
    }
}

// メッセージのキーワードを指定して、その数値を取得する関数 (digitは桁数)
float ofApp::getValueFromKey(string msg, string key){
    // メッセージをパース、ノート番号だけをとりだし
    const size_t step = key.size();
    
    size_t count(0);
    size_t pos(0) ;
    string msgStr;
    float msgNum;
    
    // キーワードから数値を抽出
    if( (pos = msg.find(key)) != std::string::npos) {
        int current = 0;
        char c;
        msgStr = msg.substr(pos);
        string valueStr = "";
        // , か } を検出するまで値を取得
        while (msgStr[current] != ',' && msgStr[current] != '}') {
            valueStr.insert(valueStr.size(), 1, msgStr[current]);
            current++;
        }
        valueStr = valueStr.substr(key.size() + 1);
        cout << valueStr << endl;
        //msgStr = msg.substr(pos + step, digit);
        msgNum = atof(valueStr.c_str());
        return msgNum;
    } else {
        return 0.0;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
