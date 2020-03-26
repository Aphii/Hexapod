#ifndef _MVMNTUPDATE_H__
#define _MVMNTUPDATE_H__

#include <stdbool.h>
#define MVMNT_NBR 5

/* MOVEMENT */
#define FOREACH_MVMNT(MVMNT) \
        MVMNT(STOP)   \
        MVMNT(FORWARD)  \
        MVMNT(BACKWARD)   \
        MVMNT(TURNING_RIGHT)  \
        MVMNT(TURNING_LEFT)  \

#define GENERATE_ENUM(ENUM) ENUM,
#define GENERATE_STRING(STRING) #STRING,

enum MVMNT_ENUM {
    FOREACH_MVMNT(GENERATE_ENUM)
};

static const char *MVMNT_STRING[] = {
    FOREACH_MVMNT(GENERATE_STRING)
};

typedef enum MVMNT_ENUM MOVEMENT;

/* prototypes of functions*/
MOVEMENT mvmntUpdate(MOVEMENT currentMovement);

#endif