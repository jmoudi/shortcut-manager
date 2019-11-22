#!/bin/bash

echo "Reloading daemon at: $(date +"%H:%M:%S-%N")";

function start(){
    echo "Runnng with Args: $@";
    #killall -v -HUP 'xbindkeys'
    killall -HUP xbindkeys
    local config="$1";
    echo "config: $config";
    if [[ ! -e "$config" ]]; then
        echo "doesnt exist: ${config}";
    elif [[ "$config" =~ ".scm" ]]; then
        echo "Loading scheme config: ${config}";
        xbindkeys -v -n -fg $config;
    elif [[ $config =~ ".conf" ]]; then
        echo "Loading regular config: ${config}";
        #xbindkeys -v -n -f "${config}";
    fi
    xbindkeys --show;
}; 
start $@


function check(){
    if [[ "$1" =~ ".scm$" ]]; then
        echo "Loading scheme config"
    else
        echo "Loading regular config"
    fi
};
#check "./src/config/.xbindkeysrc.scm"
#check "dfsf.scm"