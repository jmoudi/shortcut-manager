#include <X11/Xlib.h>
#include <stdlib.h>
#include <iostream>

using namespace std;


void* TaskCode(void* parg)
{
    int keycode = *((int*)parg);
    cout<< "\n\n" << keycode << "\n\n";
    if(keycode == XKeysymToKeycode(XOpenDisplay(0),'a'))
        system("espeak -v en " "\"a\"");
    delete (int*)parg;
    return 0;
}

void Action(int keycode)
{
    pthread_t thread;
    pthread_attr_t  attrs;
    pthread_attr_init(&attrs);
    pthread_attr_setdetachstate(&attrs,PTHREAD_CREATE_DETACHED);
    pthread_attr_setstacksize(&attrs, 1000);
    int* pthread_arg = new int;
    *pthread_arg = keycode;
    pthread_create(&thread,&attrs, TaskCode, (void*) pthread_arg);
}

int MyX11ErrorHandler(Display *, XErrorEvent *error_event)
{
   cout << "\n\n" "An X11-Functions error occured. Probably the focused window was closed.""\n"
           "This error will be ignored." "\n";
   cout<< "error_code: " << (unsigned)error_event -> error_code << "\n";
   cout<< "minor_code: " << (unsigned)error_event -> minor_code << "\n";
   cout<< "request_code: " << (unsigned)error_event -> request_code << "\n";
   cout<< "resourceid: " << error_event -> resourceid << "\n";
   cout<< "serial; " << error_event -> serial << "\n";
   cout<< "type: " << error_event -> type << "\n\n";
   return 0;
}

int main()
{
    Display* display = XOpenDisplay(0);
    Window root = DefaultRootWindow(display);
    Window current_focus_window;
    int revert;

    XSetErrorHandler(MyX11ErrorHandler);

    XGetInputFocus(display, &current_focus_window, &revert);
    XSelectInput(display,current_focus_window,KeyPressMask | KeyReleaseMask | FocusChangeMask);

    while(true)
    {
        XEvent event;
        XNextEvent(display, &event);
        switch (event.type)
        {
            case FocusOut:
                if(current_focus_window != root)
                    XSelectInput(display, current_focus_window, 0);
                XGetInputFocus(display, &current_focus_window, &revert);
                if(current_focus_window == PointerRoot)
                    current_focus_window = root;
                XSelectInput(display, current_focus_window, KeyPressMask|KeyReleaseMask|FocusChangeMask);
                break;

            case KeyPress:
                Action(event.xkey.keycode);
                break;
        }
    }
}