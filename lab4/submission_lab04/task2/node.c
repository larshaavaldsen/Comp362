/*
By Lars Haavaldsen
Comp 362 lab
*/

#include "message.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	mqd_t my_msqid, server_msqid;
	MESSG msg_rcvd, msg_send;
	unsigned int type;
	char mqName[10]; 

	if (argc < 3){
		printf("Usage: ./node <name> <value>\n");
		exit(1);
	}

	if ((server_msqid = mq_open(SERVER_NAME, O_WRONLY)) < 0)
		oops("Node: Error opening a queue.", errno);


	sprintf(mqName, "/NODE_%s", argv[1]);

	msg_send.nodeId = atoi(argv[1]);

	float previousTemperature = atof(argv[2]);

	// just in case the old queue is still there (e.g., after ^C)
	if (mq_unlink(mqName) == 0)
		printf("Node: Message queue %s removed from system.\n", mqName);

	// initialize the queue attributes
	struct mq_attr attr;

	attr.mq_maxmsg = 10;
	attr.mq_msgsize = MAX_MSG_SIZE;
	attr.mq_curmsgs = 0;
	attr.mq_flags = 0;

	if ((my_msqid = mq_open((char *) mqName, O_RDWR | O_CREAT, S_IWUSR | S_IRUSR, &attr)) < 0)
		oops("Node: Error opening a client queue.", errno);
	

	if (mq_send(server_msqid, (char *) &msg_send, sizeof(MESSG), (unsigned int) TYPE) < 0)
		oops("Node: Error sending a message.", errno);

	while (true) {
		if (mq_receive(my_msqid, (char *) &msg_rcvd, MAX_MSG_SIZE, &type) >= 0) {
			if (msg_rcvd.stable) {
				break;
			}
			previousTemperature = (previousTemperature * 3 + 2 * msg_rcvd.temperature) / 5;
			printf("NODE %d TEMPERATURE: %.3f\n", msg_send.nodeId, previousTemperature);
			msg_send.temperature = previousTemperature;

			if (mq_send(server_msqid, (char *) &msg_send, sizeof(MESSG), (unsigned int) TYPE) < 0)
				oops("Node: Error sending a message.", errno);
		}
		else {
			oops("Node: Error receiving data.", errno);
		}
	}

	printf("NODE %d TERMINATING...\n", msg_send.nodeId);
	mq_unlink(mqName);

	exit(EXIT_SUCCESS);
}