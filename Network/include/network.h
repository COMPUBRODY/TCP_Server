#ifndef network_H
#define network_H

#include <stdlib.h>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <arpa/inet.h>

#define DEFAULT_BUFLEN 256
#define DEFAULT_PORT   "3333"


typedef enum
{
	Server_instance,
	Client_instance
}Network_entity;

// Definition of error Codes
enum ERR_CODES {
    STABLE,
    WARNING,
    NO_LISTENING,
    NO_CLIENTS,
    NO_ACCEPTED,
    FAIL_01,
    FAIL_02,
    TRYING,
    ISSUE_05,
    EXIT
};

typedef ERR_CODES response_codes;


class Network
{
	public:
	
	Network_entity role;
	std::string IP;

	// struct addrinfo *result = NULL;
	// struct addrinfo *ptr    = NULL;
	// struct addrinfo hints;

	int recvbuflen       = DEFAULT_BUFLEN;
	char recvbuf[DEFAULT_BUFLEN];
	std::string sendbuf;

    int iResult;
    
	Network(Network_entity net,std::string ip_str);
	virtual ~Network() {};

	//Custom Functions
    virtual response_codes __init() = 0;
    virtual response_codes __start() = 0;
    virtual response_codes _client(int clientSocket) = 0;
    virtual response_codes _Server(int serverSocket) = 0;
	virtual response_codes Establish_Communication() = 0;
	virtual response_codes Send(std::string msg)  = 0;
	virtual inline void Recieve() = 0;
};

#endif