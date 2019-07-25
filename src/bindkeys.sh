/home/jm/Projects/Apps/HotkeyManager/config/conf1.scm
function bind_guile(){
    killall -v --wait -- 'xbindkeys';
    xbindkeys -v --geometry --file-guile=/home/jm/Projects/Apps/HotkeyManager/config/conf1.scm #='./config/conf1.scm'
    xbindkeys --show;
}; 
 bind_guile

function bind_conf(){
    killall xbindkeys;
    xbindkeys -v -f ./xbindkeys1.conf;
    xbindkeys -s;
}; 
#bind_conf

