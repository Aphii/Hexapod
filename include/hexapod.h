//#include "mvmntController.h"
//#include "mvmntUpdate.h"


#ifndef _HEXAPOD_H_
#define _HEXAPOD_H_

#define ERROR 84
#define OVER 1
#define LEGS_NBR 6

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

/* LEGS */
struct Leg_t {
    int id;
    int motorValue[3];
};
typedef struct Leg_t  Leg;

/* HEXAPOD */

struct hexapod_t {
    Leg legs[5]; //declarer value 5 ou malloc ?
    MOVEMENT currentMovement;
};
typedef struct hexapod_t hexapod_t;

/* prototypes of functions*/
hexapod_t *start(void);
int update(hexapod_t *hexapod);

#endif