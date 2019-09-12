#include <X11/Xatom.h>
#include <X11/Xlib.h>
 #include <X11/Xos.h>
#include <X11/Xfuncs.h>
#include <X11/Xutil.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#ifdef HAVE_WCHAR_H
#include <wchar.h>
#endif
#ifdef HAVE_WCTYPE_H
#include <wctype.h>
#endif
#include <locale.h>
#ifdef HAVE_LANGINFO_H
#include <langinfo.h>
#endif

XGetWindowProperty