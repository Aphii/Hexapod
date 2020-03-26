#ifndef _ANGLE_ARRAY_H__
#define _ANGLE_ARRAY_H__

#include "mvmntUpdate.h"

/* MOVEMENT VALUES */

struct MvmntTable_t {
    MOVEMENT currentMovement;
    int angleValue[3];
};

typedef struct MvmntTable_t mvmntTable;


/* protos */

mvmntTable *initAngleArray();

#endif