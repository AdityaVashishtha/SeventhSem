#include <X11/Xlib.h>
#include <stdio.h>
#include <unistd.h>

int main () {
    Window root_window; //<--one
    int root_x, root_y; //<--two
    unsigned int mask; //<--three    
    int i=1;
    while(i!=0) {
        i--;
        sleep(0.5);
        Display *display = XOpenDisplay(NULL);        
        XQueryPointer(display, DefaultRootWindow(display), &root_window, &root_window, &root_x, &root_y, &root_x, &root_y, &mask); //<--four
        printf("Mouse coordinates (X: %d, Y: %d)\n", root_x, root_y);
        XCloseDisplay(display);
        sleep(0.5);
    }    
    return 0;
}