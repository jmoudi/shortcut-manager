
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