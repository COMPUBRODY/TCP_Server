#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <arpa/inet.h>

constexpr int PORT = 8080;
constexpr int BUFFER_SIZE = 1024;

class Client {
public:
    Client() : clientSocket(-1) {}

    ~Client() {
        if (clientSocket != -1) {
            close(clientSocket);
        }
    }

    bool connectToServer(const char* serverAddress) {
        // Create a socket
        clientSocket = socket(AF_INET, SOCK_STREAM, 0);
        if (clientSocket == -1) {
            std::cerr << "Error creating socket." << std::endl;
            return false;
        }

        // Set up server address and port
        sockaddr_in serverAddr{};
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = htons(PORT);
        if (inet_pton(AF_INET, serverAddress, &(serverAddr.sin_addr)) <= 0) {
            std::cerr << "Invalid server address." << std::endl;
            close(clientSocket);
            return false;
        }

        // Connect to the server
        if (connect(clientSocket, reinterpret_cast<struct sockaddr*>(&serverAddr), sizeof(serverAddr)) == -1) {
            std::cerr << "Error connecting to server." << std::endl;
            close(clientSocket);
            return false;
        }

        return true;
    }

    void sendData(const char* data) {
        send(clientSocket, data, strlen(data), 0);
        std::cout << "Sent data: " << data << std::endl;

        // Receive the echoed data from the server
        char buffer[BUFFER_SIZE];
        ssize_t bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);

        if (bytesRead > 0) {
            buffer[bytesRead] = '\0'; // Null-terminate the received data
            std::cout << "Received data from server: " << buffer << std::endl;
        } else {
            std::cerr << "Error receiving data from server." << std::endl;
        }
    }

private:
    int clientSocket;
};

int main() {
    // Set the server address (change this to the actual server address)
    const char* serverAddress = "127.0.0.1";

    Client echoClient;

    if (echoClient.connectToServer(serverAddress)) {
        // Send data to the server (replace "Hello, Server!" with your data)
        echoClient.sendData("Hello, Server!");
    }

    return EXIT_SUCCESS;
}
