#include <stdio.h>
#include "mvmntController.h"

int getIDfromMvmnt(hexapod_t *hexapod)
{
    int id = 0;
    for (int i = 0; i < MVMNT_NBR; i++) {
        if (hexapod->currentMovement == hexapod->angleArray[i].currentMovement) {
            id = i;
            break;
        }
    }
    return id;
}

/* mvmntController
 * @params enum MOVEMENT - current movement
 * @return
 */
void mvmntController(hexapod_t *hexapod)
    //modify motor's angle value depending on currentMovement
{
    int mvmntID = getIDfromMvmnt(hexapod);
    for (int i = 0; i < LEGS_NBR; i++) {
        hexapod->legs[i].motorValue[0] = hexapod->angleArray[mvmntID].angleValue[0];
        hexapod->legs[i].motorValue[1] = hexapod->angleArray[mvmntID].angleValue[1];
        hexapod->legs[i].motorValue[2] = hexapod->angleArray[mvmntID].angleValue[2];
    }
}

/* rotateMotor
 * @params Leg - leg structure from MvmntController.h containing 3 parts for each motor of the leg
 * @params int - nb designate id the the leg (between 0 and 5)
 * @params MOVEMENT - currentMovement
 * @return
 */
void rotateMotor(hexapod_t *hexapod, int id)
    //set new values to all motors(A, B & C) of leg n°nb
{
    if (hexapod == NULL)
        return;
}