//#include "mvmntController.h"
#include "mvmntUpdate.h"


#ifndef _HEXAPOD_H_
#define _HEXAPOD_H_

#define ERROR 84
#define LEGS_NBR 6


/* LEGS */
struct Leg_t {
    int id;
    int motorValue[3];
};
typedef struct Leg_t  Leg;

/* HEXAPOD */

struct hexapod_t {
    Leg legs[6]; //declarer value 5 ou malloc ?
    MOVEMENT currentMovement;
};
typedef struct hexapod_t hexapod_t;

/* prototypes of functions*/
hexapod_t *start(void);
int update(hexapod_t *hexapod);

#endif