import { IOHookApp } from './io';

import { fromEvent } from 'rxjs';
import ioHook from 'iohook';
import { IOHookEvent, IoHookInit, Evt } from '@/types';
import { loadConfig } from '@/tasks/load-config';
import {  /*  */pasteText } from '@/tasks/send';


import { CachedKey } from './utils/cached-key';

import { normalizeKey } from './utils/string-utils';
import { getKeyCodeMap } from './tasks/load-keycodes';

enum ModifierKeys {
    Alt = 'alt',
    Ctrl = 'ctrl',
    Shift = 'shift',
    Meta = 'meta'
}
export type Modifiers = {
    altKey: boolean;
    ctrlKey: boolean;
    metaKey: boolean;
    shiftKey: boolean;
  }


/* interface App {
    keymap: Map<number|string, CachedKey>,
    actions: Map<string, Function>
} */
 
const app = {
    ioHook,
}

export const convertToKeyCode = (k: string) => {
    const cachedKey = keycodes.get(normalizeKey(k));
    console.log(`convertToKeyCode`, k, normalizeKey(k), cachedKey)
    return cachedKey.code - 8
}
export const assignConfKeys = (k: HotkeyConfig) => {
    logger.info(`assignConfKeys`, k);
    
    const keycodes = k.key.map(str => {
        const h = ModifierKeys[normalizeKey(str)];
        convertToKeyCode(str)
    });
    logger.info(`keycodes`, keycodes)
    //app.ioHook.registerShortcut(keycodes, actions.get(k.command));
}

const logger = console;
const defaultInit: IoHookInit = { logging: false };
const debug = false;
const keycodes = new Map<string|number, CachedKey>();
const actions = new Map<string, Function>();
//const app = new IOHookApp({});

/* const registered = new Map<string, object>();
registered.set(); */

const onPressed = async <T extends IOHookEvent>(e: T) => {
    
    logger.info("eee", e);
    await pasteText("test");
};

const registerKeycodes = (c: CachedKey) => {
    logger.info(`cssd`, c);
    keycodes.set(c.code, c);
    c.alias.forEach(k => {
        keycodes.set(normalizeKey(k), c)
    });
    const tt = keycodes.get(c.alias[0]);
    const tt1 = keycodes.get(c.code);
    logger.info(`tt`, tt, tt1);
    //logger.info("e", e);
};
 

export async function init({ logging }: IoHookInit = defaultInit) {
    const keyc = await getKeyCodeMap(keycodes); 
    //logger.info(`keycdddd`, keyc, keycodes);
    keyc.forEach(c => registerKeycodes(c));
    const conf = await loadConfig({});
    logger.info(`conf`, conf);
    const confkeys: HotkeyConfig[] = conf.keys;
    confkeys.forEach(c => assignConfKeys(c));   
}
export async function run({ logging }: IoHookInit = defaultInit) {
    //app.configure();
    actions.set('enter', pasteText);
    const app = new IOHookApp();
    app.ioHook.registerShortcut([31, 56], onPressed);
    //app.ioHook.registerShortcut([31], onPressed);
    app.ioHook.start(false);
    logger.info(`ioHook`, ioHook.listeners);
    //ioHook.registerShortcut([52], onPressed);  
}
   