
import {readFile} from '@std/fs';

import { config } from '../constants';
import { Task, task } from 'fp-ts/lib/Task';
import { array } from 'fp-ts/lib/Array';
import mm from 'micromatch';

const tagPattern = `#define.(\\w{0,4}_[\\w]+)\\b`;
const numPattern = `\\b(0?x?[0-9a-f]+)\\b`;
const commentPattern = `[\\/]{2}\\s*([^$]+)`;
export const tagMatcher = new RegExp(`${tagPattern}`, 'i');
export const numMatcher = new RegExp(`${numPattern}`, 'i');
export const commentMatcher = new RegExp(`${commentPattern}`, 'i');

export async function getAll(inp, fn) {
    logger.info(`bookmarkTree`, inp);
    const arrTask = array.traverse(task); 
    const bkmTask = arrTask(inp, fn);
    return bkmTask
  /*   const res = await bkmTask();
    //const res = flatTree.map(t => findBookmarks({url: t.url }));
    logger.log(`Res`, res);
    return res; */
}

interface Opts {
    all: RegExp[]
    some: RegExp[]
}
export const consume = async (line: string, opts: Opts) => {
    const results = [];
    let string = line;
    const doo = (string, matcher) => {
        console.log(`oldstring`, string, string.split(matcher));
        string = string.split(matcher)[1];
        console.log(`newstring`, string);
        results.push({
            val: 0, //res.slice(1),
            re: matcher
        })
    }
    const aaa = (matchers: RegExp[], fn) => {
        for (const matcher of matchers){
            const res = matcher.exec(string);
            if (res && res.length > 0){
                fn(string, matcher)
            }
    
            }
    }

    
    
    return results
}


export function createRegexp(){

    const re = new RegExp(`${tagMatcher}\\s*${numMatcher}\\s*${commentMatcher}`, 'i');
    return re
} 


const logger = console;


/* export const parse = async (inputStr: string, matchers: RegExp[]) => {
    const a = [];
    for (const str of inputStr.split(`\n`)){
        const rr = re.exec(str)
        if (rr){
            a.push(rr.slice(1));
        }
        return a
        //logger.info(`m` , ma.length, re, rr, rr[2].length);
    }
} */
export const loadC = async (fn) => {
    const re = createRegexp();
    const ma = await readFile(config.keycodes, 'utf-8'); //.then(s => s.match(re));
    return ma.split(`\n`).slice(50,200).map(fn)
    
 /*    const rr = [...ma.match(/(\w{0,4}_[\w]+)\s*(0?x?[0-9a-f]+)\s*[\/]{2}\s*([^$]+)/i)].slice(1,5);
    const yy = [...ma.matchAll(re)].slice(1,10); */
/*     for (const [k,v] of rr){
        logger.info(`k` , k, v);

    } 
    logger.info(`m` , a.length,  );
     console.table(a);
    return a*/
 }