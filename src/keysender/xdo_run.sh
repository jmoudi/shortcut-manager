#!/bin/bash
echo "Running..."
function xd(){
    # get browser windows
    local WID=$(xdotool search --desktop 0 --class ".*irefox.*" | head -1)
    echo "$WID"
    xdotool windowactivate --sync $WID 
    xdotool key --clearmodifiers ctrl+l
    xdotool type "dsfsfsf"

}; xd

 
function writeToClipboard(){
    local input="$1"
    echo $input | xclip -sel clip
}; 
#writeToClipboard "aaaaa"; xclip -o -selection clipboard
