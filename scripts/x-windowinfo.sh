 
xprop -f 'WM_CLASS(STRING)'


xcutsel copy



function wxx(){
exec xprop -notype \
  -f WM_NAME        8s ':\n  title =\? $0\n' \
  -f WM_CLASS       8s ':\n  appName =\? $0\n  className =\? $1\n' \
  -f WM_WINDOW_ROLE 8s ':\n  stringProperty "WM_WINDOW_ROLE" =\? $0\n' \
  WM_NAME WM_CLASS WM_WINDOW_ROLE \
  ${1+"$@"}
}
wxx

xprop -spy


WM_PROTOCOLS(ATOM): protocols  WM_DELETE_WINDOW, WM_TAKE_FOCUS, _NET_WM_PING, 
_NET_WM_SYNC_REQUEST
WM_CLASS(STRING) = "Navigator", "Firefox"
xprop | rg 'WM_WINDOW_ROLE(STRING) = '

xprop -notype WM_WINDOW_ROLE | rg '= "(.+)"' -o -r '$1';


xprop -notype -f WM_WINDOW_ROLE 8s ':\n  stringProperty "WM_WINDOW_ROLE" =\? 
$0\n' WM_WINDOW_ROLE

"browser"


xprop -notype -f WM_WINDOW_ROLE 8s '$0' WM_WINDOW_ROLE
xprop -notype -f WM_WINDOW_ROLE 8s ':\n  stringProperty "WM_WINDOW_ROLE" =\? 
$0\n'


xdotool search --class ".*irefox.*" 

 xdotool search --name ".*irefox.*" 


 