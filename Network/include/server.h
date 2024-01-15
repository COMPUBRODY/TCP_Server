#ifndef SERVER_H
#define SERVER_H


#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <arpa/inet.h>

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


class Server
{
    public:
        Server();
        ~Server();
        response_codes __init();
        response_codes __start();

    private:
        response_codes _client(int clientSocket);
};

#endif