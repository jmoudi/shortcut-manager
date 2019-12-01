

ButtonRelease event, serial 40, synthetic NO, window 0x9200001,
    root 0x16a, subw 0x0, time 37791712, (127,85), root:(127,1107),
    state 0x100, button 1, same_screen YES

KeyPress event, serial 40, synthetic NO, window 0x9200001,
    root 0x16a, subw 0x0, time 37791768, (127,85), root:(127,1107),
    state 0x0, keycode 40 (keysym 0x64, d), same_screen YES,
    XLookupString gives 1 bytes: (64) "d"
    XmbLookupString gives 1 bytes: (64) "d"
    XFilterEvent returns: False

KeyRelease event, serial 40, synthetic NO, window 0x9200001,
    root 0x16a, subw 0x0, time 37791870, (127,85), root:(127,1107),
    state 0x0, keycode 40 (keysym 0x64, d), same_screen YES,
    XLookupString gives 1 bytes: (64) "d"
    XFilterEvent returns: False

KeyPress event, serial 40, synthetic NO, window 0x9200001,
    root 0x16a, subw 0x0, time 37792587, (127,85), root:(127,1107),
    state 0x0, keycode 41 (keysym 0x66, f), same_screen YES,
    XLookupString gives 1 bytes: (66) "f"
    XmbLookupString gives 1 bytes: (66) "f"
    XFilterEvent returns: False

KeyRelease event, serial 40, synthetic NO, window 0x9200001,
    root 0x16a, subw 0x0, time 37792754, (127,85), root:(127,1107),
    state 0x0, keycode 41 (keysym 0x66, f), same_screen YES,
    XLookupString gives 1 bytes: (66) "f"
    XFilterEvent returns: False



xorg-xev
xev | awk -F'[ )]+' '/^KeyPress/ { a[NR+2] } NR in a { printf "%-3s %s\n", $5, $8 }'

sudo showkey --scancodes

zz

xev -event keyboard
https://www.uninformativ.de/blog/postings/2017-04-02/0/POSTING-en.html


https://godoc.org/azul3d.org/engine/keyboard
https://github.com/bendahl/uinput
https://github.com/micmonay/keybd_event

https://godoc.org/azul3d.org/engine/gfx/internal
https://godoc.org/azul3d.org/engine/gfx/window


X11 clipboard 101

    This ‘thing’ is called “selection”. Every time I use ‘selection’ it translates into ‘clipboard’ for all other systems.
https://medium.com/journey-to-rust/working-with-clipboard-b4564b906d46

https://medium.com/journey-to-rust/working-with-clipboard-b4564b906d46
