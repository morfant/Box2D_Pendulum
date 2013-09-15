//
//  serial.cpp
//  box2d_pendulum
//
//  Created by giy on 9/14/13.
//
//

#include "serialModule.h"

void SerialModule::setup(){
    
	bSendSerialMessage = false;
    font.loadFont("DIN.otf", 64);
	
	serial.listDevices();
	vector <ofSerialDeviceInfo> deviceList = serial.getDeviceList();
	
	// this should be set to whatever com port your serial device is connected to.
	// (ie, COM4 on a pc, /dev/tty.... on linux, /dev/tty... on a mac)
	// arduino users check in arduino app....
	int baud = 9600;
	serial.setup(0, baud); //open the first device
	//serial.setup("COM4", baud); // windows example
	//serial.setup("/dev/tty.usbserial-A4001JEC", baud); // mac osx example
	//serial.setup("/dev/ttyUSB0", baud); //linux example
	
	nTimesRead = 0;
	nBytesRead = 0;
	readTime = 0;
	memset(bytesReadString, 0, 4);
    
}

void SerialModule::updateW(int writeValue){
    
    // (1) write the letter "a" to serial:
//    cout<<writeValue<<endl;
    serial.writeByte(writeValue);
    
    // Add checking return response.
    // ex)
    // if write succeed, return writeValue
    // else return NULL
    // ...
}

void SerialModule::updateR(){

    // (2) read
    // now we try to read 3 bytes
    // since we might not get them all the time 3 - but sometimes 0, 6, or something else,
    // we will try to read three bytes, as much as we can
    // otherwise, we may have a "lag" if we don't read fast enough
    // or just read three every time. now, we will be sure to
    // read as much as we can in groups of three...
    
    nTimesRead = 0;
    nBytesRead = 0;
    int nRead  = 0;  // a temp variable to keep count per read
    
    unsigned char bytesReturned[3];
    
    memset(bytesReadString, 0, 4);
    memset(bytesReturned, 0, 3);
    
    while( (nRead = serial.readBytes( bytesReturned, 3)) > 0){
        nTimesRead++;
        nBytesRead = nRead;
    };
    
    memcpy(bytesReadString, bytesReturned, 3);
    
    bSendSerialMessage = false;
    readTime = ofGetElapsedTimef();
}

void SerialModule::report(string key, float value){
    
	string msg;
	msg += key + ofToString(value) + "\n";
	font.drawString(msg, 50, 100);
}

