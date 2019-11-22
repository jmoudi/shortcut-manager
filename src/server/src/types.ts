import {default as ioHook} from 'iohook';

export interface IOHookEvent {
    type: string
    keychar?: number
    keycode?: number
    rawcode?: number
    button?: number
    clicks?: number
    x?: number
    y?: number
  }
  export interface KeyboardEvent {
    altKey: boolean;
    ctrlKey: boolean;
    metaKey: boolean;
    shiftKey: boolean;
  }
  export interface KeyEventDetails extends IOHookEvent,KeyboardEvent{}
  export  interface IoHookInit {
    logging?: boolean;
  }
  //type KeyEnum = { [code:string]: number };
  export  interface KeyEnum { 
    [code:string]: number 
  };
 


  export  enum Evt {
  keypress = 'keypress',
  keydown = 'keydown',
  keyup = 'keyup',
  mouseclick = 'mouseclick',
  mousewheel = 'mousewheel',
  mousemove = 'mousemove',
  mousedrag = 'mousedrag'
}
export  type KeyCode = number;
export  interface KeyMessage {
  keycode: KeyCode;
  rawcode: KeyCode;
  type: Evt;
  altKey: boolean;
  shiftKey: boolean;
  ctrlKey: boolean;
  metaKey: boolean;
}
 


export type IOHook = typeof ioHook;