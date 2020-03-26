#include <stdio.h>
#include "mvmntController.h"

/* mvmntController
 * @params enum MOVEMENT - current movement
 * @return
 */
void mvmntController(hexapod_t *hexapod)
    //modify motor's angle value depending on currentMovement
{

  /*  for (int i = 0; i < LEGS_NBR;  i++) {
        rotateMotor(hexapod, i);
    } */
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
    printf("changing motors vlaues \n");
    /* tmp :/ comment faire pour que dynamiquement en fonction du current mvmnt ça prenne le bon tableau de valeur
    hexapod->legs[id].motorValue[0] = 10; //= mvmntArray[currentMovement].id ou mvmntArray(currentMovement).id
    hexapod->legs[id].motorValue[1] = 10; //= mvmntArray[currentMovement].id ou mvmntArray(currentMovement).id
    hexapod->legs[id].motorValue[2] = 10; //= mvmntArray[currentMovement].id ou mvmntArray(currentMovement).id */
}