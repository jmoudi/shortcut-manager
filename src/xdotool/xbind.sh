
# make xbindkeys reload config
killall -s1 xbindkeys

Start xbindkeys:

# start xbindkeys daemon
xbindkeys -f ~/.xbindkeysrc


killall -s1 xbindkeys
xbindkeys -f ~/.xbindkeysrc
xbindkeys --show



xmodmap ~/.Xmodmap

# reload xbindkeys
# "xmodmap ~/.Xmodmap && killall xcape && xcape -e 'Hyper_L=Return' && killall xbindkeys && xbindkeys"
"killall xbindkeys ; xbindkeys"
Control+Shift+z

function xx(){
    xbindkeys -f $HOME/.xbindkeysrc;
    xbindkeys -p;
    xbindkeys -s
}; xx

function xx(){
    killall xbindkeys;
    xbindkeys
    xbindkeys -f $HOME/.xbindkeysrc;
    xbindkeys -s
}; xx


function xx(){
    killall xbindkeys;
    xbindkeys;
    xbindkeys -f $HOME/.xbindkeysrc;
    xbindkeys -s
}; xx

function xx(){
    killall xbindkeys;
    xbindkeys -f $HOME/.xbindkeysrc.scm;
    xbindkeys -s
}; xx


xbindkeys --defaults > $HOME/.xbindkeysrc
[jm@jm-pc Public]$ xbindkeys --help
xbindkeys 1.8.6 by Philippe Brochard
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