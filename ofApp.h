#pragma once

#include "ofMain.h"
#include <fstream>
#include <iostream>

class Triangle {
public:
	Triangle(int i1, int i2, int i3) { i = i1, j = i2, k = i3; }
	int i, j, k;
};

class MyMesh {
public:
	vector<glm::vec3> verts;
	vector<Triangle> triangles;

	// indexed triangle method
	//
	void draw() {
		for (size_t n = 0; n < triangles.size(); n++)
		{
			ofNoFill();
			ofSetColor(ofColor::mediumPurple);
			ofDrawTriangle(verts[triangles[n].i - 1], verts[triangles[n].j - 1], verts[triangles[n].k - 1]);
		}
	}	

	void addVert(double x, double y, double z) {
		verts.push_back(glm::vec3(x, y, z));
	}

	void addTriangle(int i, int j, int k) {		
		triangles.push_back(Triangle(i, j, k));
	}

	// most of this code given in class
	//
	void readObjFile(string name) {
		string line;
		ofFile file;
		float sizeOfFile = 0;
		//  Open file, return if error
		//
		file.open("monster.obj");
		if (!file.open(name)) {
			cout << "can't open file: " << name << endl;
			return;
		}
		// read each line in file and process vertices and faces
		//
		while (getline(file, line)) {
			sizeOfFile++;
			if (line.size() < 3) continue;  // ignore shorter lines
			// vertex case
			//
			if (line.at(0) == 'v' && line.at(1) == ' ') {
				istringstream iss(line);
				string type;
				double x, y, z;
				iss >> type >> x >> y >> z;
				// 
				// add vertex to mes
				//
				// mesh.addVert(x, y, z);
				addVert(x, y, z);
			}
			//  face case
			//
			else if (line.at(0) == 'f') {
				//  do something similiar to vertex case abave
				//
				// 
				// add triangle to mesh
				//   
				//      mesh.addTriangle(i, j, k);
				istringstream iss(line);
				string type;
				double i, j, k;
				iss >> type >> i >> j >> k;
				addTriangle(i, j, k);
			}
		}

		cout << "Total number of vertices: " << verts.size() << endl;
		cout << "Total number of faces: " << triangles.size() << endl;
		cout << "Size of my Mesh structure: " << sizeOfFile / 1000 << " kB" << endl;

		file.close();
	}
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

		void drawAxis();

		void readObjFile(string name);

		ofEasyCam cam;

		MyMesh mesh;

		MyMesh objMesh;

		bool mouse = true, monster = false; 
};
