 

import {execa} from '@std/subprocess';
import {writeFile} from '@std/fs';
import {uniq,memoize} from '@std/fp';
import { CachedKey } from '@/utils/cached-key';
import { flatten, Task, task,fromIO,getSemigroup,getMonoid,ap, of } from 'fp-ts/lib/Task';
import { TaskEither } from 'fp-ts/lib/TaskEither';
import { reader } from 'fp-ts/lib/Reader';

import { array } from 'fp-ts/lib/Array';
import { pipe } from 'fp-ts/lib/pipeable';

import { taskify, fold as t  } from 'fp-ts/lib/TaskEither'
import { Option, none, some, fromNullable, map, chain, isSome } from 'fp-ts/lib/Option';
import { lookup } from 'fp-ts/lib/Array';

/**
 * get 'xmodmap -pke' keysym table
 */
export async function getKeySymTable(){
    const res = await execa(`xmodmap`, [`-pke`]); 
    return res.stdout
}

//export const parseLine = async (inpline:string): Promise<CachedKey|null>  => {

const getCode = () => /(\d+)/.exec(line[0])[1];
/**
 * parse 'xmodmap -pke' keysym table line
 * keycode  38 = a A a A
 */
export const parseLine = async (inpline: string) => {

//export async function parseLine (inpline:string): Promise<CachedKey|null> {
    // split line output by xmodmap -pke
    const line = inpline.split(`=`);
    const code = /(\d+)/.exec(line[0])[1];
    const alias = pipe(
        line[1],
        (l: string) => l.trim(),
        (l: string) => l.split(/\s/),
        uniq
        //.split(/\s/)
    );
    let ck: CachedKey|null; 
    const noMatch = (!code || alias.length === 0);
    if (noMatch){
        return null //ck = null
    } 

    ck = new CachedKey({ 
            code: parseInt(code), 
            alias: alias
    });
    return ck
}

 
const readLineTask = (l: string) => async () => parseLine(l) 
 
export async function getKeyCodeMap(keymap: Map<number|string, CachedKey>){
    const lines = await getKeySymTable();
    const linesa = lines.split(`\n`);
    const parser = array.traverse(task);
    const parse = parser(linesa, readLineTask);
    const res = await parse();
    const outp = res
    .filter(c => Boolean(c.code))
    //
    return outp
}