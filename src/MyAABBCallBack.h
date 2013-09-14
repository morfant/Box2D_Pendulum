//
//  MyAABBCallBack.h
//  emptyExample
//
//  Created by Gangil Yi on 9/13/13.
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
class MyAABBCallBack : public b2QueryCallback, public ofBaseApp{
protected:
    b2Body*         mBody;

public:
    bool ReportFixture(b2Fixture* fixture) {
//        cout << "AABB Callback!" << endl;
        b2Body* body = fixture -> GetBody();

        /*
        b2Shape* shape = fixture -> GetShape();
        b2Vec2 tp = b2Vec2(_toWorldX(mouseX), _toWorldY(mouseY));
        b2Transform bt;
        bt.SetIdentity();
        bt = body -> GetTransform();
         */
        
        if (fixture->GetBody()->GetType() != b2_staticBody){
            
//            bool inside = shape -> TestPoint(bt, tp);
//            if (inside) {
//                cout << "inside" << endl;
//            }

            mBody = body;
            return false;
        }
        // Return true to continue the query.
        return true;
}
    
//    b2Fixture*  getFixture();
    b2Body*     getBody();
    void resetBody();
    
};
