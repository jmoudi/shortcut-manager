 

#ifndef XSENDKEY_H
#define XSENDKEY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <X11/Xlib.h>
#include <X11/keysym.h> 


void SendEvent(XKeyEvent *event);
void SendKeyPressedEvent(KeySym keysym, unsigned int shift);

#endif