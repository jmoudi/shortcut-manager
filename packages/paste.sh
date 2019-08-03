#!/usr/bin/env

function dopaste(){
    xclip -out -selection clipboard
    exit;
};
dopaste;
