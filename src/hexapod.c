#include "hexapod.h"
#include <stdio.h>
#include <stdlib.h>

/* initializes hexapod */
hexapod_t *start(void) {
    //must init mvmntTableArray
    hexapod_t *hexapod = malloc(sizeof(hexapod_t));
    if (hexapod == NULL)
        exit(ERROR);
    hexapod->legs[0].id = 0;
    for (int i = 0; i < LEGS_NBR; i++) {
        hexapod->legs[i].motorValue[0] = 0;
        hexapod->legs[i].motorValue[1] = 0;
        hexapod->legs[i].motorValue[2] = 0;
    }
    hexapod->currentMovement = STOP;
    return hexapod;
}

void printMotorsValue(hexapod_t *hexapod)
{
    if (hexapod == NULL)
        return;
    for (int i = 0; i < LEGS_NBR; i++) {
        printf("Leg[%d] motor A: %d\n", i, hexapod->legs[i].motorValue[0]);
        printf("Leg[%d] motor A: %d\n", i, hexapod->legs[i].motorValue[1]);
        printf("Leg[%d] motor A: %d\n", i, hexapod->legs[i].motorValue[2]);
    }
}

/* updates hexapod */
int update(hexapod_t *hexapod) {
    printMotorsValue(hexapod);
    if (hexapod == NULL)
        return ERROR;
    hexapod->currentMovement = mvmntUpdate(hexapod->currentMovement);
    printf("mvmnt is : %s\n", MVMNT_STRING[hexapod->currentMovement]);
    return 0;
}
