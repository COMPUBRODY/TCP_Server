#ifndef client_H
#define client_H

#include "network.h"

class Client :public Network
{
    public:
        int clientSocket;
        Client(std::string address);
        ~Client();
        response_codes __init() override;
        response_codes __start() override;
        response_codes _client(int clientSocket) override;
        response_codes _Server(int serverSocket) override;
        response_codes Establish_Communication() override;
        response_codes connectToServer(std::string serverAddress) override;
        response_codes Send(const std::string& data) override;
        inline void Recieve();
};


#endif