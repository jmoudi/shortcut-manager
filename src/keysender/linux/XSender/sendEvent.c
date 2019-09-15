  #include <X11/Xlib.h>
#include <X11/Intrinsic.h>
#include <X11/extensions/XTest.h>
#include <unistd.h>

  // To send key events with XSendEvent(), we must set required parameters in a XKeyEvent struct and then invoke XSendEvent(). 
  void defineEvent(){
  XKeyEvent event;

  event.display = display;
  event.window = destination of the event;
  event.root = the root window;
  event.subwindow = None;
  event.time = CurrentTime;
  event.x = 1;
  event.y = 1;
  event.x_root = 1;
  event.y_root = 1;
  event.same_screen = TRUE;

  event.type = KeyPress;  or  event.type = KeyRelease;
  event.keycode = keycode;
  event.state = modifiers;
};

int main (){
  XSendEvent(event.display, event.window, TRUE, KeyPressMask, (XEvent *)event);
}
   e/* vent.window (and the second parameter of XSendEvent()) is the window ID of the destination of the event. To send the event to the window which has the input focus at the time, we can use the value obtained via XGetInputFocus(). To send the event to a specific window, we should set the window ID to event.window, and set keyboard focus to the window XSendEvent().

event.keycode is the keycode to be sent, and clients can reproduce the keysym from the keycode and value of the modifiers specified as event.modifiers.

event.state indicates the state of modifiers, and we must set the result of bitwise-or of the values for effective modifiers. Value for modifiers such as Shift or Control are defined as constans (ShiftMask and ControlMask, respectively). If modifiers such as Meta or Mode_switch are required, the value for them can be obtained via XGetModifierMapping().

The dominant problem for use of XSendEvent() is that events send by XSendEvent() (those send_event flag in Event struct were set) may ignored by some clients.  */