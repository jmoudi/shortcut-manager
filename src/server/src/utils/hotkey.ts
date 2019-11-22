import { toLowerCase } from '@std/string';

import {conformsTo} from '@std/fp'
enum ModifierKeys {
    Alt = 'alt',
    Ctrl = 'ctrl',
    Shift = 'shift'
}
export type Modifiers = {
    altKey: boolean;
    ctrlKey: boolean;
    metaKey: boolean;
    shiftKey: boolean;
  }

const normalizeKey = (k) => toLowerCase(k);

export interface IHotkey {
    //keys: HotkeyKeys;
    key?: string[]; //IHotkey.keys;
    keys?: string;
    //[k: keyof tST ]: string;
    command: string;
    args: string[];
}
export class Hotkey {
    key: string[];
    command: string;
    args: string[];
    modifiers: Modifiers;

    constructor(init: IHotkey) {
        this.key = init["key"] || init["keys"] || init["hotkey"];
        this.command = init["command"] || init["cmd"];
        this.args = init["args"] || init["params"];
        this.parseKey(init.key);
    }

    parseKey(key: string[]){
        this.modifiers = {} as any;
        //array.traverse
        for (const str of key){
            const hasMod = Boolean(ModifierKeys[normalizeKey(str)]);
            this.modifiers[key]{
                hasMod
            }
            if (ModifierKeys[normalizeKey(str)]){
                
            }
        }
    }
}

