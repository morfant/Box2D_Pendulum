//
//  testApp.h
//  cvBody_001
//
//  Created by giy.
//
//

// ---- Preprocessor command ----
#pragma once

// ---- Headers ----
#include "ofMain.h"
#include "World.h"
#include "Ball.h"
#include "Wall.h"
#include "PolygonBody.h"
#include "Box.h"
#include "Pendulum.h"
#include "Spring.h"
#include "MyAABBCallBack.h"

class testApp : public ofBaseApp{
protected:
    // ---- Constants ----
    const float kMOUSE_AABB_LENGTH = 0.0;
    
	public:
		void setup();
		void update();
		void draw();
    
    void clearSprings();
    void clearPendulums();
    void makeBall();
    void makeBox();
    void makeSpring();
    void clearBallsAndBoxes();
    float getArea(b2Vec2* vertices, int maxVCount);
    
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);		


    // World
    World*      aWorld;
    b2World*    iWorld; //aWorld -> getWorld()
    
    // Ball
    Ball*    aBall;
    
    ofVec2f tVec;
    
    // Wall
    Wall    *left, *right, *floor, *ceil;
    
    // container
    vector<Ball*> balls;
    vector<Box*> boxes;
    vector<Pendulum*> pendulums;
    vector<Spring*> springs;
    
    // using mouse Dragging
    MyAABBCallBack callback;
    b2AABB      aabb;
    b2Body*     tBody;
    b2Vec2*     tTarget;



};

