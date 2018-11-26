#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);

	this->bed_image1.loadImage("images/bed1.png");
	this->bed_image2.loadImage("images/bed2.png");
}

//--------------------------------------------------------------
void ofApp::update() {


}

//--------------------------------------------------------------
void ofApp::draw() {

	int size = 120;
	for (int x = 0; x < ofGetWidth(); x += size) {

		float noise_height = ofNoise(x * 0.03, ofGetFrameNum() * 0.03) * ofGetHeight();
		for (int y = 0; y < ofGetHeight(); y += size) {

			noise_height > y ? this->bed_image1.draw(x, y, size, size) : this->bed_image2.draw(x, y, size, size);
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}