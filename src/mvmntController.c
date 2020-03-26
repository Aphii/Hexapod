#include <stdio.h>
#include "mvmntController.h"

/* mvmntController
 * @params enum MOVEMENT - current movement
 * @return
 */
void mvmntController(hexapod_t *hexapod)
    //modify motor's angle value depending on currentMovement
{

    printf("changing motors values \n");
    for (int i = 0; i < LEGS_NBR; i++) {
        hexapod->legs[i].motorValue[0] = 10; //replace 10 by value from an array
        hexapod->legs[i].motorValue[1] = 10;
        hexapod->legs[i].motorValue[2] = 10;
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