#include <stdio.h>

#include "hexapod.h"
#include "mvmntUpdate.h"

/* mvmntUpdate
 * @params MOVEMENT currentMovement
 * @return MOVEMENT
 */

MOVEMENT mvmntUpdate(MOVEMENT currentMovement) {
//update robot movement depending on user inputs
    char *requestedMvmnt = NULL;
    scanf("%s", &requestedMvmnt); //le read estt bloquant ;(
    return getMvmnt(requestedMvmnt, currentMovement));
}

MOVEMENT getMvmnt(char *requestedMvmnt, currentMovement) {
//get a MOVEMENT from a string
    if (isValidMvmnt(requestedMvmnt)) {
        MOVEMENT mvmnt = FORWARD;
        return (mvmnt);
    }
    fprintf( stderr, "%s is not a valid movement command.\n Please retry with one of the following :\
\n\t-STOP\n\t-FORWARD\n\t-BACKWARD\n\t-TURNING_RIGHT\n\t-TURNING_LEFT\n\nCurrent movement is %s\n", requestedMvmnt, currentMovement); //might need to print currentMovmnt as str
    return (currentMovement);
}

bool isValidMvmnt(char * mvmnt) {
    //check if entry if either stop forward ...
    return true;
}
