import { Hotkey } from './hotkey';
import { CachedKey } from './cached-key';




  
export class HotkeyRegistry {
  cachedKeys: Map<number, CachedKey>;
  hotkeys: Map<number, Hotkey>;

  constructor(){
    this.initCache();
    this.initHotkeys();
  }
  initCache(){
    this.cachedKeys = new Map<number, CachedKey>();
  }
  initHotkeys(){
    this.hotkeys = new Map<number, Hotkey>();
  }
  findByCode(keycode: number){
    const this.cachedKeys.get(keycode);
  }

  
/*   addCodes(init: KeyEnum){
    for (const [k,v] of Object.entries(init)){
      this._code.set(v,k);
    }
  }
  getByCode(code:number){
    return this._code.get(code);
  } */

  

  getAll(){
    return Array.from(this.hotkeys.entries());
  }

  
}

 
 