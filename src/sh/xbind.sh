 
function xx(){
    killall xbindkeys;
    xbindkeys -v -f /home/jm/Projects/Apps/HotkeyManager/xbindkeys.conf;
    xbindkeys -s;
}; xx

function xx(){
    killall xbindkeys;
    xbindkeys -v -fg ./config/xb-main.scm;
    xbindkeys -s;
}; xx

xbindkeys -mk,
A list of keys is in /usr/include/X11/keysym.h and in /usr/include/X11/keysymdef.h.  The XK_ is not needed.

xbindkeys --defaults-guile > ./config/xbg.conf

usage: xbindkeys [options]
  where options are:
  -V, --version           Print version and exit
  -d, --defaults          Print a default rc file
 -dg, --defaults-guile    Print a default guile configuration file
  -f, --file              Use an alternative rc file
 -fg, --file-guile        Use an alternative guile configuration file
  -p, --poll-rc           Poll the rc/guile configs for updates
  -h, --help              This help!
  -X, --display           Set X display to use
  -v, --verbose           More information on xbindkeys when it run
  -s, --show              Show the actual keybinding
  -k, --key               Identify one key pressed
 -mk, --multikey          Identify multi key pressed
  -g, --geometry          size and position of window open with -k|-mk option
  -n, --nodaemon          don't start as daemon
[jm@jm-pc Public]$ 


xbindkeys -p.
A keycode can be identified with xbindkeys -k 


"firefox"
    F8

"firefox"
    control+shift + q

     Running xbindkeys goes into daemon mode, so pass -n to test it. If everything works properly, put the following into your .profile :