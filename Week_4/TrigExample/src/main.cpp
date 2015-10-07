#line 1 "TrigExample"

#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:

#line 1 "TrigExample"
float angle; // Angle in radians.
float angularVelocity; // Angular velocity in radians / unit time.

float radius; // Radius => hypotenuse

float x0; // X origin
float y0; // Y origin

float x1; // X => adjacent
float y1; // Y => opposite

void setup() 
{
    ofSetWindowShape(400, 400);
    
	angle = 0;
	angularVelocity = ofDegToRad(1);	
	
    x0 = ofGetWidth() / 2;
    y0 = ofGetHeight() / 2;    

    radius = 150;
    
    x1 = 0;
    y1 = 0;
}


void update()
{
    x0 = ofGetWidth() / 2;
    y0 = ofGetHeight() / 2;    

    radius = std::min(ofGetWidth(), ofGetHeight()) / 2.0f * 0.8f;

    angle += angularVelocity;
}

void draw() 
{
    ofBackground(ofColor::black);
    
    x1 = x0 + radius * cos(angle);
    y1 = y0 + radius * sin(angle);
        
    ofSetColor(ofColor::yellow);
    ofLine(x0, y0, x1, y1);
    
    ofPath arc0;
    arc0.setCircleResolution(32);
    arc0.setFilled(false);
    arc0.setStrokeWidth(1);
    arc0.setStrokeColor(ofColor::white);
    arc0.arc(x0, y0, radius / 2.0f, radius / 2.0f, ofRadToDeg(0), ofRadToDeg(angle));
    
    arc0.draw();
    
    
}


void keyPressed(int key)
{
    if (key == 'a')
    {
        angularVelocity += ofDegToRad(1);
    }
    else if (key == 'z')
    {
        angularVelocity -= ofDegToRad(1);
    }
    else if (key == ' ')
    {
        angularVelocity = 0;
    }
}



};

int main()
{
    ofSetupOpenGL(320, 240, OF_WINDOW);
    ofRunApp(new ofApp());
}

