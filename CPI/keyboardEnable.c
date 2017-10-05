#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int KEYBOARD_ID = 12;
    printf("Enter time in second to disable your keyboard \n");
    char command[512]="xinput set-prop 11 'Device Enabled' 0 & sleep";
    char commandPart[512] = "; xinput set-prop 11 'Device Enabled' 1";    
    int time = 5;    
    scanf("%d",&time);
    sprintf(command,"%s %d %s",command,time,commandPart);
    system(command);
}
