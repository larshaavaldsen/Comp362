
#include "message.h"
#include <math.h>
#include <mqueue.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void debugMark(int i) {
	printf("\nDebug marker: %d\n", i);
}

int main(int argc, char *argv[])
{
	// usage ./monitor inital nodesToSpawn n1Temp n2Temp ... nxTemp
	if(atoi(argv[2]) + 3 != argc) {
		printf("usage: ./monitor inital nodesToSpawn n1Temp n2Temp ... nxTemp\n");
		exit(1);
	}
	
	float integratedTemp = atoi(argv[1]);

	int nodesToSpawn = atoi(argv[2]);

	TEMPERATURE nodeData[nodesToSpawn];

	mqd_t my_msqid, your_msqid;
	unsigned int type;

	// just in case it is still there (if we quit using ^C for example)
	if (mq_unlink(SERVER_NAME) == 0)
		printf("Old Message queue %s removed.\n", SERVER_NAME);

	// initialize the queue attributes
	struct mq_attr attr;

	attr.mq_maxmsg = 10;
	attr.mq_msgsize = MAX_MSG_SIZE;
	attr.mq_curmsgs = 0;
	attr.mq_flags = 0;

	if ((my_msqid = mq_open(SERVER_NAME, O_RDWR | O_CREAT, S_IWUSR | S_IRUSR, &attr)) < 0)
		oops("Monitor: Error opening a server queue.", errno);


	// Creating all children nodes
	for(int i = 0; i < nodesToSpawn; i++) {
		pid_t pid = fork();

		char name[10];
		sprintf(name, "%d", i);
		
		if (pid == 0) {
			execlp("./node", "", name, argv[3+i], NULL);
		}
	}
	int stabalizedNodes = 0;

	while (true) {
	
		MESSG msg_rcvd, msg_send;
		int sumOfClientTemps = 0;
		// get temps from all clients to calc sum
		for(int i = 0; i < nodesToSpawn; i++) {
			if (mq_receive(my_msqid, (char*) &msg_rcvd, MAX_MSG_SIZE, &type) == -1)
				oops("error reciveing messages", errno)

			nodeData[msg_rcvd.nodeId].msqid = msg_rcvd.nodeId;
			nodeData[msg_rcvd.nodeId].previousTemperature = msg_rcvd.temperature;
			sumOfClientTemps += msg_rcvd.temperature;
		}

		// calculating new monitor temp
		integratedTemp = (2 * integratedTemp + sumOfClientTemps) / 6;
		printf("MONITOR TEMP: %f\n", integratedTemp);

		// send out new monitor temp
		for (int i = 0; i < nodesToSpawn; i++) {
			// stability check
			char mqName[10];

			msg_send.nodeId = i;
			msg_send.temperature = integratedTemp;
			msg_send.stable = false;

			sprintf(mqName, "/NODE_%d", nodeData[i].msqid);

			if ((int) nodeData[i].previousTemperature == (int) integratedTemp) {
				stabalizedNodes++;
			}	else{
					if ((your_msqid = mq_open((char *) &mqName, O_WRONLY)) < 0)
						oops("Monitor: Error opening a client's queue", errno);
							
					if (mq_send(your_msqid, (char*) &msg_send, sizeof(MESSG), (unsigned int) TYPE) < 0)
						oops("Monitor: Cannot respond to a client.", errno);
					mq_close(your_msqid);

			}
		}

		if(stabalizedNodes == nodesToSpawn)
			break;


	}

	for (int i = 0; i < nodesToSpawn; i++) {
		MESSG msg_send;
		char mqName[10];
		msg_send.nodeId = i;
		msg_send.stable = true;

		sprintf(mqName, "/NODE_%d", nodeData[i].msqid);
		if ((your_msqid = mq_open((char *) &mqName, O_WRONLY)) < 0)
			oops("Monitor: Error opening a client's queue", errno);
							
		if (mq_send(your_msqid, (char*) &msg_send, sizeof(MESSG), (unsigned int) TYPE) < 0)
			oops("Monitor: Cannot respond to a client.", errno);


	}


	// while (true)
	// {
	// 	MESSG msg_rcvd, msg_send;
	// 	char mqName[10];
		
	// 	msg_send.temperature = 1;

	// 	if (mq_receive(my_msqid, (char*) &msg_rcvd, MAX_MSG_SIZE, &type) >= 0)
	// 	{
	// 		float sumOfClientTemps;

	// 		for (int i; i < nodesToSpawn; i++) {
	// 			sumOfClientTemps += nodeData[i].previousTemperature;
	// 		}

	// 		float newTemp;
	// 		printf("Monitor id /%d gives temp: %.2f\n", msg_rcvd.nodeId, msg_rcvd.temperature); // skip '/'
	// 		sprintf(mqName, "/NODE_%d", msg_rcvd.nodeId);

			

			// if ((your_msqid = mq_open((char *) &mqName, O_WRONLY)) < 0)
			// 	oops("Monitor: Error opening a client's queue", errno);
			
			// if (mq_send(your_msqid, (char*) &msg_send, sizeof(MESSG), (unsigned int) TYPE) < 0)
			// 	oops("Monitor: Cannot respond to a client.", errno);

	// 		// add old temp to temp array
	// 	}
	// 	else
	// 		oops("Monitor: Error receiving data.", errno);
	// }

	mq_unlink(SERVER_NAME);

	exit(EXIT_SUCCESS);
}
