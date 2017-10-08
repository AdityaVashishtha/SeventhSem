#include <conio.h>
#include <dos.h>  
union REGS in, out;

void detect_mouse() {
	in.x.ax = 0;
	int86 (0X33,&in,&out);   
	if (out.x.ax == 0) {
		printf ("Mouse Driver not Detected\n");
		exit(0);
	}
	else
		printf ("Mouse Driver Detected\n");
}

int main ()
{
    	detect_mouse();
	getch ();
	return 0;
}
