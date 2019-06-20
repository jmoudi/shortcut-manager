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


xprop

xdotool search --class octopi windowactivate
xdotool search --class "Firefox Developer Edition" windowactivate

--window

xwininfo -display :0


xorg-wininfo

xorg-twm




xdotool search --id 0x5e00010


wmctrl

  windowactivate
  windowfocus




xwininfo -name *irefox*



xwininfo: can not set locale properly
xwininfo: unrecognized argument --help

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

