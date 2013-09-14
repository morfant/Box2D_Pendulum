//
//  Ball.cpp
//  emptyExample
//
//  Created by Gangil Yi on 8/13/13.
//
//

// ----Headers----
#include "Ball.h"


// ----Birth & Death----

Ball::Ball(b2World* aWorld, float x, float y, bool isStatic)
{
    
    mWorld = aWorld;
    posX = x;
    posY = y;
    
    radius = 50.f;
    
	b2BodyDef myBodyDef;

    if(isStatic)
        myBodyDef.type = b2_staticBody;
    else
        myBodyDef.type = b2_dynamicBody;
    
    myBodyDef.position.Set(_toWorldX(posX), _toWorldY(posY));
	mBody = mWorld -> CreateBody(&myBodyDef);
    
    
	b2CircleShape myCircleShape;
	myCircleShape.m_p.Set(0, 0);
	myCircleShape.m_radius = _toWorldScale(radius/2.f);
	
	b2FixtureDef myFixtureDef;
	myFixtureDef.shape = &myCircleShape;	
	myFixtureDef.density = 1.f;
    myFixtureDef.restitution = 0.9f;
    myFixtureDef.friction = 0.7f;
    mBody->CreateFixture(&myFixtureDef);
}

Ball::Ball(b2World* aWorld, float x, float y, float r, bool isStatic)
{
    
    mWorld = aWorld;
    posX = x;
    posY = y;
    
    radius = r;
    
	b2BodyDef myBodyDef;
    
    if(isStatic)
        myBodyDef.type = b2_staticBody;
    else
        myBodyDef.type = b2_dynamicBody;
    
    myBodyDef.position.Set(_toWorldX(posX), _toWorldY(posY));
	mBody = mWorld -> CreateBody(&myBodyDef);
    
    
	b2CircleShape myCircleShape;
	myCircleShape.m_p.Set(0, 0);
	myCircleShape.m_radius = _toWorldScale(radius/2.f);
	
	b2FixtureDef myFixtureDef;
	myFixtureDef.shape = &myCircleShape;
	myFixtureDef.density = 1.f;
    myFixtureDef.restitution = 0.9f;
    myFixtureDef.friction = 0.7f;
    mBody->CreateFixture(&myFixtureDef);
}

Ball::~Ball()
{


}


// getter & setter
float
Ball::getX()
{
    return posX;
}

float
Ball::getY()
{
    return posY;
}

float
Ball::getRadius()
{
    return radius;
}

b2World*
Ball::getWorld()
{
    return mWorld;
}

b2Body*
Ball::getBody()
{
    return mBody;

}

void
Ball::setX(float _posX)
{
    
}

void
Ball::setY(float _posY)
{

}


void
Ball::renderAtBodyPosition()
{
    b2Vec2 pos = mBody->GetPosition();
    float angle = mBody->GetAngle();
    
    ofSetColor(255, 255, 0);
    ofPushMatrix();
    ofTranslate(_toPixelX(pos.x), _toPixelY(pos.y));
    ofRotateZ(RAD_TO_DEG * angle);
    ofEllipse(0, 0, radius, radius);
    ofPopMatrix();
}


// Update & draw
void
Ball::update()
{
    
}


void
Ball::draw()
{
   


}