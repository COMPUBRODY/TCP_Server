#ifndef client_H
#define client_H

#include "network.h"

#define DEFAULT_BUFLEN 512



class Client :public Network
{
    public:
        SOCKET ConnectSocket = INVALID_SOCKET;
        Client();
        ~Client();
        response_codes __init();
        response_codes __start();
        response_codes _Server(int serverSocket) = 0;
        response_codes Establish_Communication();
        response_codes Send(std::string msg);
	    inline void Recieve();
        
};


#endif