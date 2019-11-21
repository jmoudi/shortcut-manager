
kde-cli-tools
xorg-server-wayland xorg-xdm xorg-xdpyinfo xorg-xhost
/usr/
xorg-server-xwayland
/usr/include/X11/keysym.h and in /usr/include/X11/keysymdef.h

xprop
xorg-server

libxkbcommon-doc
/usr/lib/libxcb-xinerama.so.0.0.0
cd $(realpath libxkbcommon-doc)
/usr/include/X11/
/usr/include/xkbcommon/

http://kbd-project.org/docs/howto-linux-keyboard-and-console/kbd-15.html
Something else people like to change are the bindings of the function keys. Suppose that you want to make F12 produce the string "emacs ". Then

        % loadkeys
        keycode 88 = F12
        string F12 = "emacs "
        %
