#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <arpa/inet.h>


constexpr int PORT = 8080;
constexpr int BUFFER_SIZE = 1024;

using namespace::std

// Definition of error Codes
typedef enum{
    ERR_0,
    ERR_1,
    ERR_2,
    ERR_3,
    ERR_4,
    EXIT
}ERR_CODES;



class Server:
{
    __init();
    __bind_addr();
    socket_client();
    __status();
    __echo();
    login_req();
    auth_mek();
    bind_server();
    close_();
}


// Create the socket
bool __init()
{
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(serverSocket == -1) 
    {
        std::cerr << "Error creating Socket." << std::endl;
        return EXIT;
    }
};

// Bind the socket to an address and port
bool __bind_addr()
{
    sockaddr_in serverAddress{};
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    
}
