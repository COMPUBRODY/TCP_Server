#include "../include/network.h"


Network::Network(Network_entity net,std::string ip_str)
{
    
    // Initialize Socket
    this->role = net;
	
	if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        return;
    }
    //ZeroMemory(&hints, sizeof(hints));
    //hints.ai_family   = AF_INET;
    //hints.ai_socktype = SOCK_STREAM;
    //hints.ai_protocol = IPPROTO_TCP;

    if(this->role == Server_instance)
    {
        //hints.ai_flags = AI_PASSIVE;
        // Resolve the server address and port
        //iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
    }
    else
    {
        //iResult = getaddrinfo(ip_str.c_str(), DEFAULT_PORT, &hints, &result);
    }

    if ( iResult != 0 ) {
        printf("getaddrinfo failed with error: %d\n", iResult);
        return;
    }

    printf("Network init\n");
}