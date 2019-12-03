
import { default as ioHook } from 'iohook';
import { IOHook, IoHookInit, IOHookEvent, KeyEventDetails } from '../types';
import {conformsTo,reduce} from '@std/fp'
import { KeyCodeMap } from '@/app/KeyCodeMap';



interface Shortcut {
  id: number;
  callback: Function;
  releaseCallback?: Function;
}
interface IOHookStatus {
  active: boolean;
  shortcuts: Shortcut[]
}
export interface IOHookAppConfig{
  rawCode?: boolean;
  disableClickPropagation?: boolean;
  debug?: boolean;
  keymap?: KeyCodeMap;
}
export class IOHookApp {
  ioHook: IOHook
  keymap: KeyCodeMap;
  config: IOHookAppConfig;
  //hotkeys: HotkeyRegistry;
  constructor(config?: Partial<IOHookAppConfig>){
    //this.keymap = keymap;
    this.init();
    this.setConfig(config);
    this.keymap = config.keymap;
    
  }
  init(){
    this.ioHook = ioHook;
  }
  setConfig(config: Partial<IOHookAppConfig> = {}){
    this.config = {debug: false};
  }
  configure(opts: Partial<IOHookAppConfig>){
    this.ioHook.useRawcode(true);
    this.ioHook.disableClickPropagation();
    //ioHook.setDebug(true); // Uncomment this line for see all debug information from iohook
  }

  register(keys: string[], action: Action){
    if (!this.keymap){
      throw 'no keymap'
    }
    const reduceToCodes = (codes: number[], k: string) => {
      const al = this.keymap.getAlias(k);
      if (al){ 
        // '- 8' due to ioHook having wrong keysyms
        codes.push(al.code - 8); 
      }
      return codes
    }
    const convertedCodes = reduce(keys, reduceToCodes, []);
    const id = this.ioHook.registerShortcut(convertedCodes, action);
    return id;
    //console.log(keys, convertedCodes, status)
  }

  start(){
    this.ioHook.start(this.config.debug);
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

 

 


