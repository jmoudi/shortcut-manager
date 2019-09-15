 
xcutsel copy

cat "ooo" | xclip -in
$(echo "oo") | xclip -in
printf "ee" | xclip -in

function aa(){
    printf "ee" | xclip -in;
    xclip -o -sel clip > webpage.txt
}; aa

function aa(){
    printf "ee" | xclip -in;
    xclip -o -sel clip > webpage.txt
}; aa

xdotool search --class ".*irefox.*" 

 xdotool search --name ".*irefox.*" 

https://aur.archlinux.org/packages/xmacro/


$ xev | grep -A2 --line-buffered '^KeyRelease' \
    | sed -n '/keycode /s/^.*keycode \([0-9]*\).* (.*, \(.*\)).*$/\1 \2/p'


    KeyRelease event, serial 40, synthetic NO, window 0x9400001,
    root 0x16a, subw 0x0, time 547664502, (110,46), root:(110,1238),
    state 0x0, keycode 41 (keysym 0x66, f), same_screen YES,
    XLookupString gives 1 bytes: (66) "f"
    XFilterEvent returns: False


add_key ok!!!  fun=1
add_key ok!!!  fun=1
add_key ok!!!  fun=1
add_key ok!!!  fun=1
add_key ok!!!  fun=1
add_key ok!!!  fun=1
add_key ok!!!  fun=1
add_key ok!!!  fun=1
add_key ok!!!  fun=1
add_key ok!!!  fun=1
add_key ok!!!  fun=1
add_key ok!!!  fun=1
"xbindkeys_show"
    Control+Shift + q
"xterm"
    m:0x4 + c:41
    Control + f
"xterm"
    m:0x4 + b:2   (mouse)
"xterm"
    m:0xc + c:41
    Control+Alt + f
"(Scheme function)"
    Control + a
"(Scheme function)"
    Shift + p
"(Scheme function)"
    Control + w
"(Scheme function)"
    Shift + w
"(Scheme function)"
    m:0x1 + b:1   (mouse)
"(Scheme function)"
    m:0x1 + b:3   (mouse)
"(Scheme function)"
    Release + m:0x1 + b:1   (mouse)
"(Scheme function)"
    Release + m:0x1 + b:3   (mouse)
"(Scheme function)"
    m:0x8 + b:1   (mouse)
"(Scheme function)"
    m:0x8 + b:3   (mouse)
"(Scheme function)"
    Release + m:0x8 + b:1   (mouse)
"(Scheme function)"
    Release + m:0x8 + b:3   (mouse)

