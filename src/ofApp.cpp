#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundAuto(false);
	ofBackground(0);
	ofEnableAlphaBlending();
	ofSetCircleResolution(1000);
	ofEnableAntiAliasing();
	ofSetFrameRate(60);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
	// If the left mouse button is pressed...
		if (ofGetMousePressed(OF_MOUSE_BUTTON_LEFT)) {

			// Code for the final version of the brush

			ofVec2f mousePos(ofGetMouseX(), ofGetMouseY());
			if (firstFrameAfterClick)
			{
				firstFrameAfterClick = false;
			}
			else {
				if (ofGetFrameNum() % 60)
				{
					distance = sqrt(pow((lastFramePosition - mousePos).x, 2) + pow((lastFramePosition - mousePos).y, 2));
					if (distance < 2.f)
					{
						numTriangles = 2;
					}
					else if (distance < 5.f) {
						numTriangles = 1;
					}
					else if (distance < 10.f) {
						numTriangles = 15;
					}
					else
					{
						numTriangles = 100;
					}
					ofDrawBitmapString(ofToString(distance), 10, 10);
				}
			}

			for (int t = 0; t<numTriangles; ++t) {
				float offsetDistance = ofRandom(minOffset, maxOffset);				

				// Define a triangle at the origin (0,0) that points to the right
				ofVec2f p1(0, 6.25);
				ofVec2f p2(25, 0);
				ofVec2f p3(0, -6.25);

				float rotation = ofRandom(360); // The rotate function uses degrees!
				p1.rotate(rotation);
				p2.rotate(rotation);
				p3.rotate(rotation);

				ofVec2f triangleOffset(offsetDistance, 0.0);
				triangleOffset.rotate(rotation);

				p1 += mousePos + triangleOffset;
				p2 += mousePos + triangleOffset;
				p3 += mousePos + triangleOffset;

				ofColor aqua(0, 252, 255, alpha);
				ofColor purple(198, 0, 205, alpha);
				ofColor inbetween = aqua.getLerped(purple, ofRandom(1.0));
				ofSetColor(inbetween); 				

				ofDrawTriangle(p1, p2, p3);

				ofSetColor(255,255,255);
				ofDrawBitmapString(ofToString(ofGetFrameRate()), 10, 10);
				std::cout << distance << "\n";
				lastFramePosition = mousePos;

			}

			// Alternate code, for the rotating triangle brush discussed in the chapter:

			//        ofVec2f mousePos(ofGetMouseX(), ofGetMouseY());
			//
			//        // Define a triangle at the origin (0,0) that points to the right
			//        ofVec2f p1(0, 25.0);
			//        ofVec2f p2(100, 0);
			//        ofVec2f p3(0, -25.0);
			//
			//        // Rotate the triangle points around the origin
			//        float rotation = ofRandom(360); // Uses degrees!
			//        p1.rotate(rotation);
			//        p2.rotate(rotation);
			//        p3.rotate(rotation);
			//
			//        // Shift the triangle to the mouse position
			//        p1 += mousePos;
			//        p2 += mousePos;
			//        p3 += mousePos;
			//
			//        ofSetColor(255, 50);
			//        ofDrawTriangle(p1, p2, p3);
		}
		else
		{
			distance = 0;
			lastFramePosition.set(0,0);
		}

	// If the right mouse button is pressed...
	if (ofGetMousePressed(OF_MOUSE_BUTTON_RIGHT)) {
		ofBackground(0);  // Erase the screen with a black background
	}
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
	firstFrameAfterClick = true;
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
