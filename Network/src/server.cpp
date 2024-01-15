
#include <server.h>


constexpr int PORT = 8080;
constexpr int BUFFER_SIZE = 1024;

using namespace::std;




class Server
{
    public:
        // Contructor
        Server() : serverSocket(-1) {}

        ~Server(){
        if (serverSocket != -1) 
            {
            close(serverSocket);
            }
        } 

        // Create the socket
        response_codes __init(){
            serverSocket = socket(AF_INET, SOCK_STREAM, 0);
            if(serverSocket == -1){
                std::cerr << "Error creating Socket." << std::endl;
                return FAIL_01;
            }
        

            // Bind the socket to an address and port
            sockaddr_in serverAddress{};
            serverAddress.sin_family = AF_INET;
            serverAddress.sin_addr.s_addr = INADDR_ANY;
            serverAddress.sin_port = htons(PORT);

            if (bind(serverSocket, reinterpret_cast<struct sockaddr*>(&serverAddress), sizeof(serverAddress)) == -1){
                std::cerr << "Error binding socket." << std::endl;
                close(serverSocket);
                return FAIL_02;
            }
        
            // Listen for incoming connections

            if (listen(serverSocket, 5) == -1) {
                std::cerr << "Error listening for connections." << std::endl;
                close(serverSocket);
                return NO_LISTENING;
            }

            std::cout << "Server listening on port " << PORT << std::endl;

            return STABLE;
        };


        // Waiting for a client
        response_codes __start(){
            while (true) {
                // Accept a connection from a client
                int clientSocket = accept(serverSocket, nullptr, nullptr);  // ----->>> Aqui va la authenticacion
                if (clientSocket == -1) {
                    std::cerr << "Error accepting connection." << std::endl;
                    close(serverSocket);
                    return NO_ACCEPTED;
                }

                // Handle the client
                _client(clientSocket);

                // Close the client socket
                close(clientSocket);
            }

            return STABLE;

        };

    private:
        int serverSocket;

        response_codes _client(int clientSocket){
            char buffer[BUFFER_SIZE];
            ssize_t bytesRead;

            while ((bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0)) > 0) {
                // Process data (in this case, just echoing back)
                send(clientSocket, buffer, static_cast<size_t>(bytesRead), 0);
            }
            return STABLE;
        };

    
};






