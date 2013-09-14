#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    
    // Box2D
    // Make & init containder - balls
    balls.clear();
    pendulums.clear();
    springs.clear();
    
    // World
    aWorld = new World();
    iWorld = aWorld -> getWorld();
    
    // Wall
    left = new Wall(iWorld, b2Vec2(0, 0), b2Vec2(0, ofGetHeight()), ofGetHeight());
    
    right = new Wall(iWorld, b2Vec2(ofGetWidth(), 0), b2Vec2(ofGetWidth(), ofGetHeight()), ofGetHeight());
    
    floor = new Wall(iWorld, b2Vec2(0, ofGetHeight()), b2Vec2(ofGetWidth(), ofGetHeight()), ofGetWidth());
    
    ceil = new Wall(iWorld, b2Vec2(0, 0), b2Vec2(ofGetWidth(), 0), ofGetWidth());

    // Pendulum
    if(pendulums.size() == 0){
        Pendulum* aPendulum = new Pendulum(iWorld, ofGetWidth()/2.f, ofGetHeight()/2.f);
        pendulums.push_back(aPendulum);
    }
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    // Box2D world update
	float32 timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;
    iWorld->Step(timeStep, velocityIterations, positionIterations);
    
    if(springs.size() != 0){
        springs[0]->update(mouseX, mouseY);
    }
       
}

//--------------------------------------------------------------
void testApp::draw(){

    // Set basic draw options
    ofSetLineWidth(1.0);
    ofSetRectMode(OF_RECTMODE_CORNER);
    
    // Draw ball
    ofColor(255, 0, 0);
    ofFill();
    for (vector<Ball*>::iterator iter = balls.begin(); iter != balls.end(); iter++) {
        (*iter)->renderAtBodyPosition();
    }

    // Draw boxes
    ofColor(0, 255, 0);
    ofFill();
    for (vector<Box*>::iterator iter = boxes.begin(); iter != boxes.end(); iter++) {
        (*iter)->renderAtBodyPosition();
    }
    
    
    // Draw pendulums
    ofColor(0, 0, 200);
    ofFill();
    for (vector<Pendulum*>::iterator iter = pendulums.begin(); iter != pendulums.end(); iter++) {
        (*iter)->renderAtBodyPosition();
    }

    
    // Draw walls
    ofColor(255, 250, 0);
    ofNoFill();
    left->renderAtBodyPosition();
    right->renderAtBodyPosition();
    floor->renderAtBodyPosition();
    ceil->renderAtBodyPosition();
    
    // Draw mouseJoint(spring)
    if (springs.size() != 0)
        springs[0]->renderAtBodyPosition();
    
}

void testApp::clearSprings(){
    
    for (vector<Spring*>::iterator iter = springs.begin(); iter != springs.end(); iter++) {
        delete *iter;
    }
    
    springs.clear();
//    cout<<"Spring is deleted."<<endl;
}


void testApp::clearPendulums(){

    // clear b2Body
    for (vector<Pendulum*>::iterator iter = pendulums.begin(); iter != pendulums.end(); iter++) {
        delete *iter;
    }
    
    // clear circle
    pendulums.clear();
}

void testApp::makeBall(){
    Ball * aBall = new Ball(iWorld, mouseX, mouseY, false);
    balls.push_back(aBall);
}

void testApp::makeBox(){
    Box * aBox = new Box(iWorld, mouseX, mouseY, false);
    boxes.push_back(aBox);
}

void testApp::makeSpring(){
    callback.resetBody();
    
    aabb.lowerBound.Set(_toWorldX(mouseX) - kMOUSE_AABB_LENGTH, _toWorldY(mouseY) - kMOUSE_AABB_LENGTH);
    aabb.upperBound.Set(_toWorldX(mouseX) + kMOUSE_AABB_LENGTH, _toWorldY(mouseY) + kMOUSE_AABB_LENGTH);
    
    iWorld->QueryAABB(&callback, aabb);
    
    tBody = callback.getBody();
    tTarget = new b2Vec2(_toWorldX(mouseX), _toWorldY(mouseY));
    
    if (tBody) {
        Spring* spring = new Spring(iWorld, floor->getBody(), tBody, tTarget);
        springs.push_back(spring);
//        cout<<"Spring is added."<<endl;
    }
}

void testApp::clearBallsAndBoxes(){

    // clear b2Body
    for (vector<Ball*>::iterator iter = balls.begin(); iter != balls.end(); iter++) {
        iWorld->DestroyBody((*iter)->getBody());
    }

    // clear b2Body
    for (vector<Box*>::iterator iter = boxes.begin(); iter != boxes.end(); iter++) {
        iWorld->DestroyBody((*iter)->getBody());
    }
    
    
    // clear circle
    balls.clear();
    boxes.clear();
}



//--------------------------------------------------------------
void testApp::keyPressed(int key){

	switch (key){
        case 'k':
            clearPendulums();
            break;

        case 'b':
            makeBall();
            break;

        case 'x':
            makeBox();
            break;
            
		case 'c':
            clearBallsAndBoxes();
			break;
	}
}


//--------------------------------------------------------------
void testApp::keyReleased(int key){
    switch (key) {
            
        default:
            break;
    }

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){    
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    if(springs.size() == 0)
        makeSpring();
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    if (springs.size() != 0)
        clearSprings();
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
