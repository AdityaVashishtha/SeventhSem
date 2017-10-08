#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "X11/Xlib.h"
#include "X11/Xutil.h"

int cord[2];

void mouseMove(int x, int y)
{
    Display *display = XOpenDisplay(NULL);    
    XWarpPointer(display, None, None, 0, 0, 0, 0, x, y);    
    XCloseDisplay(display);
}

void getCurrentLocation() {
    Window root_window; 
    int root_x, root_y; 
    unsigned int mask; 
    Display *display = XOpenDisplay(NULL);        
    XQueryPointer(display, DefaultRootWindow(display), &root_window, &root_window, &root_x, &root_y, &root_x, &root_y, &mask); 
    printf("Mouse coordinates (X: %d, Y: %d)\n", root_x, root_y);
    XCloseDisplay(display);
    cord[0] = root_x;
    cord[1] = root_y;
}

int main(){
    printf("Enter location to restrict as between 0,0 and x,y\n");
    int x,y;
    int new_x,new_y;
    scanf("%d%d",&x,&y);
    while(1) {
        new_x=new_y=0;
        sleep(0.5);        
        getCurrentLocation();
        if(cord[0]>x)
            new_x = x -cord[0];
        if(cord[1]>y)
            new_y = y -cord[1];
        if(new_x != 0 || new_y !=0)
            mouseMove(new_x,new_y);        
            sleep(0.5);          
        printf("CurLocation :: \t %d\t%d \n",cord[0],cord[1]);        
    }    
}
