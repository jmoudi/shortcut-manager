import { spawn, execFile } from 'child_process';
import { default as execa } from 'execa';
import { } from '@Modules/string/src/path';
import { resolve } from 'path';

const BINPATH = "./src/autohotkey/AutoHotkey.exe";

class AutoHotkey {
    getArgs(params){
        return ["./src/autohotkey/assign.ahk", "+c,paste,abbbbb;!d,paste,kkkkk"]
    }
}
const autoHotkey = new AutoHotkey();

export async function execute<T = any>(params){
    //const args = ["./src/autohotkey/assign.ahk", ...params];
    const bin = await execa(resolve(BINPATH), autoHotkey.getArgs(params));
    return bin;
}
export function execute2<T = any>(params){
    const args = ["../src/autohotkey/assign.ahk", ...params];
    const bin = execFile(BINPATH, args);
    return bin;
}