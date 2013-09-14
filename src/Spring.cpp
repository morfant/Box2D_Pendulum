//
//  Spring.cpp
//  emptyExample
//
//  Created by Gangil Yi on 9/12/13.
//
//

// ----Headers----
#include "Spring.h"


// ----Birth & Death----

Spring::Spring(b2World* aWorld, b2Body* ground, b2Body* body, b2Vec2* target)
{
    mWorld = aWorld;
    
    b2MouseJointDef jointDef;
    jointDef.bodyA = ground;
    jointDef.bodyB = body;
    jointDef.target = *target;
    
    jointDef.collideConnected = true;
    jointDef.maxForce = 1000 * body->GetMass();
    jointDef.dampingRatio = 0;
    
    mMouseJoint = (b2MouseJoint*)mWorld->CreateJoint(&jointDef);
    
    body->SetAwake(true);

}

Spring::~Spring()
{
    mWorld->DestroyJoint(mMouseJoint);
    mMouseJoint = NULL;
}



b2World*
Spring::getWorld()
{
    return mWorld;
}


b2MouseJoint*
Spring::getMouseJoint()
{
    return mMouseJoint;
}

void
Spring::renderAtBodyPosition()
{
    // We can get the two anchor points
    b2Vec2 v1 = mMouseJoint->GetAnchorA();
    b2Vec2 v2 = mMouseJoint->GetAnchorB();
    // And just draw a line
    ofSetColor(255, 0, 100);
    ofSetLineWidth(1);
    ofLine(_toPixelX(v1.x), _toPixelY(v1.y),_toPixelX(v2.x), _toPixelY(v2.y));
}


// Update & draw
void
Spring::update(float x, float y)
{
    b2Vec2 newTarget = b2Vec2(_toWorldX(x), _toWorldY(y));
    mMouseJoint->SetTarget(newTarget);
}