#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

void main() {
    FILE *fp;
    int fd = open("/dev/null", O_WRONLY);
    dup2(fd, 2);
    close(fd);
    char *command="fdisk -l";
    char out[512];
    fp = popen(command,"r"); 
    int flag =1;
    while(flag) {
        fscanf(fp,"%s",out);   
        const char *device = "Device";
        if(strcmp(out,device)==0){                        
            break;
        }
    }
    char temp[512];
    printf("---------------------------------------------------------------------------\n");
    printf("%s",out);
    strcpy(out,"Partition");
    while(fgets(temp,10,fp)!=NULL){
        // fseek(fp,-10,SEEK_CUR);
        // fscanf(fp,"%[^\t]s %[^\t]s %[^\t]s %[^\t]s %[^\t]s %[^\t]s %[^\t]s %[^\t]s",device,temp,temp,temp,sectors,size,temp,type);   
        if(strcmp(out,temp)==0)
            break;
        printf("%s",temp);    
    }
    printf("---------------------------------------------------------------------------\n");    
}