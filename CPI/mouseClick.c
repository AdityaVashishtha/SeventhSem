#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

int main (){    
    int count=0;
    int stopAt=4;
    int button;
    XEvent event;    
    Display *display = XOpenDisplay(NULL);    
    Window root= XDefaultRootWindow(display);
    XGrabPointer(display, root, False, ButtonPressMask, GrabModeAsync, GrabModeAsync, None, None, CurrentTime);
    XSelectInput(display, root, ButtonPressMask) ;
    while(1){
        XNextEvent(display,&event);
        printf("Click! :: ");
        switch(event.type){
            case ButtonPress:    
                count++;                    
                button = event.xbutton.button;                
                if(button==Button1)
                    printf("Left Click !! \t (count = %d)\n",count);
                else if(button==Button2)
                    printf("Middle Click !! \t (count = %d)\n",count);    
                else if(button==Button3)
                    printf("Right Click !! \t (count = %d)\n",count);    
                else if(button == Button5)
                    printf("Scrolled !! \t (count = %d)\n",count);    
                break; 
            default:
                printf("Unknown Event \n"); 
                break;
        }
        if(count >= stopAt)
            break;
    }   
    XCloseDisplay(display);
    return 0;
}
