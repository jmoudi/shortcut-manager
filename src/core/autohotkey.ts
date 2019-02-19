import { default as execa } from 'execa';
import { resolve } from 'path';
import { Hotkey } from '@/types';

const BINPATH = "./src/autohotkey/AutoHotkey.exe";

 function stringify(keymap, cb){
    const output: string[] = [];
    for (const [k,v] of keymap.entries()){
        output.push(cb(v));
    }
    return output.join(";");
}

export class AutoHotkey {
    getArgs(params){
        return ["./src/autohotkey/assign.ahk", params];
    }
    async run<T = any>(params: string){
        //const args = ["./src/autohotkey/assign.ahk", ...params];
        const bin = await execa(resolve(BINPATH), this.getArgs(params));
        return bin;
    }
    toJSON(input){
        return JSON.stringify(input).replace(/(")/g, '\"\"');
    }

    
}