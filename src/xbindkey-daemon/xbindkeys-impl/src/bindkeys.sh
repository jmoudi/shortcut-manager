
#killall -v --wait -- 'xbindkeys';
 # --file-guile doesn't work

killall -v --wait -- 'xbindkeys';
function bind_guile(){
    #killall -v -- 'xbindkeys';
    xbindkeys -v -n -fg '/home/jm/Projects/Apps/HotkeyManager/config/conf1.scm';
    #xbindkeys --show;
}; 
bind_guile
 #xbindkeys --show
