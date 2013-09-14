//
//  Pendulum.h
//  emptyExample
//
//  Created by Gangil Yi on 9/12/13.
//
//

// ----Preprocessor command----
#pragma once


// ----Headers----
#include <iostream>
#include "ofMain.h"
#include "Box2D.h"
#include "convertFunc.h"
#include "Box.h"
#include "Ball.h"


// ----Class definition----
class Pendulum{
protected:
    
    // Position
    float   posX;
    float   posY;
    
	// Box2D circle and box
    b2World*    mWorld;
	Box*		mBox; //swinging bar
    Ball*       mCircle; //center of swinging
    b2RevoluteJoint*        mRevJoint;
    
    
    
public:
    // Birth and Death
    Pendulum(b2World* world, float x, float y);
    ~Pendulum();
    
    // Getter
    float   getX();
    float   getY();
    b2RevoluteJoint*    getRevJoint();
    
    
    b2World*    getWorld();
    b2Body*     getBox();
    b2Body*     getCircle();
    
    // Setter
    void    setX(float posX);
    void    setY(float posY);
        
    // Render
    void    renderAtBodyPosition();
    
    // Update & draw
    void    update();
    void    draw();
    
    
    
    
    
};