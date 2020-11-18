#include <stdio.h>
#include <unistd.h> //sleep();
#include "socket_test.h"

int main(int argc, char *argv[])
{
    int a = 10, b = -2, c = 100;
    

    while(1)
    {
        printf("a+b=%d\n", APLUSB);
        sleep(3);
    }

    return 0;
}
