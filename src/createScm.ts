 
const keys = [
    {key:"shift a", cmd: ""}
]

interface SchemeFunctionInit {

    name?: string;
}
const createSchemeFunction = ({}) => {

}
interface ExecTemplateInit {

    name?: string;
}
const createSchemeFunction = ({}) => {

}
interface Functaa {
    
        //name: 'xbindkey-function2',
        (hotkey: string, func: string): void;
        (hotkey: string, func: number): number;
    
}
const aa: Functaa = (hotkey, func) => 2;
const num = aa('fds', 'df')

interface Functaa {
    
    //name: 'xbindkey-function2',
    (hotkey: string, func: string): void;
    (hotkey: string, func: number): number;

}
const aa: Functaa = (hotkey, func) => 2;
const num = aa('fds', 'df')


export namespace XbindKeys {
    // "call" can either be an executable .bin path, a globally available command,
    // or a scheme lambda expression
    export type CommandOrLambda = string;
    export type Exec = {key: string, call: CommandOrLambda };
    export type Func = {
        name: 'xbindkey-function',
        (hotkey: string, func: string): void;
    }
    const j: Func = ('fd','fd')
    export interface Funct {
        Func,
        (
            name: 'xbindkey-function2',
            (hotkey: string, func: string): void;
        )
    }
    /* export interface Functions {
        export type Func = {
            name: 'xbindkey-function',
            (hotkey: string, func: string): void;
        }
    } 
    type a = Functions.Func */
    export enum aa { 
        Functions
    }
    export type Func2 = {
        name: 'xbindkey-function',
        (hotkey: string, func: string): void;
    }
    //export type XbindkeysFunction = (hotkey, func:) =>  
}

// /type ReturnType<T extends (...args: any) => any> = T extends (...args: any) => infer R ? R : any;

/* Parameters
const a: XbindKeys.Func; a()
type ss = ReturnType */
const a = {...XbindKeys}; 
const createSchemeExec = (funcname: string, fn: T) => {
    XbindKeys.Functions.Func
}
const xbindkeyFunction = ({key, call}:XbindKeys.Exec) => {
    createF({name:'xbindkey-function', })
    const keyArg = key;
    const funcArg = call;
    createF('xbindkey-function', );
    const cr = (...args:any[]) => createF('xbindkey-function', (...args));
    const tpl = `(xbindkey-function '(shift a)
    (lambda ()
      (display "Hello from Scheme!")
      (newline)))`
};
xbindkeyFunction({
    key: 'shift a',
    call: 
})
const createExecTemplate =
const createXbindkeysFunctionTemplate = () => 
{

const tpl = `(xbindkey-function '(shift a)
		   (lambda ()
		     (display "Hello from Scheme!")
             (newline)))`
return tpl
             
}