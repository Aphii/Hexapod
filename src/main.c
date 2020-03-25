#include "hexapod.h"
#include <stdio.h>

int main()
{
    hexapod_t *hexapod;
    printf("Starting test program\n");
    hexapod = start();
    int status = 0;
    for (;;) {
        status = update(hexapod);
        if (status == ERROR)
            return ERROR;
        else if (status == OVER)
            break;
    }
    printf("Ending test program");
    return (0);
}