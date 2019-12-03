#!/bin/bash


function startr(){
}


function start(){
    killall -HUP xbindkeys
    #killall -v -- 'xbindkeys';
    xbindkeys -v -n -fg '/home/jm/Projects/Apps/HotkeyManager/config/conf1.scm';
    #xbindkeys --show;
}; 
start