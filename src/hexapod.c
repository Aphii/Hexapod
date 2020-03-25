#include "hexapod.h"
#include <stdlib.h>

/* initializes hexapod */
hexapod_t *start(void) {
    //must init mvmntTableArray
    hexapod_t *hexapod = malloc(sizeof(hexapod_t));
    if (hexapod == NULL)
        exit(ERROR);
  /*  hexapod->legs[5] = {{0, STOP, {0,0,0}},
                        {1, STOP, {0,0,0}},
                        {2, STOP, {0,0,0}},
                        {3, STOP, {0,0,0}},
                        {4, STOP, {0,0,0}},
                        {5, STOP, {0,0,0}}}; // init array to stop movement */
    hexapod->legs[0].id = 0;
    hexapod->legs[0].motorValue[0] = 0;
    hexapod->legs[0].motorValue[1] = 0;
    hexapod->legs[0].motorValue[2] = 0;
    hexapod->currentMovement = STOP;
    return hexapod;
}

/* updates hexapod */
int update(hexapod_t *hexapod) {
  //  hexapod->currentMovement = mvmntUpdate(hexapod->currentMovement);
    return 0;
}
