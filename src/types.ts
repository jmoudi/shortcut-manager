



type XFunc = 
| 'xbindkey-function2' 
| 'xbindkey-function' 
| 'debug';

type ArgFun = <T = any>(...args: T[]) => void;
type SchemeCode = string;

interface ArgsT {
    name: XFunc,
    fn: Function
}
interface Functaa2 {
    
    //name: 'xbindkey-function2',
    (name: 'xbindkey-function2', fn: (hotkey: string, func: string) => void);
    (name: 'debug', fn: (hotkey: string, func: number) => number);
 }
 interface Funct3 {
    
    //name: 'xbindkey-function2',
    (name: XFunc, fn: Function): SchemeCode;
    (name: 'xbindkey-function2', fn: (hotkey: string, func: string) => string): SchemeCode;
    (name: 'xbindkey-function', fn: (hotkey: string, func: string) => string): SchemeCode;
    (name: 'debug', fn: (hotkey: string, func: number) => number): SchemeCode;
 };
 type Funct4 = {
    
    //name: 'xbindkey-function2',
    (name: XFunc, fn: Function): SchemeCode;
    (name: 'xbindkey-function2', fn: (hotkey: string, func: string) => string): SchemeCode;
    (name: 'xbindkey-function', fn: (hotkey: string, func: string) => string): SchemeCode;
    (name: 'debug', fn: (hotkey: string, func: number) => number): SchemeCode;
 }
interface FJJ extends Functaa2 {
    (name: XFunc, fn: Function): SchemeCode
}




const bb: Funct3 = (name: XFunc, fn: Function): SchemeCode => {
    return `name`
    
}
const creategt = (name: XFunc, fn: ArgFun): SchemeCode => {
    return `name`
    
};
//const ii: Funct3 = creategt('', ());
const bb3: Funct3 = (name: XFunc, fn: Function) => {
    return `name`
    
};
bb3('debug', (d, g) => 2);
bb3('xbindkey-function', (d, g) => 2);


const bb4: Funct3 = (name, fn) => {
    return `name`
    
};
bb3
const numag = bb3("xbindkey-function", (h,k) => 2);

const numg = bb("debug", (h,k) => 2);


const cc: Functaa2 = <T extends ArgsT>(name: T., fn: Function): SchemeCode => {
    return `name`
    
}
const numfg = cc("debug", (h,k) => 2);





interface Funct1 {
    
    //name: 'xbindkey-function2',
    //(name: XFunc, fn: Function): SchemeCode;
    (name: 'xbindkey-function2', fn: (hotkey: string, func: string) => string): SchemeCode;
    (name: 'xbindkey-function', fn: (hotkey: string, func: string) => string): SchemeCode;
    (name: 'debug', fn: (hotkey: string, func: number, oo: string) => number): SchemeCode;
 };
 const bb3dy: Funct1 = (name, fn) => {
     const t = fn();
    return `name`
    
};
const uu = ('f', 'dsf', 'fds') => 2
bb3dy('debug', (f,o,i) => 2);
const y = bb3dy('debug', (d, g) => 2);
bb3dy('xbindkey-function', (d, g) => 2);


const creategts = (name: XFunc, fn: ArgFun): SchemeCode => {
    const rr: Funct1 = (name, fn) => ``;
    return `name`
    
};
const i = creategts('debug', () => {});
//const ii: Funct3 = creategt('', ());
const bb3d: Funct3 = (name: XFunc, fn: Function) => {
    return `name`
    
};
bb3d('debug', (d, g) => 2);
bb3d('xbindkey-function', (d, g) => 2);