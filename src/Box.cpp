//
//  Box.cpp
//  emptyExample
//
//  Created by Gangil Yi on 8/13/13.
//
//

// ----Headers----
#include "Box.h"


// ----Birth & Death----

Box::Box(b2World* aWorld, float x, float y, bool isStatic)
{
    
    mWorld = aWorld;
    posX = x;
    posY = y;
    
	b2BodyDef myBodyDef;

    if(isStatic)
        myBodyDef.type = b2_staticBody;
    else
        myBodyDef.type = b2_dynamicBody;
    
    myBodyDef.position.Set(_toWorldX(posX), _toWorldY(posY));
	mBody = mWorld -> CreateBody(&myBodyDef);
    
	b2PolygonShape myPolygonShape;
	myPolygonShape.SetAsBox(_toWorldScale(width)/2.f, _toWorldScale(height)/2.f);
	
	b2FixtureDef myFixtureDef;
	myFixtureDef.shape = &myPolygonShape;
	myFixtureDef.density = 1.f;
    myFixtureDef.restitution = 0.5f;
    mBody->CreateFixture(&myFixtureDef);
}

Box::Box(b2World* aWorld, float x, float y, float w, float h, bool isStatic)
{
    
    mWorld = aWorld;
    posX = x;
    posY = y;
    width = w;
    height = h;
    
	b2BodyDef myBodyDef;
    
    if(isStatic)
        myBodyDef.type = b2_staticBody;
    else
        myBodyDef.type = b2_dynamicBody;
    
    myBodyDef.position.Set(_toWorldX(posX), _toWorldY(posY));
	mBody = mWorld -> CreateBody(&myBodyDef);
    
    //    cout << "addr of aWorld in Box: " << aWorld << endl;
    
    
	b2PolygonShape myPolygonShape;
	myPolygonShape.SetAsBox(_toWorldScale(width)/2.f, _toWorldScale(height)/2.f);
	
	b2FixtureDef myFixtureDef;
	myFixtureDef.shape = &myPolygonShape;
	myFixtureDef.density = 1.f;
    myFixtureDef.restitution = 0.5f;
    mBody->CreateFixture(&myFixtureDef);
}

Box::~Box()
{


}


// getter & setter
float
Box::getX()
{
    return posX;
}

float
Box::getY()
{
    return posY;
}

float
Box::getWidth()
{
    return width;
}

float
Box::getHeight()
{
    return height;
}

b2World*
Box::getWorld()
{
    return mWorld;
}

b2Body*
Box::getBody()
{
    return mBody;

}

void
Box::setX(float _posX)
{
    
}

void
Box::setY(float _posY)
{

}


void
Box::renderAtBodyPosition()
{
    b2Vec2 pos = mBody->GetPosition();
    float angle = mBody->GetAngle();
    
    ofSetColor(0, 0, 255);
    ofPushMatrix();
    ofSetRectMode(OF_RECTMODE_CENTER);    
    ofTranslate(_toPixelX(pos.x), _toPixelY(pos.y));
    ofRotateZ(RAD_TO_DEG * angle);
    ofRect(0, 0, width, height);
    ofPopMatrix();
}


// Update & draw
void
Box::update()
{
    
}


void
Box::draw()
{
   


}