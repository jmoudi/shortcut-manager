
type Callback = (...args: any[]) => any;

interface ShortcutInit {
  id?: number;
  keys: string[];
  action: Callback;
}
class Shortcut {

  id: number;
  keys: string[];
  action: Callback;

  constructor({id, keys, action}:ShortcutInit){
    this.id = id || createID();
    this.keys = keys;
    this.action = action.bind(this);
  }

  match(cb){
    return this.keys.every(cb)
  }

}