
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <X11/X.h>         // `apt-get install libx11-dev`
#include <X11/Xmu/WinUtil.h>    // `apt-get install libxmu-dev`
#include <X11/XKBlib.h>
#include <X11/Xresource.h>
#include <X11/Xutil.h>
#include <X11/extensions/XTest.h>
#include <X11/extensions/Xinerama.h>
#include <X11/keysym.h>
#include <X11/cursorfont.h>


XGetInputFocus
XSetInputFocus

int	main(int argc, char **argv)
{
    int ii, Junk;
    int c;
    char *temp;
    unsigned long count = 1;
    progname = argv[0];

    if(displayname == NULL)
	displayname = getenv("DISPLAY");

    if(displayname == NULL)
	displayname = ":0.0";

    display = XOpenDisplay(displayname);

    if(display == NULL)
    {
	fprintf(stderr, "%s: can't open display `%s'.\n",
		progname, displayname);
	exit(1);
    }

    if(window == 0)
        XGetInputFocus(display, &window, &Junk);

    if(window == (Window)-1)
    {
        window = RootWindow(display, 0); // XXX nonzero screens?
    }

    // now do the work:
    for (ii=0;ii<(int)count;ii++)
      SendKeyPressedEvent(keysym, shift);

    XCloseDisplay(display);

    return 0;
}

void aa(){
  XSetInputFocus(disp, list[selectWindow],RevertToPointerRoot,CurrentTime);
  for(i=0;i<hello.size();i++){
      tamper[0] = hello[i];
      KeySym key = XStringToKeysym(tamper);
      XTestFakeKeyEvent(disp,XKeysymToKeycode(disp, key),True, CurrentTime );
      XTestFakeKeyEvent(disp,XKeysymToKeycode(disp, key),False, CurrentTime );
  }

}



void _xdo_init_xkeyevent(const xdo_t *xdo, XKeyEvent *xk) {
  xk->display = xdo->xdpy;
  xk->subwindow = None;
  xk->time = CurrentTime;
  xk->same_screen = True;

  /* Should we set these at all? */
  xk->x = xk->y = xk->x_root = xk->y_root = 1;
}

void _xdo_send_key(const xdo_t *xdo, Window window, charcodemap_t *key,
                          int modstate, int is_press, useconds_t delay) {
  /* Properly ensure the modstate is set by finding a key
   * that activates each bit in the modifier state */
  int mask = modstate | key->modmask;
  int use_xtest = 0;

  if (window == CURRENTWINDOW) {
    use_xtest = 1;
  } else {
    Window focuswin = 0;
    xdo_get_focused_window(xdo, &focuswin);
    if (focuswin == window) {
      use_xtest = 1;
    }
  }
  if (use_xtest) {
    //printf("XTEST: Sending key %d %s\n", key->code, is_press ? "down" : "up");
    XkbStateRec state;
    XkbGetState(xdo->xdpy, XkbUseCoreKbd, &state);
    int current_group = state.group;
    XkbLockGroup(xdo->xdpy, XkbUseCoreKbd, key->group);
    if (mask)
      _xdo_send_modifier(xdo, mask, is_press);
    //printf("XTEST: Sending key %d %s %x %d\n", key->code, is_press ? "down" : "up", key->modmask, key->group);
    XTestFakeKeyEvent(xdo->xdpy, key->code, is_press, CurrentTime);
    XkbLockGroup(xdo->xdpy, XkbUseCoreKbd, current_group);
    XSync(xdo->xdpy, False);
  } else {
    /* Since key events have 'state' (shift, etc) in the event, we don't
     * need to worry about key press ordering. */
    XKeyEvent xk;
    _xdo_init_xkeyevent(xdo, &xk);
    xk.window = window;
    xk.keycode = key->code;
    xk.state = mask | (key->group << 13);
    xk.type = (is_press ? KeyPress : KeyRelease);
    XSendEvent(xdo->xdpy, xk.window, True, KeyPressMask, (XEvent *)&xk);
  }