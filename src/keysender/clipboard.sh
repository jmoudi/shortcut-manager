#!/bin/bash
 
action=$1
 
if [ "$action" != "paste" ] && [ "$action" != "copy" ]
then
  echo "Invalid command"
  exit 1
fi
 
if [ "$action" == "copy" ]
then
  xclip -in -selection clipboard $file #xsel --clipboard --input 
else
  xclip -out -selection clipboard  #xsel --clipboard --output
fi