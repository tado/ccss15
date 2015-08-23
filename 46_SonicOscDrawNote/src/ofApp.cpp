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
    ofSetColor(0, 10);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    // バッファーされたOSCメッセージを処理
    while(receiver.hasWaitingMessages()){
        ofxOscMessage m;
        receiver.getNextMessage(&m);
        
        if(m.getAddress() == "/message"){
            // メッセージをパース、ノート番号だけをとりだし
            string needle = "note: ";
            const size_t step = needle.size();
            
            size_t count(0);
            size_t pos(0) ;
            string msg = m.getArgAsString(0);
            string noteStr;
            float noteNum;
            
            // キーワードから数値を抽出
            if( (pos = msg.find(needle)) != std::string::npos) {
                noteStr = msg.substr(pos + step, 2);
                noteNum = atof(noteStr.c_str());
            }
            
            // とりだしたノート番号を表示
            cout << noteStr << endl;
            
            // とりだしたノート番号を高さに四角を描く
            int x = int(ofGetElapsedTimef() * 200) % int(ofGetWidth());
            int y = ofMap(noteNum, 60, 80, ofGetHeight(), 0);
            ofSetColor(255, 250);
            ofSetRectMode(OF_RECTMODE_CENTER);
            ofRect(x, y, 15, 15);
        }
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
