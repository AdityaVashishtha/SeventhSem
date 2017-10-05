#include <stdio.h>
#include <sys/ioctl.h>
#include <linux/kd.h>
 
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
//   int x = ioctl(1, KDSETLED, K_CAPSLOCK);
//   printf("%d",x);
//   return 0;
    int tty = open("/dev/tty1", O_RDONLY);
    int state;
    int x = ioctl(tty, KDGETLED, &state);
    printf("%d \n",x);
    x = ioctl(tty, KDSETLED, state | LED_SCR);
    printf("%d \n",x);
}