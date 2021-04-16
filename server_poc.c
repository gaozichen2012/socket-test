#include <stdio.h>
#include <unistd.h> //sleep();
#include "server_poc.h"

int server_at_unpacket_process(char *pAtCmd)
{
    if (strncmp(pAtCmd, "AT+POC=0B", strlen("AT+POC=0B")) == 0)
    {
        server_send_cmd2_answer("+POC:0B000000");
        server_send_cmd2_other("+POC:8b0001");
        server_send_cmd2_other("+POC:83001b2d003374006f006d0033000000");
    }
    else if (strncmp(pAtCmd, "AT+POC=0C", strlen("AT+POC=0C")) == 0)
    {
        server_send_cmd2_answer("+POC:0C000000");
        server_send_cmd2_other("+POC:8b0000");
        server_send_cmd2_other("+POC:8301ffffffffdd8b43677a7af2950000");
    }
}
