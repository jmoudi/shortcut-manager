
import {execa} from '@std/subprocess';
import {writeFile} from '@std/fs';
import {uniq,memoize} from '@std/fp';
import { CachedKey } from './cached-key';
import { Task, task } from 'fp-ts/lib/Task';
import { array } from 'fp-ts/lib/Array';
import { pipe } from 'fp-ts/lib/pipeable';

import { taskify, fold } from 'fp-ts/lib/TaskEither'
import { Option, none, some, fromNullable, map, chain, isSome } from 'fp-ts/lib/Option';
import { lookup } from 'fp-ts/lib/Array';

// Chord add a callback to the key that has to be executed within n ms to succeed
export class Chord {

}



export function parseKeyCode(inpline:string){
    // split line output by xmodmap -pke
    const line = inpline.split(`=`);
    const code = parseInt(/(\d+)/.exec(line[0])[1]);
    const alias = uniq(line[1].trim().split(/\s/));
    console.log(`d`, line, code, alias)
    return new CachedKey({ 
        code, 
        alias
    });
}

export const parseLine = (inpline:string) => async () => {
    // split line output by xmodmap -pke
    const line = inpline.split(`=`);
    const code = parseInt(/(\d+)/.exec(line[0])[1]);
    const alias = uniq(line[1].trim().split(/\s/));
    console.log(`d`, line, code, alias);
/*     const outp = {
        keycode: code,
        alias: alias
    }
    return outp */
    return new CachedKey({ 
        code, 
        alias
    });
}



export async function getSrc(){
    const res = await execa(`xmodmap`, [`-pke`]); 
    return res.stdout
}
//declare const execa = execa<T>
/* 
const tasks = [
    pipe(
      map(log)
    ),
    pipe(
      map(log)
    )
  ]
    parser<CachedKey>(
        lines.split(`\n`),
        (l) => parseLine(l)
    );
    const oo = pipe(
        (lines: string) => lines.split(`\n`),
        chain<string[]>(a => )
    )
    const oo1 = pipe(
        (lines: string) => lines.split(`\n`),
        chain()        //(l) => parseLine(l)
        \map(l => l)
        //map((l) => parseLine(l))
    );
  
  */
export async function parseKeys(){
    

    const keymap = new Map<number|string, CachedKey>();
    const lines = await getSrc();

    const parser = array.traverse(task);
    const linesa = lines.split(`\n`);
    const kk = parser(linesa, parseLine);
    const aa = await kk();
    aa.filter(e => Boolean(e)).forEach(c => keymap.set(c.code, c));

    console.log(`key`, keymap);
  
    const ooa = oo(lines);
    /* 
    lines.split(`\n`).reduce((map, cur) => {
        const key = parseKeyCode(cur);
        console.log(`key`, key);
        if (key && key.alias.length > 0){
            map.set(key.code, key);
            key.alias.forEach(a => map.set(a, key));
            
        }
        return keymap;
    }, keymap);
    console.log(`keym`, lines, keymap);
    return keymap */
}