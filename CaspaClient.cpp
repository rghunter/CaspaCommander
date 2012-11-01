//============================================================================
// Name        : CaspaClient.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include "CaspaCommander.h"

using namespace std;

int main(void) {
	CaspaCommander command("/dev/ttyACM0");
	command.writeString("\r");
	command.writeString("promptOff\r");
	while(1)
	{
		command.setTurn(100);
		command.setThrottle(100);
		sleep(1);
		command.setTurn(-100);
		command.setThrottle(-100);
		sleep(1);
	}

	return EXIT_SUCCESS;
}
