#include<sys/io.h>
#include<stdio.h>
#include<sys/io.h>
#include<unistd.h>
#include <sys/file.h>
int main()
{
int data;
int k;
int fd;
 if ( (fd = open( "/dev/port", O_RDWR )) < 0) {
            perror("Cannot open /dev/port" );
            exit( 1 );
      }

lseek( fd, 0x60, 0 );
printf("%d",k);
printf("keyboard disabled\n");
 data = 0xf5; 
write( fd, &data, 1 ) ;                

sleep(2);

lseek( fd, 0x60, 0 );
data = 0xf4;                 


 write( fd, &data, 1 ) ; 
printf("keyboard enabled");
      close( fd );



}




