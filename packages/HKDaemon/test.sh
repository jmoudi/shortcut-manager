
lsof

function getroot(){
    local propp=$(xprop -root | rg 'WM_CLASS'); 
    propp > ./testoutput
}

function paste1(){
    #$(echo "aaa" | xclip -i -selection clipboard)
    local old=$(xclip -o -selection 'clipboard');
    echo "OLD CONTENTS: $old";
    local new="oooo"
    printf $new | xclip -i -selection 'clipboard';
    #echo "NEW CONTENTS: $(xclip -o -selection clipboard)";
    #sleep 0.1;
    ./lib/sendkeys/xsendkey 'Control+v'
    #xdotool type "$(xclip -o -selection clipboard)";
    printf $old | xclip -i -selection 'clipboard';
}; paste1 