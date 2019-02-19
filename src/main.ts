import {AutoHotkey,KeyMap} from '@/core';
import { log } from '@/util';
import { KEYBINDINGS } from '@/constants';

import { Hotkey } from '@/types';
import { json5, readFile } from '@Modules/filesystem';
import { resolve,join } from 'path';

export function convertToAhk(keymap: KeyMap){

    const str = Array.from(keymap.values()).map((hotkey: Hotkey) => `${hotkey.key},${hotkey.command},${hotkey.value}`).join(";");
    return str;
}

async function assign(keymap: KeyMap, hotkeys){
    //const keymap = new KeyMap();
    for (const hotkey of hotkeys){
        keymap.set(hotkey.key, hotkey);
    }
    return keymap;
};
async function main(){
    const keymap = new KeyMap();
    const autoHotkey = new AutoHotkey();
    
    const china2 = [
        { key: "!c", value: "罗马", command: "enter" },
        { key: "!x", value: "罗马", command: "find" },
    ];

    const srcPath = resolve(KEYBINDINGS, "china.json");
    const content = await readFile(srcPath, "utf8");
    log("srcPath", srcPath, content);
    const china = json5.parse(content);
    assign(keymap, china);
    log("keymap", keymap, china);
    const str = convertToAhk(keymap);
    log("Stringified:", str);
    const exec = autoHotkey.run(str);
    //log("exec", exec);
}
main();