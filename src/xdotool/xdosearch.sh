m-pc Public]$ xdotool search --help
Usage: xdotool search [options] regexp_pattern
--class         check regexp_pattern against the window class
--classname     check regexp_pattern against the window classname
--maxdepth N    set search depth to N. Default is infinite.
                -1 also means infinite.
--onlyvisible   matches only windows currently visible
--pid PID       only show windows belonging to specific process
                Not supported by all X11 applications
--screen N      only search a specific screen. Default is all screens
--desktop N     only search a specific desktop number
--limit N       break search after N results
--name          check regexp_pattern against the window name
--shell         print results as shell array WINDOWS=( ... )
--prefix STR    use prefix (max 16 chars) for array name STRWINDOWS
--title         DEPRECATED. Same as --name.
--all           Require all conditions match a window. Default is --any
--any           Windows matching any condition will be reported
--sync          Wait until a search result is found.
-h, --help      show this help output

If none of --name, --classname, or --class are specified, the 
defaults are: --name --classname --class
[jm@jm-pc Public]$ 


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

