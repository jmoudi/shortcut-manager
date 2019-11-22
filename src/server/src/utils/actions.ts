import { Hotkey } from '@/utils/hotkey';
import { KeyMap } from '@/utils/cached-key';
import { Action } from 'rxjs/internal/scheduler/Action';

declare const actions: KeyMap;
export const 

export class ActionMap {
  map: Map<string, Function>
  constructor(){
    this.map = new Map<string, Function>();
  }
  getAction = (shortcut: Hotkey) => {

    const action = actions.get(shortcut.command);
    return action
  }
}