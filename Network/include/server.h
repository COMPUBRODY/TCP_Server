#ifndef SERVER_H
#define SERVER_H

#include "network.h"


class Server : public Network
{
    public:
        SOCKET ListenSocket = INVALID_SOCKET;
        SOCKET ClientSocket = INVALID_SOCKET;
        Server();
        ~Server();
        response_codes __init();
        response_codes __start();
        response_codes _client(int clientSocket);
        response_codes Establish_Communication();
        response_codes Send(std::string msg);
	    inline void Recieve();
        
};

#endif