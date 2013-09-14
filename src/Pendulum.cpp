//
//  Pendulum.cpp
//  emptyExample
//
//  Created by Gangil Yi on 9/12/13.
//
//

// ----Headers----
#include "Pendulum.h"


// ----Birth & Death----

Pendulum::Pendulum(b2World* aWorld, float x, float y)
{
    
    mWorld = aWorld;
    posX = x;
    posY = y;
    mBox = new Box(mWorld, x, y, 20, 200, false);
    mCircle = new Ball(mWorld, x, y, 60, true);
    
    b2RevoluteJointDef jointDef;
    jointDef.bodyA = mCircle->getBody();
    jointDef.bodyB = mBox->getBody();
    jointDef.collideConnected = false;
    jointDef.localAnchorA.Set(0, 0);
    jointDef.localAnchorB.Set(0, _toWorldScale(100));
    jointDef.referenceAngle = 0;
    jointDef.lowerAngle = -0.25f * b2_pi; // -90 degrees
    jointDef.upperAngle = 0.25f * b2_pi; // 45 degrees
    jointDef.enableLimit = true;
//    jointDef.maxMotorTorque = 10.0f;
//    jointDef.motorSpeed = 10.0f;
//    jointDef.enableMotor = true;
    
    mRevJoint = (b2RevoluteJoint*)mWorld->CreateJoint(&jointDef);
	
}

Pendulum::~Pendulum()
{
    mWorld->DestroyBody(mRevJoint->GetBodyA());
    mWorld->DestroyBody(mRevJoint->GetBodyB());
//    mWorld->DestroyJoint(mRevJoint);
    mRevJoint = NULL;
}


// getter & setter
float
Pendulum::getX()
{
    return posX;
}

float
Pendulum::getY()
{
    return posY;
}


b2World*
Pendulum::getWorld()
{
    return mWorld;
}

b2Body*
Pendulum::getBox()
{
    return mBox->getBody();
}

b2Body*
Pendulum::getCircle()
{
    return mCircle->getBody();
}

b2RevoluteJoint*
Pendulum::getRevJoint()
{
    return mRevJoint;
}

void
Pendulum::setX(float _posX)
{
    
}

void
Pendulum::setY(float _posY)
{

}

void
Pendulum::renderAtBodyPosition()
{
    // circle    
    mCircle->renderAtBodyPosition();

    b2Vec2 pos = mBox->getBody()->GetPosition();
    b2Vec2 cPos = mCircle->getBody()->GetPosition();
    float jointAngle = mRevJoint->GetJointAngle();
    float lowerLimit = mRevJoint->GetLowerLimit();
    float upperLimit = mRevJoint->GetUpperLimit();
    
    ofSetColor(0, 0, 255);
    ofPushMatrix();
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofTranslate(_toPixelX(pos.x), _toPixelY(pos.y));
    ofRotateZ(-1 * RAD_TO_DEG * jointAngle);
    ofRect(0, 0, mBox->getWidth(), mBox->getHeight());
    ofPopMatrix();
    
    // angle limit line
    ofPushMatrix();
    ofSetRectMode(OF_RECTMODE_CORNER);
    ofTranslate(_toPixelX(cPos.x), _toPixelY(cPos.y));
    ofSetColor(100, 200, 0);
    ofRotateZ(-1 * RAD_TO_DEG * lowerLimit);
    ofRect(0, 0, 1, mBox->getHeight());
    ofRotateZ(RAD_TO_DEG * lowerLimit); // reset rotateZ
    ofRotateZ(-1 * RAD_TO_DEG * upperLimit);
    ofRect(0, 0, 1, mBox->getHeight());    
    ofPopMatrix();
    
}


// Update & draw
void
Pendulum::update()
{
    
}


void
Pendulum::draw()
{
   


}