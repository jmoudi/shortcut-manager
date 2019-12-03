import { config } from '@/constants';
import {Yaml} from '@encoding/yaml';
import {readFile} from '@std/fs';

 
export const loadConfig = async (opts) => {
    const ma = await readFile(config.keymap, 'utf-8'); //.then(s => s.match(re));
    return Yaml.parse(ma)
    
 /*    const rr = [...ma.match(/(\w{0,4}_[\w]+)\s*(0?x?[0-9a-f]+)\s*[\/]{2}\s*([^$]+)/i)].slice(1,5);
    const yy = [...ma.matchAll(re)].slice(1,10); */
/*     for (const [k,v] of rr){
        logger.info(`k` , k, v);

    } 
    logger.info(`m` , a.length,  );
     console.table(a);
    return a*/
 }