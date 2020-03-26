#include "angleArray.h"
#include <stdlib.h>

mvmntTable *initAngleArray()
{
    mvmntTable *mvmntArray = malloc(sizeof(mvmntTable) * 6);
    mvmntArray[0].currentMovement = STOP;
    mvmntArray[0].angleValue[0] = 0;
    mvmntArray[0].angleValue[1] = 0;
    mvmntArray[0].angleValue[2] = 0;
    mvmntArray[1].currentMovement = FORWARD;
    mvmntArray[1].angleValue[0] = 10;
    mvmntArray[1].angleValue[1] = 10;
    mvmntArray[1].angleValue[2] = 10;
    mvmntArray[2].currentMovement = BACKWARD;
    mvmntArray[2].angleValue[0] = 20;
    mvmntArray[2].angleValue[1] = 20;
    mvmntArray[2].angleValue[2] = 20;
    mvmntArray[3].currentMovement = TURNING_RIGHT;
    mvmntArray[3].angleValue[0] = 30;
    mvmntArray[3].angleValue[1] = 30;
    mvmntArray[3].angleValue[2] = 30;
    mvmntArray[4].currentMovement = TURNING_LEFT;
    mvmntArray[4].angleValue[0] = 40;
    mvmntArray[4].angleValue[1] = 40;
    mvmntArray[4].angleValue[2] = 40;
    mvmntArray[5].currentMovement = OVER;
    mvmntArray[5].angleValue[0] = 0;
    mvmntArray[5].angleValue[1] = 0;
    mvmntArray[5].angleValue[2] = 0;
    return mvmntArray;
}