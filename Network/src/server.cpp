#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <arpa/inet.h>


constexpr int PORT = 8080;
constexpr int BUFFER_SIZE = 1024;

using namespace::std;

// Definition of error Codes
enum ERR_CODES {
    WARNING,
    NO_CONNECTION,
    FAIL,
    TRYING,
    ISSUE_05,
    EXIT
};



class Server:
{
    public:
    // Contructor

    int _init()
    {

    };

    int _bind_addr()
    {

    };

    int _listening()
    {

    };

    int socket_client()
    {

    };

    int _status()
    {

    };

    int _echo()
    {

    };

    int login_req()
    {

    };

    int auth_mek()
    {

    };

    int bind_server()
    {

    };

    int _close()
    {

    };

    private:

    
}


// Create the socket
int __init()
{
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(serverSocket == -1) 
    {
        std::cerr << "Error creating Socket." << std::endl;
        return EXIT;
    }
};

// Bind the socket to an address and port
int __bind_addr()
{
    sockaddr_in serverAddress{};
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(PORT);

    if (bind(serverSocket, reinterpret_cast<struct sockaddr*>(&serverAddress), sizeof(serverAddress)) == -1) {
    std::cerr << "Error binding socket." << std::endl;
    close(serverSocket);
    return EXIT_FAILURE;
    }
}

// Listen for incoming connections
int __listening()
{
    if (listen(serverSocket, 5) == -1) {
    std::cerr << "Error listening for connections." << std::endl;
    close(serverSocket);
    return EXIT_FAILURE;
    }

    std::cout << "Server listening on port " << PORT << std::endl;

    while (true) {
        // Accept a connection from a client
        int clientSocket = accept(serverSocket, nullptr, nullptr);   ----->>> Aqui va la authenticacion
        if (clientSocket == -1) {
            std::cerr << "Error accepting connection." << std::endl;
            close(serverSocket);
            return EXIT_FAILURE;
        }

        // Receive and send back data in chunks
        char buffer[BUFFER_SIZE];
        ssize_t bytesRead;

        while ((bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0)) > 0) {
            send(clientSocket, buffer, static_cast<size_t>(bytesRead), 0);
        }

        // Close the client socket
        close(clientSocket);
    }

    // Close the server socket (not reached in this example)
    close(serverSocket);

    return EXIT_SUCCESS;

}


