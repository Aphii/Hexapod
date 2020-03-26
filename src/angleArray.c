#include "angleArray.h"
#include <stdlib.h>

mvmntTable *initAngleArray()
{
    mvmntTable *mvmntArray = malloc(sizeof(mvmntTable) * 6);
    mvmntArray[0].currentMovement = STOP;
    mvmntArray[0].angleValue[0] = 0;
    mvmntArray[0].angleValue[0] = 0;
    mvmntArray[0].angleValue[0] = 0;
    mvmntArray[1].currentMovement = FORWARD;
    mvmntArray[0].angleValue[0] = 10;
    mvmntArray[0].angleValue[0] = 10;
    mvmntArray[0].angleValue[0] = 10;
    mvmntArray[2].currentMovement = BACKWARD;
    mvmntArray[0].angleValue[0] = 20;
    mvmntArray[0].angleValue[0] = 20;
    mvmntArray[0].angleValue[0] = 20;
    mvmntArray[3].currentMovement = TURNING_RIGHT;
    mvmntArray[0].angleValue[0] = 30;
    mvmntArray[0].angleValue[0] = 30;
    mvmntArray[0].angleValue[0] = 30;
    mvmntArray[4].currentMovement = TURNING_LEFT;
    mvmntArray[0].angleValue[0] = 40;
    mvmntArray[0].angleValue[0] = 40;
    mvmntArray[0].angleValue[0] = 40;
    mvmntArray[5].currentMovement = OVER;
    mvmntArray[0].angleValue[0] = 0;
    mvmntArray[0].angleValue[0] = 0;
    mvmntArray[0].angleValue[0] = 0;
    return mvmntArray;
}