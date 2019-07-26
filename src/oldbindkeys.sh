
function bind_guile2(){
    killall -v --wait -- 'xbindkeys';
    xbindkeys -v -fg '/home/jm/Projects/Apps/HotkeyManager/config/conf1.scm';
    xbindkeys --show;
}; 
 bind_guile

function bind_conf(){
    killall xbindkeys;
    xbindkeys -v -f ./xbindkeys1.conf;
    xbindkeys -s;
}; 