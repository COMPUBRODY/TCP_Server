#include <iostream>
#include "Network/include/network.h"
#include "Network/include/server.h"
#include "Network/include/client.h"
//#include <security.h>
//#include <threads.h>


#define SERVER (0)


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
        Client* cl = new Client("127.0.0.1");
        Main_program(cl);
        delete cl;
	#endif
    

    return EXIT_SUCCESS;
}
