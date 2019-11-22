
import { default as ioHook } from 'iohook';
import { IOHook, IoHookInit, IOHookEvent, KeyEventDetails } from './types';
import {conformsTo} from '@std/fp'
import { normalizeKey } from './utils/string-utils';


interface IOConfig{

}
export class IOHookApp {
  ioHook: IOHook
  //keymap: KeyMap;
  //hotkeys: HotkeyRegistry;
  constructor(keymap?: IOConfig){
    //this.keymap = keymap;
    this.init();
  }
  init(){
    this.ioHook = ioHook;
  }
  configure(){
    this.ioHook.useRawcode(true);
    this.ioHook.disableClickPropagation();
    //ioHook.setDebug(true); // Uncomment this line for see all debug information from iohook
  }
/*
  bindAll(keys: Hotkey[]){
    keys.forEach(this.bindKey)
  }
 
  bindKey(shortcut: Hotkey){
    const convertToIoHook = (shortcut: Hotkey) => {
      return shortcut.key.map((k: string) => {
        const code = this.keymap.get(normalizeKey(k));
        return code - 8
      })
    }
    this.ioHook.registerShortcut(convertToIoHook(shortcut), getAction(shortcut))
    
  } */

  /* onPressed(details: KeyEventDetails){
    const reg = this.hotkeys.findByCode(details.keycode);
    if (reg){
      conformsTo(reg.modifiers, {
          altKey: details.altKey,
          ctrlKey: details.ctrlKey,
          shiftKey: details.shiftKey,
          metaKey: details.metaKey
        })
    }
    
    this.hotkeys
  } */
}




/* 
function logKeypress(key) {
  console.log(key, key.keycode, key.rawcode, `Key: `, String.fromCharCode(key.keychar));
}
export function register(keys: string[], action: Function) {
  console.log(`Registering:`, keys, action); //key, key.keycode, key.rawcode, `Key: `, String.fromCharCode(key.keychar));

  ioHook.registerShortcut(
    keys.map(k => KeyCodes[toUpper(k)]),
    action
  );
} */

 

 


