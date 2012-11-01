/*
 * CaspaCommander.cpp
 *
 *  Created on: Nov 1, 2012
 *      Author: rghunter
 */

#include "CaspaCommander.h"

CaspaCommander::CaspaCommander() {
	caspaPort = open("/dev/ttyACM0", O_RDWR | O_NOCTTY | O_NONBLOCK);
	writeString("\r");
	writeString("promptOff\r");

}
CaspaCommander::CaspaCommander(char * port) {

	caspaPort = open(port, O_RDWR | O_NOCTTY | O_NONBLOCK);
	writeString("\r");
	writeString("promptOff\r");
}

CaspaCommander::~CaspaCommander() {
	close(caspaPort);

}
int CaspaCommander::getThrottle(void) {

	return 0;
}
int CaspaCommander::getTurn(void) {

	return 0;
}
int CaspaCommander::setThrottle(int speed) {
	char buffer[50];
	sprintf(buffer,"setThrottle %i\r",speed);
	return writeString(buffer);
}
int CaspaCommander::setTurn(int angle) {
	char buffer[50];
	sprintf(buffer,"setTurn %i\r",angle);
	return writeString(buffer);
}
int CaspaCommander::writeString(char *message) {
	while(write(caspaPort, message, strlen(message)+1) != (strlen(message)+1))
		usleep(200);
}

