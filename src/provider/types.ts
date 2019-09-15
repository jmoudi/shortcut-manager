import { isString } from 'util';

type GenFunc = (...args: any) => any;
type ReturnType1<T extends GenFunc> = T extends (...args: any) => infer R ? R : any;


type a = ReturnType<T>



interface KeyCodes {
    [code: string]: string
}
type KeyCode = keyof KeyCodes;
export interface KeyEvents {
    keys: {
        [k: string]: (e: React.KeyboardEvent<HTMLTextAreaElement>) => any
    }
}
export class Key {
    key: string;
    handler: (...init:any[]) => any;

    constructor({ key, handler }: Partial<Key>){
        if (key && handler){
            this.key = key; 
            this.handler = handler; 
        }
    }
}





interface Select extends ColumnNameQueryBuilder {
    (aliases: { 
        [alias: string]: string | Knex.Raw 
    }): QueryBuilder;
  }


type XFunc = 
| 'xbindkey-function2' 
| 'xbindkey-function' 
| 'debug';

type OO = {
    (name: XFunc, fn: (...args) => void)
};

type ArgFun = <T = any>(...args: T[]) => void;
type SchemeCode = string;
interface ScCr<T = string> {
    (name: T, fn: ArgFun): SchemeCode;
};
/* interface XF extends ScCr<XFunc> {
    (name: 'xbindkey-function2', fn: (hotkey: string, func: string) => void);
    (name: 'debug', fn: (hotkey: string, func: number) => number);
} */
type XF2 = {
    [k: string]: ScCr<XFunc>
}
enum XFNames {
    XBF = 'xbindkey-function',
    Debug = 'debug',
}
/* type CC = {
    ([XFNames.XBF]: (hotkey: string, func: string) => void)
    ([XFNames.Debug]: (hotkey: string, func: number) => number)
} */
interface CCd {
    (name: XFNames.XBF, f:(hotkey: string, func: string) => void):SchemeCode;
    (name: XFNames.Debug, f:(hotkey: string, func: number) => number):SchemeCode
}
interface P {
    (name: XFNames, f: Function):SchemeCode;
}
type iii = (name: XFNames, f: Function) => SchemeCode
const k: CCd;


interface l {
    (name: string, fn: any): any
}
const crYd: P = (name, fn) => {
    return ``
    //name, fn();
    //return `(${name} ${fn()})`
};
const resf = crYd(XFNames.Debug, () => {})
interface XF3 {
    XFNames.XBF: 
}
namespace KK {
    (name: )
}

interface XF1  {
    (name: 'xbindkey-function2', fn: (hotkey: string, func: string) => void): ScCr<XFunc>
    (name: 'debug', fn: (hotkey: string, func: number) => number): ScCr<XFunc>
} 

const crY: XF1 = (name, fn) => {
    //name, fn();
    return `(${name} ${fn()})`
};
const res = crY('xbindkey-function', ())
interface Functaa2 {
    
    //name: 'xbindkey-function2',
    (name: 'xbindkey-function2', fn: (hotkey: string, func: string) => void);
    (name: 'debug', fn: (hotkey: string, func: number) => number);
 }

const bb: Functaa2 = (name: XFunc, fn) => {
    name
}
const numg = bb("", (h,k) => 2);
