#ifndef SERVER_H
#define SERVER_H

#include "network.h"

class Server : public Network
{
    public:
        int serverSocket;
        int clientSocket;
        Server();
        ~Server();
        response_codes __init() override;
        response_codes __start() override;
        response_codes _client(int clientSocket) override;
        response_codes _Server(int serverSocket) override;
        response_codes Establish_Communication() override;
        response_codes connectToServer(const char* serverAddress) override;
        response_codes Send(const std::string& data) override;
	    inline void Recieve();
        
};

#endif