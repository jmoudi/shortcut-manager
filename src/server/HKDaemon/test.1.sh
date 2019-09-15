#!/bin/bash

function paste(){
    echo "aaaaa_$(date +%F_%H.%M.%S)"
};

function writeToClipboard(){
    local input="$1"
    echo "aaa" | xclip -i -selection clipboard
};

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

function paste22(){
    #$(echo "aaa" | xclip -i -selection clipboard)
    local old=$(xclip -o);
    #echo "OLD CONTENTS: $old";
    local new="oooo"
    echo $new | xclip -i -sel 'clip';
    #echo "NEW CONTENTS: $(xclip -o -selection clipboard)";
    sleep 0.1;
    xdotool key ctrl+v
    #xdotool type "$(xclip -o -selection clipboard)";
    echo $old | xclip -i
};  


function paste2(){
    #$(echo "aaa" | xclip -i -selection clipboard)
    local old=$(xclip -o -selection clipboard);
    #echo "OLD CONTENTS: $old";
    local new="oooo"
    echo $new | xclip -i -selection clipboard;
    #echo "NEW CONTENTS: $(xclip -o -selection clipboard)";
    #sleep 0.1;
    xdotool key ctrl+v
    #xdotool type "$(xclip -o -selection clipboard)";
    echo $old | xclip -i -selection clipboard;
};  
