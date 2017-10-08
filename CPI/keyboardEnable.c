#include <stdio.h>
#include <stdlib.h>
#include<sys/io.h>
#include<unistd.h>
#include <sys/file.h>

int main() {      
    printf("Enter time in second to disable your keyboard (default is 5) \n");
    int time = 5;    
    scanf("%d",&time);
    int data,fd;
    int PORT_OFFSET = 0x60;
    int OFFSET=0;
    int WAIT_FOR_ENABLE = 0xF5;
    int ENABLE_KBD = 0xF4;
    if(fd=open("/dev/port",O_RDWR | O_SYNC) < 0 ) {
        printf("Counldn\'t open file, (Try with sudo)\n");
        exit(0);
    }    
    lseek(fd,PORT_OFFSET,OFFSET);
    printf("Disabling keyboard for (%d sec) ... \n",time);
    write(fd,&WAIT_FOR_ENABLE,1);
    sleep(time);  
    lseek(fd,PORT_OFFSET,OFFSET);
    printf("Keyboard Enabled\n");
    write(fd,&ENABLE_KBD,1);    
}
