/* mvmntUpdate
 * @params MOVEMENT currentMovement
 * @return MOVEMENT
 */

#include <stdio.h>
#include <poll.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include "mvmntUpdate.h"

bool isValidMvmnt(char * mvmnt) {
    //check if entry if either stop forward ...
    return true;
}

MOVEMENT getFromIndex(int id)
{
    switch (id) {
        case 0:
            return STOP;
        case 1:
            return FORWARD;
        case 2:
            return BACKWARD;
        case 3:
            return TURNING_RIGHT;
        case 4:
            return TURNING_LEFT;
        break;
    }
    return STOP;
}

MOVEMENT stringToEnumMovement(char *str)
{
 /*   for (int i = 0; i < MVMNT_NBR; i++) {
        char *mvmnt = MVMNT_STRING[getFromIndex(i)];
        if (strcmp(str, mvmnt) == 0)
            return getFromIndex(i);
    }
    */return STOP;
}

MOVEMENT getMvmnt(char *requestedMvmnt, MOVEMENT currentMovement) {
//get a MOVEMENT from a string
    if (isValidMvmnt(requestedMvmnt)) {
        MOVEMENT mvmnt = stringToEnumMovement(requestedMvmnt);
        return (mvmnt);
    }
    fprintf( stderr, "%s is not a valid movement command.\n Please retry with one of the following :\
\n\t-STOP\n\t-FORWARD\n\t-BACKWARD\n\t-TURNING_RIGHT\n\t-TURNING_LEFT\n\n", requestedMvmnt);
    return (currentMovement);
}

MOVEMENT mvmntUpdate(MOVEMENT currentMovement) {
//update robot movement depending on user inputs
    char *requestedMvmnt = NULL;
    int ret_poll;
    ssize_t ret_read;
    struct pollfd input[1] = {{fd: 0, events: POLLIN}};
    char buff[100];
    ret_poll = poll(input, 1, 2);
    printf("ret_poll:\t%d\nerrno:\t%d\nstrerror:\t%s\n", ret_poll, errno, strerror(errno));
    ret_read = read(0, buff, 99);
    printf("ret_read:\t%zd\nerrno:\t%d\nstrerror:\t%s\nbuff:\t%s\n", ret_read, errno, strerror(errno), buff);
    return getMvmnt(requestedMvmnt, currentMovement);
}
