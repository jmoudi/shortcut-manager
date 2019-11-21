

bash /home/jm/Projects/Apps/BashScripts/src/xdotool/xclip_run.sh "ooooo"
 
function writeToClipboard(){
    local input="$1"
    echo $input | xclip -sel clip
}; writeToClipboard "aaaaa"; xclip -o -selection clipboard

$(echo "aaa" | xclip -i -selection clipboard)

function paste(){
    local input="$1"
    echo $input | xclip -sel clip
}; writeToClipboard "aaaaa"

function read_into_clipboard(){
    echo "ooooo" | xclip -sel clip
};

xclip -o -sel clip

xclip -i -sel clip dssdfdsf

xclip -i -verbose

[jm@jm-pc ~]$ xterm -help
XTerm(344) usage:
    xterm [-options ...] [-e command args]
 


paste=$1
function main(){
    old=$(xclip -o -selection clipboard)
    #paste="$1";
    echo "Pasting $paste"
    # saving
    echo "$paste" | xclip -sel clip;
    #sleep 0.5
    # pasting
    #xdotool key --clearmodifiers ctrl+v
    #xclip -o -selection clipboard;
    #sleep 0.5
    echo "$old" | xclip -sel clip;
}; 
main