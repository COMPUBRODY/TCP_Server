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

#pragma once

typedef enum{
	Server_instance,
	Client_instance
}Network_entity;

// Definition of error Codes
enum ERR_CODES {
    OK,
    STABLE,
    WARNING,
    NO_LISTENING,
    NO_CLIENTS,
    NO_ACCEPTED,
    FAIL_01,
    FAIL_02,
    TRYING,
    ISSUE_05,
    ISSUE_06,
    EXIT
};

typedef ERR_CODES response_codes;


class Network
{
	public:
        Network(Network_entity net,std::string ip_str);
        virtual ~Network() {};

        // Member Variables
        Network_entity role;
        response_codes code;
        std::string IP;
        int recvbuflen = DEFAULT_BUFLEN;
        char recvbuf[DEFAULT_BUFLEN];
        std::string sendbuf;
        int iResult;
        


        //Custom Functions
        virtual response_codes __init() = 0;
        virtual response_codes __start() = 0;
        virtual response_codes _client(int clientSocket) = 0;
        virtual response_codes _Server(int serverSocket) = 0;
        virtual response_codes Establish_Communication() = 0;
        virtual response_codes connectToServer(std::string serverAddress) = 0;
        virtual response_codes Send(const std::string& data)  = 0;
        virtual inline void Recieve() = 0;
};

#endif