#ifndef client_H
#define client_H

#include "network.h"

#define DEFAULT_BUFLEN 512

class Client :public Network
{
    public:
        int clientSocket;
        Client(std::string address);
        ~Client();
        response_codes __init() override;
        response_codes __start() override;
        response_codes _Server(int serverSocket) override;
        response_codes Establish_Communication() override;
        response_codes connectToServer(const char* serverAddress) override;
        response_codes Send(const std::string& data) override;
        inline void Recieve();
};


#endif