/* import {Replacer} from '@Modules/string';
console.log(Replacer) */
import {Watcher} from '@Modules/fs';
import {Stats,existsSync as exists} from 'fs';

import {log} from '@Modules/logger';
import {default as execa} from 'execa';
import {resolve} from 'path';
import{reloadXbindkeys} from './xbindkeysApi';

async function handleChange(p: string, stats?: Stats){
    log(`change`, p);
    const res = await reloadXbindkeys(p);
    log(`charesnge`, res);

}
export function startWatch(){
    log(`startWatch`, Watcher);
    const watcher = new Watcher({
        awaitWriteFinish: true
    });
    const watchPatterns = [
        `./config/xb-*.*`
    ];
    log(watchPatterns.map(p => exists(p)));
    watcher.add(watchPatterns);
    watcher.on('change', handleChange);

    log(`startedWatch`, watcher, watcher.getWatched());
}
startWatch();