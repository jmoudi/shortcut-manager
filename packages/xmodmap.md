
https://renenyffenegger.ch/notes/Linux/X/XKB/database#keycodes


yarn link @std/log @std/subprocess @std/async @std/fs



xsel --clipboard --output --selectionTimeout 3000



xev

xprop


Enter"(Scheme function)"
m:0x0 + c:36
Return




# create custom table
xmodmap -pke > ~/.Xmodmap
#test
xmodmap ~/.Xmodmap

xbindkeys --defaults-guile > /home/jm/.xbindkeysrc.scm


xbindkeys --key


# enter
    m:0x0 + c:36
    Return


# fn
"(Scheme function)"
    m:0x0 + c:151
    XF86WakeUp

# ctrl
    m:0x4 + c:37
    Control + Control_L


```

keycode  66 = KP_Enter NoSymbol KP_Enter
PageDown -> Next,c:117

keycode  66 = Caps_Lock NoSymbol Caps_Lock
keycode 104 = KP_Enter NoSymbol KP_Enter
keycode  79 = KP_Home KP_7 KP_Home KP_7
keycode  80 = KP_Up KP_8 KP_Up KP_8
keycode  81 = KP_Prior KP_9 KP_Prior KP_9
keycode  82 = KP_Subtract KP_Subtract KP_Subtract KP_Subtract KP_Subtract KP_Subtract XF86Prev_VMode
keycode  83 = KP_Left KP_4 KP_Left KP_4
keycode  84 = KP_Begin KP_5 KP_Begin KP_5
keycode  85 = KP_Right KP_6 KP_Right KP_6
keycode  86 = KP_Add KP_Add KP_Add KP_Add KP_Add KP_Add XF86Next_VMode
keycode  87 = KP_End KP_1 KP_End KP_1
keycode  88 = KP_Down KP_2 KP_Down KP_2
keycode  89 = KP_Next KP_3 KP_Next KP_3
keycode  90 = KP_Insert KP_0 KP_Insert KP_0
keycode  91 = KP_Delete KP_Decimal KP_Delete KP_Decimal
keycode  92 = ISO_Level3_Shift NoSymbol ISO_Level3_Shift
keycode 110 = Home NoSymbol Home
keycode 111 = Up NoSymbol Up
keycode 112 = Prior NoSymbol Prior
keycode 113 = Left NoSymbol Left
keycode 114 = Right NoSymbol Right
keycode 115 = End NoSymbol End
keycode 116 = Down NoSymbol Down
keycode 117 = Next NoSymbol Next
keycode 118 = Insert NoSymbol Insert
keycode 119 = Delete NoSymbol Delete


xorg-xev
xbindkeys
xorg-xmodmap
xev | awk -F'[ )]+' '/^KeyPress/ { a[NR+2] } NR in a { printf "%-3s %s\n", $5, $8 }'


!
! Swap Caps_Lock and Control_L
!
remove Lock = Caps_Lock
remove Control = Control_L
keysym Control_L = Caps_Lock
keysym Caps_Lock = Control_L
add Lock = Caps_Lock
add Control = Control_L



clear lock
keycode 66 = KP_Enter
