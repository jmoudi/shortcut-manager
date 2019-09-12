 #!/bin/bash

function reload_all(){
    local configfile="$1";
    local pid=$(pidof xbindkeys);
    if [[ -n $pid ]]; then echo "FFFF FOUND";
    local proc=$(killall xbindkeys); # 0 = process killed
    #if [[ $proc -ne 0 ]]
    echo "configfile $configfile";
    #xbindkeys -v -fg "$configfile";
    #xbindkeys -v -fg $configfile

    local res=$(xbindkeys -v -fg $configfile);
    echo "RES $res";
    #local res=$(xbindkeys -v -fg $configfile);
    xbindkeys -s;
};

cmd="$1";
args="$2";

function readArgs(){
    echo "cmd args $cmd $args"
    case $cmd in
        reload ) echo "reload"; reload_all $args ;;
        *) echo "MSG";;
    esac;
    echo "READ FINSIHED $cmd $args"
}
readArgs


function readArgs1(){
    #echo "FuncName: $0   NrOfArgs: $#    All Args: $*"
    local matching_pattern=0
    local cmd="$1";
    local args="$2";
    shift

    while [[ "$1" =~ ^- && ! "$1" == "--" ]]; do  #while (( "$#" )); do echo "ARG: $1"
        case "$1" in
            -V | --version )
                echo $version
                ;;
            -t | --types)
                shift
                matching_pattern=$(create_filetype_pattern "$1");
                ;;
            -s | --separator)
                shift
                separator="$1"
                ;;
            *)
                echo "MSG"
                ;;
        esac
        shift
    done
    if [[ "$1" == '--' ]]; then shift; fi

    #PATTERN: $matching_pattern
    #echo "target_dir: $target_dir   ";
    find $target_dir -regextype "posix-extended" -type f -iregex $matching_pattern | cat
};