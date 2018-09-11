// The MIT License (MIT)
//
// Copyright (c) 2015 THINGER LTD
// Author: alvarolb@gmail.com (Alvaro Luis Bustamante)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include "thinger/thinger.h"
#include "stdio.h"
#include "stdlib.h"

#define USER_ID             "Your_ID"  // place your credential, its important 
#define DEVICE_ID           "Your_Device"       // // place your credential, its important 
#define DEVICE_CREDENTIAL   "Your_credential"   // // place your credential, its important 
int num = 0;


// this function read data from a text file and transmit it to the iot-cloud
// you need to change the file path accoding to your system.

int getNum(){
	FILE *fptr;
	if ((fptr = fopen("/home/pi/Documents/walabot_project/program.txt","r")) == NULL)  //  you need to change it according to your system
	{
		printf("Error! opening file");
		// Program exits if the file pointer returns NULL.
		exit(1);
	}
	fscanf(fptr,"%d", &num);
	// printf("Value of n=%d", num);
	fclose(fptr);

	return num;
}

int main(int argc, char *argv[])
{
	
// check the thinger.io documentation for details about this source.
	
	thinger_device thing(USER_ID, DEVICE_ID, DEVICE_CREDENTIAL);
	thing["sensor"] >> [](pson& out){
	out = getNum();
	};
	
	thing.start();
	return 0;
}
