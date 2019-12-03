#!/bin/bash
echo "Running..."
function xd(){
    # get browser windows
    local WID=$(xdotool search --desktop 0 --class ".*irefox.*" | head -1)
    echo "$WID"
    xdotool windowactivate --sync $WID 
    xdotool key --clearmodifiers ctrl+l
    xdotool type "dsfsfsf"

}; xd

WID=`xdotool search "Mozilla Firefox" | head -1`
xdotool windowactivate --sync $WID
xdotool key --clearmodifiers ctrl+l


function xd(){
    WID=`xdotool search "Mozilla Firefox" | head -1`
    xdotool windowactivate --sync $WID
    xdotool key --clearmodifiers ctrl+l
}; xd

function xd(){
    # get browser windows
    local WID=$(xdotool search --desktop 0 --class ".*irefox.*" | head -1)
    echo "$WID"
    xdotool windowactivate --sync $WID 
    xdotool key --clearmodifiers ctrl+l
    xdotool type "dsfsfsf"

}; xd
xdotool search --desktop 0 --class ".*irefox.*" 
function xd(){
    local WID=$(xdotool search --desktop 0 --class ".*irefox.*" | head -1)
    echo "$WID"
 

}; xd



xdotool get_num_desktops
set_num_desktops


    xdotool windowactivate --sync $WID
    xdotool key --clearmodifiers ctrl+l
xdotool search "Mozilla Firefox" windowactivate --sync key --clearmodifiers ctrl+l

xdotool search "firefox" windowactivate --sync key --clearmodifiers ctrl+l

xdotool search --class "Firefox Developer Edition" --windowsize --usehints %@ 80 24


-stats

xprop

xdotool search --class octopi windowactivate
xdotool search --class "Firefox Developer Edition" windowactivate

--window

xwininfo -display :0

xprop -id 123731975

xdotool getactivewindow
getwindowfocus
getwindowname
getwindowpid

xorg-wininfo

xorg-twm


You can run wmctrl -l in a loop or on a timer (e.g. sleep 10; wmctrl -l) and then start the fullscreen application and record its window properties. If you want more information, you can do something like

sleep 10; xprop




xdotool search --id 0x5e00010


wmctrl

  windowactivate
  windowfocus

   xwininfo -stats
xdotool getactivewindow | xdotool getwindowname
xwininfo -name *irefox*


xwininfo -name
xwininfo: can not set locale properly
xwininfo: unrecognized argument --help


xdotool getactivewindow | xprop -f 'WM_CLASS(STRING)'

WM_CLASS
function aa(){
    local wid=$(xdotool getactivewindow);
    xprop -id $wid | rg 'WM_CLASS'
}; aa

function aa(){
    local wid=$(xdotool getactivewindow);
    xprop -id $wid -f 'WM_CLASS'
}; aa
xdotool getactivewindow | xprop -id


usage:  xprop [-options ...] [[format [dformat]] atom] ...
where options include:
-grammar                       print out full grammar for command line
-display host:dpy              the X server to contact
-id id                         resource id of window to examine
-name name                     name of window to examine
-font name                     name of font to examine
-remove propname               remove a property
-set propname value            set a property to a given value
-root                          examine the root window
-len n                         display at most n bytes of any property
-notype                        do not display the type field
-fs filename                   where to look for formats for properties
-frame                         don't ignore window manager frames
-f propname format [dformat]   formats to use for property of given name
-spy                           examine window properties forever
-version                       print program version

usage:  xwininfo [-options ...]

where options include:
    -help                print this message
    -version             print version message
    -display host:dpy    X server to contact
    -root                use the root window
    -id windowid         use the window with the specified id
    -name windowname     use the window with the specified name
    -int                 print window id in decimal
    -children            print parent and child identifiers
    -tree                print children identifiers recursively
    -stats               print window geometry [DEFAULT]
    -bits                print window pixel information
    -events              print events selected for on window
    -size                print size hints
    -wm                  print window manager hints
    -shape               print shape extents
    -frame               don't ignore window manager frames
    -english             print sizes in english units
    -metric              print sizes in metric units
    -all                 -tree, -stats, -bits, -events, -wm, -size, -shape




WM_CLASS(STRING) = "konsole", "konsole"


xprop |awk '/WM_CLASS/{print $4}'