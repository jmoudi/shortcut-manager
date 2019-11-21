 # ~/.XCompose
 
function installcxx(){
    cd lib
    git clone "https://github.com/jarro2783/cxxopts"
    cd cxxopts
    cmake ./
    make
};
installcxx

 local xcompose='
# This file defines custom Compose sequences for Unicode characters
# Import default rules from the system Compose file:
 include "/usr/share/X11/locale/en_US.UTF-8/Compose"

# To put some stuff onto compose key strokes:
 <Multi_key> <minus> <greater> : "→" U2192 # Compose - >
 <Multi_key> <colon> <parenright> : "☺" U263A   # Compose : )
 <Multi_key> <h> <n> <k> : "hugs and kisses" # Compose h n k
 <Multi_key> <less> < p> : "< p>

" # Compose < p
'
