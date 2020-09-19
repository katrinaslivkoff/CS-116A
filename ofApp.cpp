#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	cam.setDistance(30.0);
	cam.lookAt(glm::vec3(0, 0, 0));
	ofSetBackgroundColor(ofColor::black);

	// harcode test triangle
	//
	mesh.verts.push_back(glm::vec3(0, 0, 2));
	mesh.verts.push_back(glm::vec3(0, 0, 0));
	mesh.verts.push_back(glm::vec3(2, 0, 0));
	mesh.verts.push_back(glm::vec3(1, 2, 1));
	mesh.verts.push_back(glm::vec3(2, 0, 2));

	mesh.triangles.push_back(Triangle(1, 2, 5));
	mesh.triangles.push_back(Triangle(2, 3, 5));
	mesh.triangles.push_back(Triangle(3, 4, 5));
	mesh.triangles.push_back(Triangle(4, 1, 5));
	mesh.triangles.push_back(Triangle(4, 2, 5));
	

	// Creates a new mesh variable for the monster object file
	//
	objMesh.readObjFile("monster.obj");

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	cam.begin();
//	ofDrawGrid();
//	ofSetColor(0, 255, 0); //red, gree, blue components for RGB space

	//X
	//
	ofSetColor(ofColor::red);
	ofDrawLine(glm::vec3(0, 0, 0), glm::vec3(5.0, 0, 0));

	//Y
	//
	ofSetColor(ofColor::green);
	ofDrawLine(glm::vec3(0, 0, 0), glm::vec3(0, 5.0, 0));

	//Z
	//
	ofSetColor(ofColor::blue);
	ofDrawLine(glm::vec3(0, 0, 0), glm::vec3(0, 0, 5.0));

	// if the monster is true, then draw the monster
	// else draw the pyramid mesh
	//
	if (monster) 
	{
		objMesh.draw();
	}
	else 
	{
		mesh.draw();
	}

	cam.end();
}

void ofApp::drawAxis()
{

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	// helps with switching between pyramid mesh and monster
	//
	switch (key)
	{
	case 'm':
		if (monster)
		{
			monster = false;
		}
		else
		{
			monster = true;
		}
		break;
	default:
		break;
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

//--------------------------------------------------------------
void ofApp::readObjFile(string name) {

}
