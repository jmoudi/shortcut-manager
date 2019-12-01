 

import {execa} from '@std/subprocess';
import {writeFile} from '@std/fs';
import {uniq,memoize,reduce} from '@std/fp';
import { CachedKey } from '@/app/CachedKey';
import { flatten, Task, task,fromIO,getSemigroup,getMonoid,ap, of } from 'fp-ts/lib/Task';
import { TaskEither } from 'fp-ts/lib/TaskEither';
import { reader } from 'fp-ts/lib/Reader';

import { array } from 'fp-ts/lib/Array';
import { pipe } from 'fp-ts/lib/pipeable';

import { taskify, fold as t  } from 'fp-ts/lib/TaskEither'
import { Option, none, some, fromNullable, map, chain, isSome } from 'fp-ts/lib/Option';
import { lookup } from 'fp-ts/lib/Array';
import { toLowerCase } from '@/utils';
import { KeyCodeMap } from '../app/KeyCodeMap';


/**
 * get 'xmodmap -pke' keysym table
 */
export async function getKeySymTable(){
    const res = await execa(`xmodmap`, [`-pke`]);
    return res.stdout.split(`\n`)
}

//export const parseLine = async (inpline:string): Promise<CachedKey|null>  => {

const getKeyCode = (inp: string) => {
    const code = /(\d+)/.exec(inp)[1];
    return parseInt(code);
}
const getKeyAlias = (inp: string) => {
    const alias = pipe(
        inp,
        (l: string) => l.trim(),
        (l: string) => l.split(/\s/),
        uniq
        //.split(/\s/)
    );
    return alias
}
/**
 * parse 'xmodmap -pke' keysym table line
 * keycode  38 = a A a A
 */
export const parseLine = (inpline: string) => {

//export async function parseLine (inpline:string): Promise<CachedKey|null> {
    // split line output by xmodmap -pke
    const line = inpline.split(`=`);
    const code = getKeyCode(line[0]);
    const alias = getKeyAlias(line[1]);
    let ck: CachedKey|null; 
    const noMatch = (!code || alias.length === 0);
    if (noMatch){
        return null //ck = null
    } 

    ck = new CachedKey({ 
        code: code, 
        alias: alias
    });
    return ck
}

export const state = {
    debug: false
}

export const normalizeKey = (k: string) => toLowerCase(k);

export const parseModifier = (k: string) => {
    const [name, end] = k.split(`_`);
    const re = /(Shift|Co?n?tro?l|Alt|Meta)_(L|R)/i;
    //const [orig, ]
    
}

//Control_L if (endsWith)
const readLineTask = (l: string) => async () => parseLine(l) 

// temporary hack
// TODO: change to monad
export async function getKeyCodeMap(){
    const lines = await getKeySymTable();
    const parser = array.traverse(task);
    const parse = parser(lines, readLineTask);
    const res = await parse();
    const outp = res
    .filter(c => Boolean(c.code))
    //
    return outp
}

export async function createKeyCodeMap(){
    const lines = await getKeySymTable();
    const keyMapReducer = (keymap: KeyCodeMap, line: string) => {
        const cachedKey = parseLine(line);
        if (cachedKey.alias[0] !== ''){
            keymap.register(cachedKey);
        }
        return keymap
    }
    const res = reduce(lines, keyMapReducer, new KeyCodeMap());
    return res
}