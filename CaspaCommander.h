/*
 * CaspaCommander.h
 *
 *  Created on: Nov 1, 2012
 *      Author: rghunter
 */

#ifndef CASPACOMMANDER_H_
#define CASPACOMMANDER_H_

#include <termios.h>
#include <cstring>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/signal.h>
#include <sys/types.h>

class CaspaCommander {
public:
	CaspaCommander();
	CaspaCommander(char * port);
	virtual ~CaspaCommander();
	int getThrottle(void);
	int getTurn(void);
	int setThrottle(int speed);
	int setTurn(int angle);
	int writeString(char *message);

private:
	int caspaPort;
};

#endif /* CASPACOMMANDER_H_ */
