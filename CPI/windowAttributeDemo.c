/** gcc position.c -o position -lX11 **/
#include <X11/Xlib.h>
#include <stdio.h>


int main (int argc, char **argv) {
    Window root_window; //<--one
    int root_x, root_y; //<--two
    unsigned int mask; //<--three

    Display *display = XOpenDisplay(NULL);
    if (display == NULL) {
        fprintf(stderr, "Cannot connect to X server!\n");
        exit (EXIT_FAILURE);
    }
    // Status XGetWindowAttributes(display, w, window_attributes_return)
    // Display *display;
    // Window w;
    // XWindowAttributes *window_attributes_return;
    XWindowAttributes window_attributes_return;
    XGetWindowAttributes(display,  DefaultRootWindow(display), &window_attributes_return);
    printf("Windows position : %d  %d \n",window_attributes_return.width,window_attributes_return.y);
    return 0;
}