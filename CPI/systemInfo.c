#include <stdio.h>
#include <stdlib.h>

int getRAM() {
    FILE *meminfo = fopen("/proc/meminfo", "r");
    if(meminfo == NULL)
        printf("ERROR OCCURED\n");

    char line[256];
    while(fgets(line, sizeof(line), meminfo))
    {
        int ram,freeRam,cache;
        if(sscanf(line, "MemTotal: %d kB", &ram) == 1) {            
            printf("Total Ram: \t %10d\n",ram);            
        }         
        if(sscanf(line, "MemFree: %d kB", &freeRam) == 1) {            
            printf("Free Ram: \t %10d\n",freeRam);            
        }
        if(sscanf(line, "Cached: %d kB", &cache) == 1) {            
            printf("Cache: \t %10d\n",cache);            
        }        
    }
    fclose(meminfo);
    return -1;
}

int getCPUInfo() {
    FILE *meminfo = fopen("/proc/cpuinfo", "r");
    if(meminfo == NULL)
        printf("ERROR OCCURED\n");
    int count=0;
    char line[256];
    while(fgets(line, sizeof(line), meminfo))
    {
        printf("%s",line);
        count++;
        if(count>8)       
        break;
    }
    fclose(meminfo);
    return -1;
}

void getBiosInfo() {
    if(system("biosdecode") == -1) {
        printf("Some error occured \n");
    }
}

void printFlag(char * str){
    printf("\t-------------------\n");
    printf("\t----%s----\n",str);
    printf("\t-------------------\n");
}

int main() {
    printFlag("System Info");
    getRAM();
    getCPUInfo();
    getBiosInfo();
}
