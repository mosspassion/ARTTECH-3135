#line 1 "Ball"

#include "ofMain.h"


#line 1 "Ball"
class Ball {
public:
	Ball() {
        // initialize all of the variables.	 
        // initialization list is also an option.        
        x = 0;
        y = 0;
        vx = 0;
        vy = 0;
        r = 10;
        color = ofColor(255);
	}	
	
	// draw the ball with the color and radius.
	void draw() {
	    ofFill();
	    ofSetColor(color);
	    ofCircle(x, y, r);
	}
	
	// update the position of the ball with the velocity.
	void update() {
	    x = x + vx;
	    y = y + vy;
	}
	
	float x; // Ball x velocity.
	float y; // Ball y position.
	float vx;// Ball x velocity.
	float vy; // Ball y velocity.
	float r; // Ball radius.
	ofColor color; // Ball class.
	
};

