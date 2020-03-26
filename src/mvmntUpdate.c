/* mvmntUpdate
 * @params MOVEMENT currentMovement
 * @return MOVEMENT
 */

#include <stdio.h>
#include <poll.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <stdlib.h>
#include "mvmntUpdate.h"

void strToLowerCase(char *str)
{
    for(int i = 0; str[i]; i++){
        str[i] = tolower(str[i]);
    }
}

bool isValidMvmnt(char *mvmnt) {
    //check if input mvmnt is a valid command
    if (mvmnt == NULL)
        return false;
    strToLowerCase(mvmnt);
    if (strcmp(mvmnt, "stop") == 0 || strcmp(mvmnt, "over") == 0 || strcmp(mvmnt, "forward") == 0 || \
strcmp(mvmnt, "backward") == 0 || strcmp(mvmnt, "turning_right") == 0 || strcmp(mvmnt, "turning_left") == 0)
        return true;
    return false;
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
        case 5:
            return OVER;
        break;
    }
    return STOP;
}

MOVEMENT stringToEnumMovement(char *mvmnt)
{
   /* for (int i = 0; i < MVMNT_NBR; i++) {
        char *mvmnt = MVMNT_STRING[getFromIndex(i)];
        if (strcmp(str, mvmnt) == 0)
            return getFromIndex(i);
    } */
    if (strcmp(mvmnt, "stop") == 0 )
        return STOP;
    if (strcmp(mvmnt, "over") == 0 )
        return OVER;
    if (strcmp(mvmnt, "forward") == 0 )
        return FORWARD;
    if (strcmp(mvmnt, "backward") == 0 )
        return BACKWARD;
    if (strcmp(mvmnt, "turning_right") == 0 )
        return TURNING_RIGHT;
    if (strcmp(mvmnt, "turning_left") == 0 )
        return TURNING_LEFT;
    return STOP;
}

MOVEMENT getMvmnt(char *requestedMvmnt, MOVEMENT currentMovement) {
//get a MOVEMENT from a string
    if (isValidMvmnt(requestedMvmnt)) {
        MOVEMENT mvmnt = stringToEnumMovement(requestedMvmnt);
        return (mvmnt);
    }
    fprintf( stderr, "%s is not a valid movement command.\nHexapod current movement is %s.\n Please retry with one of the following :\
\n\t-STOP\n\t-FORWARD\n\t-BACKWARD\n\t-TURNING_RIGHT\n\t-TURNING_LEFT\n\t-OVER (to stop program)\n\n", requestedMvmnt, MVMNT_STRING[currentMovement]);
    return (currentMovement);
}

MOVEMENT mvmntUpdate(MOVEMENT currentMovement) {
//update robot movement depending on user inputs
    int ret_poll;
    ssize_t ret_read;
    struct pollfd input[1] = {{fd: 0, events: POLLIN}};
    char buff[100];
    ret_poll = poll(input, 1, 2);
    ret_read = read(0, buff, 99);
    char *requestedMvmnt = malloc(sizeof(char) * (ret_read - 1));
    if (requestedMvmnt == NULL)
        return STOP;
    for (int i = 0; i < (ret_read - 1); i++) {
        requestedMvmnt[i] = buff[i];
    }
    return getMvmnt(requestedMvmnt, currentMovement);
}
