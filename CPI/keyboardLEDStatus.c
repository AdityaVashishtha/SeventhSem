#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <X11/Xlib.h>

int main(void) {  
   Display *dpy = XOpenDisplay(":0"); 
   XKeyboardState x;
   XGetKeyboardControl(dpy, &x);
   XCloseDisplay(dpy);

   printf("Enter no. of times to blink led\n");
   float time = 2.5;
   scanf("%f",&time);
   printf("Keyboard Status indicator");
   char cmd[512] = "./led.sh ";
   sprintf(cmd,"%s %f",cmd,time);
   system(cmd);
   printf("led_mask=%lx\n", x.led_mask);   
   printf("NumLock is %s\n", (x.led_mask & 2) ? "On" : "Off");
   printf("CAPSLock is %s\n", (x.led_mask & 1) ? "On" : "Off");
   //printf("scrollLock is %s\n", (x.led_mask & 3) ? "On" : "Off");
   return 0;
}