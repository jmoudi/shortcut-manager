
import {log} from '@Modules/logger';
import {default as execa} from 'execa';
import {spawn} from 'child_process';

import {resolve} from 'path';

export function reloadXbindkeys1(path: string){
    const abs = resolve(path);
    log(`abs`, abs);
    const xbp = execa(`xbindkeys`, [`-v`, `-fg`, abs ]);
    xbp.stdout.on(`data`, d => console.log(d))
    xbp.stdin.on(`data`, d => console.log(`ssss`, d))
    xbp.stderr.on(`data`, d => console.warn(d))
    .on(`data`, (d) => log(`d`,d))
    //return execa(`./src/sh/xbindkeys-ipc.sh`, [`reload`, `'${abs}'`]) //`./config/xb-main.scm`
}
export function reloadXbindkeys(path: string){
    const abs = resolve(path);
    log(`abs`, abs);
    const xbp = spawn(`xbindkeys`, [`-v`, `-fg`, abs ]);
    xbp.on('error', (err) => {
        console.log('Failed to start subprocess.', err);
      });
    xbp.stdout.on(`data`, d => console.log(d))
    xbp.stdin.on(`data`, d => console.log(`ssss`, d))
    xbp.stderr.on(`data`, d => console.warn(d))
    xbp.on(`data`, d => console.log(d))
    log(`x`,xbp)
     //return execa(`./src/sh/xbindkeys-ipc.sh`, [`reload`, `'${abs}'`]) //`./config/xb-main.scm`
}