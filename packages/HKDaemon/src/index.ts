export * from "./watch";

import {FSWatcher, Stats} from '@std/fs'

/* 
class LW extends FSWatcher {
    options = {
        //cwd: path.resolve(process.cwd(), `..`, ),
        alwaysStat: true,
        depth: 10,
        //atomic: true,
        awaitWriteFinish: true
    }
} */

const startWatching = async () => {
    const watcher = new FSWatcher({
        //cwd: path.resolve(process.cwd(), `..`, ),
        alwaysStat: true,
        depth: 10,
        //atomic: true,
        awaitWriteFinish: true
    });
    watcher.add([
        './packages/XSender/sendFake.c'
    ])
    watcher.on('error', err => console.log(err));
    watcher.on('change', (path, stats) => console.log(path, stats));
    
};
startWatching();
 
 