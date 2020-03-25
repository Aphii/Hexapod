#include "hexapod.h"
#ifndef _MVMNTCONTROLLER_H__
#define _MVMNTCONTROLLER_H__

struct MvmntTable_t {
    MOVEMENT currentMovement;
    int motorsValue;
};

#define STOP_ARRAY {{0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}}

#define FORWARD_ARRAY {{10,10,10}, {10,10,10}, {10,10,10}, {10,10,10}, {10,10,10}, {10,10,10}}

typedef struct MvmntTable_t mvmntTable;

/* prototypes of functions */
void mvmntController(hexapod_t *hexapod);
#endif