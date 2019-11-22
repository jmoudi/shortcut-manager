 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <X11/Xlib.h>
#include <X11/keysym.h> 

static char    *progname       = NULL;
static char    *displayname    = NULL;
static Window   window         = 0;
static Display *display        = NULL;
static char     keyname[1024];
static int      shift          = 0;
static int      keysym         = 0;

int	MyErrorHandler(Display *my_display, XErrorEvent *event)
{
    fprintf(stderr, "%s: XSendEvent(0x%lx) failed.\n", progname, window);
    return 1;
}

void	SendEvent(XKeyEvent *event)
{
    XSync(display, False);
    XSetErrorHandler(MyErrorHandler);
    XSendEvent(display, window, True, KeyPressMask, (XEvent*)event);
    XSync(display, False);
    XSetErrorHandler(NULL);
}

void	SendKeyPressedEvent(KeySym keysym, unsigned int shift)
{
    XKeyEvent		event;

    // Meta not yet implemented (Alt used instead ;->)
    //int meta_mask=0;

    event.display	= display;
    event.window	= window;
    event.root		= RootWindow(display, 0); // XXX nonzero screens?
    event.subwindow	= None;
    event.time		= CurrentTime;
    event.x		= 1;
    event.y		= 1;
    event.x_root	= 1;
    event.y_root	= 1;
    event.same_screen	= True;
    event.type		= KeyPress;
    event.state		= 0;

    //
    // press down shift keys one at a time...
    //

/*      if (shift & ShiftMask) {
	    event.keycode = XKeysymToKeycode(display, XK_Shift_L);
        printf("SHIFT %d", event.keycode);
	    SendEvent(&event);
	    event.state |= ShiftMask;
    } */
    //if (shift & ControlMask) {
        event.keycode = XKeysymToKeycode(display, XK_Control_L);
        printf("ControlMask %d", event.keycode);
        SendEvent(&event);
        event.state |= ControlMask;
    //}
/*      if (shift & Mod1Mask) {
        event.keycode = XKeysymToKeycode(display, XK_Alt_L);
        SendEvent(&event);
        event.state |= Mod1Mask;
    }
    if (shift & meta_mask) {
        event.keycode = XKeysymToKeycode(display, XK_Meta_L);
        SendEvent(&event);
        event.state |= meta_mask;
    } */
    printf("CCCCCv %d", event.keycode);
    //  Now with shift keys held down, send event for the key itself...
    // fprintf(stderr, "sym: 0x%x, name: %s\n", keysym, keyname);
    if (keysym != NoSymbol) {
        event.keycode = XKeysymToKeycode(display, keysym);
        // fprintf(stderr, "code: 0x%x, %d\n", event.keycode, event.keycode );
        SendEvent(&event);

        event.type = KeyRelease;
        SendEvent(&event);
    }

    //
    // Now release all the shift keys...
    //

/*     if (shift & ShiftMask) {
        event.keycode = XKeysymToKeycode(display, XK_Shift_L);
        SendEvent(&event);
        event.state &= ~ShiftMask;
    } */
    if (shift & ControlMask) {
        event.keycode = XKeysymToKeycode(display, XK_Control_L);
        SendEvent(&event);
        event.state &= ~ControlMask;
    }
/*     if (shift & Mod1Mask) {
        event.keycode = XKeysymToKeycode(display, XK_Alt_L);
        SendEvent(&event);
        event.state &= ~Mod1Mask;
    }
    if (shift & meta_mask) {
        event.keycode = XKeysymToKeycode(display, XK_Meta_L);
        SendEvent(&event);
        event.state &= ~meta_mask;
    } */
}
 
int	main(int argc, char **argv)
{
    keysym = 0;
    shift  = 0;
    int Junk;
    if(displayname == NULL){
	    displayname = getenv("DISPLAY");
    }

    if(displayname == NULL){
	    displayname = ":0.0";
    }
    display = XOpenDisplay(displayname);

    if(window == 0)
        XGetInputFocus(display, &window, &Junk);

    if(window == (Window)-1)
    {
        window = RootWindow(display, 0); // XXX nonzero screens?
    }

    shift |= ControlMask;
    keysym = XK_V;
    printf("keysym %d", keysym);
    SendKeyPressedEvent(keysym, shift);

    XCloseDisplay(display);

    return 0;
}
