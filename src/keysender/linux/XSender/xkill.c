
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


int xdo_kill_window(const xdo_t *xdo, Window window) {
  int ret;
  ret = XKillClient(xdo->xdpy, window);
  return _is_success("XKillClient", ret == 0, xdo);
}


int xdo_get_window_name(const xdo_t *xdo, Window window, 
                        unsigned char **name_ret, int *name_len_ret,
                        int *name_type) {
  if (atom_NET_WM_NAME == (Atom)-1) {
    atom_NET_WM_NAME = XInternAtom(xdo->xdpy, "_NET_WM_NAME", False);
  } 
  if (atom_WM_NAME == (Atom)-1) {
    atom_WM_NAME = XInternAtom(xdo->xdpy, "WM_NAME", False);
  }
  if (atom_STRING == (Atom)-1) {
    atom_STRING = XInternAtom(xdo->xdpy, "STRING", False);
  }
  if (atom_UTF8_STRING == (Atom)-1) {
    atom_UTF8_STRING = XInternAtom(xdo->xdpy, "UTF8_STRING", False);
  }

  Atom type;
  int size;
  long nitems;

  /**
   * http://standards.freedesktop.org/wm-spec/1.3/ar01s05.html
   * Prefer _NET_WM_NAME if available, otherwise use WM_NAME
   * If no WM_NAME, set name_ret to NULL and set len to 0
   */

  *name_ret = xdo_get_window_property_by_atom(xdo, window, atom_NET_WM_NAME, &nitems,
                             &type, &size);
  if (nitems == 0) {
    *name_ret = xdo_get_window_property_by_atom(xdo, window, atom_WM_NAME, &nitems,
                               &type, &size);
  }
  *name_len_ret = nitems;
  *name_type = type;

  return 0;
}


/* Arbitrary window property retrieval
 * slightly modified version from xprop.c from Xorg */
unsigned char *xdo_get_window_property_by_atom(const xdo_t *xdo, Window window, Atom atom,
                                            long *nitems, Atom *type, int *size) {
  Atom actual_type;
  int actual_format;
  unsigned long _nitems;
  /*unsigned long nbytes;*/
  unsigned long bytes_after; /* unused */
  unsigned char *prop;
  int status;

  status = XGetWindowProperty(xdo->xdpy, window, atom, 0, (~0L),
                              False, AnyPropertyType, &actual_type,
                              &actual_format, &_nitems, &bytes_after,
                              &prop);
  if (status == BadWindow) {
    fprintf(stderr, "window id # 0x%lx does not exists!", window);
    return NULL;
  } if (status != Success) {
    fprintf(stderr, "XGetWindowProperty failed!");
    return NULL;
  }

  /*
   *if (actual_format == 32)
   *  nbytes = sizeof(long);
   *else if (actual_format == 16)
   *  nbytes = sizeof(short);
   *else if (actual_format == 8)
   *  nbytes = 1;
   *else if (actual_format == 0)
   *  nbytes = 0;
   */

  if (nitems != NULL) {
    *nitems = _nitems;
  }

  if (type != NULL) {
    *type = actual_type;
  }

  if (size != NULL) {
    *size = actual_format;
  }
  return prop;
}