#include <iostream>
#include "network.h"
#include "server.h"
#include <client.h>
#include <security.h>
#include <threads.h>


#define SERVER (1)


void Main_program(Network* net)
{
    net->__init();
    //do something
}



int main(int argc, char **argv){

    #if SERVER

        Server* sr = new Server();
        Main_program(sr);
        //use delete word to delete the dynamic Memory
        delete sr;
	#else
        Network* cl = new Client("127.0.0.1");
        Main_program(cl);
        delete cl;
	#endif
    

    return EXIT_SUCCESS;
}
