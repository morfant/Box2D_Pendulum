//
//  serialModule.h
//  box2d_pendulum
//
//  Created by giy on 9/14/13.
//
//
// ----Preprocessor command----
#pragma once

// ----Headers----
#include <iostream>
#include "ofMain.h"

// Serial Communication

class SerialModule{
protected:
    ofSerial            serial;
    ofTrueTypeFont		font;
    
    bool		bSendSerialMessage;
    // a flag for sending serial
    char		bytesRead[3];
    // data from serial, we will be trying to read 3
    char		bytesReadString[4];
    // a string needs a null terminator, so we need 3 + 1 bytes
    int			nBytesRead;
    // how much did we read?
    int			nTimesRead;
    // how many times did we read?
    float		readTime;
    // when did we last read?
    
public:
    void setup();
    void updateW(int writeValue);
    void updateR();
    void report(string key, float value);


};

