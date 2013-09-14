//
//  MyAABBCallBack.cpp
//  emptyExample
//
//  Created by Gangil Yi on 9/13/13.
//
//

// ----Headers----
#include "MyAABBCallBack.h"

// getter & setter
//b2Fixture*
//MyAABBCallBack::getFixture()
//{
//    return mFixture;
//}

b2Body*
MyAABBCallBack::getBody()
{
    return mBody;
}

void
MyAABBCallBack::resetBody()
{
    mBody = NULL;
}
