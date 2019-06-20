import {KeyMap} from '@/core/keymap';
import {log} from '@Modules/logger';
import { Hotkey } from '@/types';
import {default as execa} from 'execa';
import {readConfig} from '@Modules/filesystem/src/core/readUtils';

function stringify(keymap, cb){
    const output: string[] = [];
    for (const [k,v] of keymap.entries()){
        output.push(cb(v));
    }
    return output.join(";");
}
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
async function load(file){
    
    const content = await readConfig<{keys: Hotkey[]}>(file);
    log("content", content);
    const keymap = new KeyMap();
    assign(keymap, content.keys);
    log("keymap", keymap);
    const str = convertToAhk(keymap);
    log("Stringified:", str);
    
    const exec = await execa(`wine`, [
        `AutoHotkeyU64.exe`,
        `src/ahk/main.ahk`,
        str
    ]);
    log("exec", exec, str);
}
load("./keybindings/china.json");
//load("korea/shoes.json");