//
//  convertFunc.h
//  cvBody_001
//
//  Created by giy on 9/1/13.
//
//

// ----Preprocessor command----
#pragma once

// ----Headers----
#include "ofMain.h"

// ----Define----
#define BOX2D_SCALE		80. // 1 meter of box2D world is 80 pixel on the screen. MUST FLOAT type!

// ----Inline Funcs----
inline float _round2(float f)
{
    return std::floor(f * 100.f) / 100.f;
}

inline float _toDegree(float a)
{
    return -a / TWO_PI * 360.f;
}

inline float _toRadian(float a)
{
    return -a / 360.f * TWO_PI;
}

inline float _toPixelX(float x)
{
    return (ofGetWidth() / 2.f) + (BOX2D_SCALE * x);
}

inline float _toPixelY(float y)
{
    return (ofGetHeight() / 2.f) - (BOX2D_SCALE * y);
}

inline float _toWorldX(float x)
{
    return _round2( -1.f * ((ofGetWidth() / 2.f) - x) / BOX2D_SCALE);
}

inline float _toWorldY(float y)
{
    return _round2( ((ofGetHeight() / 2.f) - y) / BOX2D_SCALE);
}

inline float _toWorldScale(float v)
{
    return _round2(v / BOX2D_SCALE);
}