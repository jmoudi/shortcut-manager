import {Watcher} from '@Modules/fs';
import {log} from '@Modules/logger';
import {default as execa} from 'execa';

export function reloadXbindkeys(path: string){
    return execa(`
    function xx(){
        local configfile="$1";
        killall xbindkeys;
        xbindkeys -v -fg "$configfile";
        xbindkeys -s;
    }; xx
    `, [path]) //`./config/xb-main.scm`
}
export function startWatch(){
    const watcher = new Watcher({
        awaitWriteFinish: true
    });
    watcher.add([
        `./config/xb-*.*`
    ]);
    watcher.on('change', (p) => {
        log(`change`, p);
        reloadXbindkeys(p);
    })
}
startWatch();