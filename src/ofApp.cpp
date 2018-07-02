#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	minDistance = 10;
	leftMouseButtonPressed = false;
}

//--------------------------------------------------------------
void ofApp::update(){
	if (leftMouseButtonPressed) {
		ofVec2f mousePos(ofGetMouseX(),ofGetMouseY());
		if (lastPoint.distance(mousePos) >= minDistance) {
			currentPolyline.curveTo(mousePos.x,mousePos.y);
			lastPoint = mousePos;
		}
		
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	ofSetLineWidth(10);
	for (int i=0; i<polylines.size(); i++) {
		ofSetColor(25*i, 0, 125);
		ofPolyline polyline = polylines[i];
		polyline.draw();
		vector <glm::vec3> vertices = polyline.getVertices();
		for (int vertexIndex=0; vertexIndex<vertices.size(); vertexIndex++) {
			glm::vec3 vertex = vertices[vertexIndex];
			ofDrawCircle(vertex, 10);
		}
	}
	ofSetColor(255, 0, 125);
	currentPolyline.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
	//for ( vector<ofPolyline>::iterator it = polylines.begin(); it != polylines.end(); it++ )
	for ( lineVec::iterator it = polylines.begin(); it != polylines.end(); it++ )
	{

		cout << (*it).size() << endl;
		printf("ofPolyLine container at %p\n", &it);
		printf("ofPolyLine at %p\n", &(*it));
		//cout << "ofPolyLine Container at : " << (*it) << endl;
		
		
	}
	
	if((polylines.size() != 0) && key == 'z') {
		
		ofPolyline tmp = *prev(polylines.end());
		deletedPolylines.push_back(tmp);
		polylines.pop_back();
		
	}
	if((deletedPolylines.size() != 0) && key == 'x') {
		ofPolyline tmp = *prev(deletedPolylines.end());
		polylines.push_back(tmp);
		deletedPolylines.pop_back();
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

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if(button == OF_MOUSE_BUTTON_LEFT) {
		leftMouseButtonPressed = true;
		currentPolyline.curveTo(x, y);
		currentPolyline.curveTo(x, y);
		lastPoint.set(x,y);
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	if (button == OF_MOUSE_BUTTON_LEFT) {
		leftMouseButtonPressed = false;
		currentPolyline.curveTo(x, y);
		polylines.push_back(currentPolyline);
		currentPolyline.clear();
	}

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
