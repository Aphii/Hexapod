#include <stdio.h>
#include <stdlib.h>
#include "hexapod.h"
#include "mvmntController.h"

/* initializes hexapod */
hexapod_t *start(void) {
    hexapod_t *hexapod = malloc(sizeof(hexapod_t));
    if (hexapod == NULL)
        exit(ERROR);
    for (int i = 0; i < LEGS_NBR; i++) {
        hexapod->legs[i].motorValue[0] = 0;
        hexapod->legs[i].motorValue[1] = 0;
        hexapod->legs[i].motorValue[2] = 0;
    }
    hexapod->angleArray = initAngleArray();
    hexapod->currentMovement = STOP;
    return hexapod;
}

void printMotorsValue(hexapod_t *hexapod)
{
    if (hexapod == NULL)
        return;
    for (int i = 0; i < LEGS_NBR; i++) {
        printf("Leg[%d] motor A: %d\n", i, hexapod->legs[i].motorValue[0]);
        printf("Leg[%d] motor B: %d\n", i, hexapod->legs[i].motorValue[1]);
        printf("Leg[%d] motor C: %d\n", i, hexapod->legs[i].motorValue[2]);
    }
}

/* tmp updates hexapod */
int update(hexapod_t *hexapod) {
    printMotorsValue(hexapod);
    if (hexapod == NULL)
        return ERROR;
    hexapod->currentMovement = mvmntUpdate(hexapod->currentMovement);
    if (hexapod->currentMovement == OVER)
        return 1;
    mvmntController(hexapod);
    return 0;
}
