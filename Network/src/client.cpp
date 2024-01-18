#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include "../include/client.h"
#include "../include/network.h"


constexpr int PORT = 8080;
constexpr int BUFFER_SIZE = 1024;

using namespace::std;

// COnstructor Client
Client::Client(std::string address):Network(Client_instance,address)
{
    // Resolve the server address and port
    IP = address;
	std::cout<<"Building Client ."<<std::endl;
    //this->mode     = Hold;
    //this->cuadrant = Right_Cuadrant;
}

response_codes Client :: __init(){

    printf("Client Initialized..\n");
    if(! connectToServer(IP) == STABLE){
        printf("error connectToServer");
    }
    while(__start()){
        printf("Client Working Fine");
    }
    printf("Client Closed");

    return STABLE;
};

response_codes Client :: __start(){

    printf("Client Started...\n");
    response_codes result = _client(01);
            // Check the result
        if (result == OK) {
            std::cout << "Communication OK" << std::endl;
        } else{
            std::cout << "Something is wrong in CLient" << std::endl;
            return WARNING;
        }
    return STABLE;
};

response_codes Client :: _client(int clientSocket){

    std::string dataToSend = "Hello, Server!";
    printf("Sending Message.\n");

    // Call the Send function to send the data
    response_codes result = Send(dataToSend);

    // Check the result
    if (result == OK) {
        std::cout << "Data sent successfully." << std::endl;
    } else{
        std::cout << "It Seems that something wrong with server." << std::endl;
        return ISSUE_06;
    } 
    return OK;
};

response_codes Client :: _Server(int serverSocket){

    return STABLE;
};

response_codes Client :: connectToServer(std::string serverAddress) {
        // Create a socket
        const char* addr_IP = serverAddress.c_str();
        clientSocket = socket(AF_INET, SOCK_STREAM, 0);
        if (clientSocket == -1) {
            std::cerr << "Error creating socket." << std::endl;
            return FAIL_01;
        }

        // Set up server address and port
        sockaddr_in serverAddr{};
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = htons(PORT);
        if (inet_pton(AF_INET, addr_IP, &(serverAddr.sin_addr)) <= 0) {
            std::cerr << "Invalid server address." << std::endl;
            close(clientSocket);
            return FAIL_02;
        }

        // Connect to the server
        if (connect(clientSocket, reinterpret_cast<struct sockaddr*>(&serverAddr), sizeof(serverAddr)) == -1) {
            std::cerr << "Error connecting to server." << std::endl;
            close(clientSocket);
            return NO_LISTENING;
        }

        std::cout << "Client listening on port " << PORT << std::endl;

        // Rest of your client code goes here...

        // Close the server socket when done
        //close(clientSocket);


        return STABLE;
    }

response_codes Client ::Send(const std::string& data) {
    
    send(clientSocket, data.c_str(), data.length(), 0);
    std::cout << "Sent data: " << data << std::endl;

    // Receive the echoed data from the server
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);

    if (bytesRead > 0) {
        buffer[bytesRead] = '\0'; // Null-terminate the received data
        std::cout << "Received data from server: " << buffer << std::endl;
    } else {
        std::cerr << "Error receiving data from server." << std::endl;
        return FAIL_01; 
    }
    return OK;
}


inline void Client :: Recieve()
{
    // Receive until the peer closes the connection
    memset(recvbuf,0,recvbuflen);
    //iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
    //if(iResult == WSAEWOULDBLOCK || iResult == -1){return;}
    if ( iResult > 0 )
        printf("Bytes received: %d\n", iResult);
    else if ( iResult == 0 )
        printf("Connection closed\n");
    else
        //printf("recv failed with error: %d\n", WSAGetLastError());

    printf("msg recieved: %s\r\n",recvbuf);
}


response_codes Client ::Establish_Communication()
{
  
  return STABLE;
}


// Destructor
Client::~Client()  { 
    if (clientSocket != -1) {
        close(clientSocket);
    }
}