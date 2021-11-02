#include <stdio.h>
#include <stdlib.h>

#define FULL_STATE    100
#define CRITIC_STATE  25
#define NO_STATE  -1

void notify(char* message, char* urgency);


int main(int argc, char const *argv[]){
    int battery_state = NO_STATE;
    FILE *fptr = fopen("/sys/class/power_supply/BAT0/capacity", "r");

    if (fptr == NULL) return EXIT_FAILURE;

    fscanf(fptr, "%d", &battery_state);

    if (battery_state == FULL_STATE)
        notify("fully charged", "normal");
    else if (battery_state <=CRITIC_STATE)
        notify("low battery", "critical");

    return EXIT_SUCCESS;
}


void notify(char* message, char* urgency){
    char command[512];
    
    sprintf(command, "notify-send 'Battery State' '%s' -u %s", message, urgency);
    system(command);
}