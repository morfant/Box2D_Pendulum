//
//  Spring.h
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


// ----Class definition----
class Spring{
protected:
    
	// Box2D circle and box
    b2World*            mWorld;
    b2MouseJoint*       mMouseJoint;
    b2Body*             mBody;
    
    
    
public:
    // Birth and Death
    Spring(b2World* world, b2Body* ground, b2Body* body, b2Vec2* target);
    ~Spring();
    
    
    // Getter
    b2MouseJoint*    getMouseJoint();
    b2World*    getWorld();
    
    // Setter

    // Render
    void    renderAtBodyPosition();
    
    // Update & draw
    void    update(float x, float y);
    
    
    
    
    
};