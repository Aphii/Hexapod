#include "hexapod.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    hexapod_t *hexapod;
    printf("Starting program\n");
    hexapod = start();
    int status = 0;
    for (;;) {
        status = update(hexapod);
        if (status == ERROR)
            return ERROR;
        else if (status == 1)
            break;
    }
    free(hexapod);
    printf("Ending program\n");
    return (0);
}