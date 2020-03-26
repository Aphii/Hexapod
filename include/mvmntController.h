#include "hexapod.h"
#ifndef _MVMNTCONTROLLER_H__
#define _MVMNTCONTROLLER_H__

struct MvmntTable_t {
    MOVEMENT currentMovement;
    int angleValue[3];
};

typedef struct MvmntTable_t mvmntTable;

/* prototypes of functions */
void mvmntController(hexapod_t *hexapod);
#endif