#include <iostream>
#include <network.h>
#include <server.h>
#include <client.h>
#include <server.h>
#include <security.h>
#include <threads.h>


#define SERVER (1)


void Main_program(Network* net)
{
    net->Establish_Communication();
    //Snake_entry_point(net,net->cuadrant,net->mode);
    //hangman_game(net,net->mode,net->cuadrant);
}



int main(int argc, char **argv){

    #if SERVER

        Server echoServer;
        Server* sr = new Server();

        Main_program(sr);

        if(echoServer.__init())
        {
            echoServer.__start();
        }
	#else

        // Set the server address (change this to the actual server address)
        const char* serverAddress = "127.0.0.1";

        Client echoClient;

        if (echoClient.connectToServer(serverAddress)) {
            // Send data to the server (replace "Hello, Server!" with your data)
            echoClient.sendData("Hello, Server!");
        }
        Client* cl = new Client("127.0.0.1");
        Main_program(cl);
	#endif
    
    


    return EXIT_SUCCESS;
}
