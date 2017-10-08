#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int KEYBOARD_ID = 11;
    if(KEYBOARD_ID == 0) {
        printf("Wrong keyboard id set keyboard id first \n");
        exit(0);
    }
    char command[512]="xinput set-prop 10 'Device Enabled' 0 & sleep";
    char commandPart[512] = "; xinput set-prop 10 'Device Enabled' 1";   
    printf("Enter time in second to disable your keyboard (default is 5) \n");
    int time = 5;    
    scanf("%d",&time);
    sprintf(command,"%s %d %s",command,time,commandPart);
    system(command);
}
