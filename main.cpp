#include <iostream>
#include <server.h>

int main(){

    Server echoServer;

    if(echoServer.__init())
    {
        echoServer.__start();
    }

    return EXIT_SUCCESS;
}
