import {FSWatcher, Stats} from '@std/fs'
import {Logger,log} from '@std/log';
import {execa} from '@std/subprocess';
import {fromEvent} from '@std/async';

const gcc = (args: string[]) => execa('gcc', args, {
    stdio: ['inherit'],
    timeout: 10000
});
const runFile = (src: string) => execa(src, {
    stdio: ['inherit'],
    timeout: 10000
});


const logger = new Logger();

interface FileListener {
    (path: string, stats: Stats): Promise<any>; //|void
}

const runCFile: FileListener = async (file, stats) => {
    logger.info('ch', file, stats);
    const dest = './XSender/bin/fakeKey';
    const compileTask = gcc([
        file, //'./XSender/fakeKey.c', 
        '-o', 
        './XSender/bin/fakeKey', 
        '-lX11', '-lXtst', '-lXext'
    ]);
    const runTask = runFile(dest);
    const res = await Promise.all([
        compileTask,
        runTask
    ]);
    return res;

}


class CFileWatcher extends FSWatcher {
    options = {
        //cwd: path.resolve(process.cwd(), `..`, ),
        alwaysStat: true,
        depth: 5,
        //atomic: true,
        awaitWriteFinish: true
    }

    constructor(){
        super();
        this.bindHooks();
/*         this.add([
            './packages/XSender/sendFake.c'
        ]); */
    }
    bindHooks(){
        //this.on("change", this.onChange.bind(this));
        //this.on('change', (path, stats) => this.onChange(path, stats));
        //this.on("change", runCFile);
        /*     .on('all', (path) => log(`File ${path} has been added`))
    .on('add', (path) => log(`File ${path} has been added`))
    .on('unlink', (path) => log(`File ${path} has been removed`))
    .on('addDir', (path) => log(`Directory ${path} has been added`))
    .on('unlinkDir', (path) => log(`Directory ${path} has been removed`))
    .on('error', (error) => log(`Watcher error: ${error}`))
    .on('ready', () => log('Initial scan complete. Ready for changes'))
    .on('raw', (event, path, details) => {
        log('Raw event info:', event, path, details);
    }); */
    }

    handleError(p){
        logger.warn(p);
    }

    onChange: FileListener = async (file, stats) => {
        logger.info(`onChange`, file, stats);
        const res = await runCFile(file, stats).catch((p) => this.handleError(p));
        logger.info(`res`, res);
        //return res
    }

}



const startWatching = async () => {
    const watcher = new CFileWatcher();
    watcher.add([
        './packages/XSender/sendFake.c'
    ])
    watcher.on('error', err => watcher.handleError(err));
    watcher.on('change', (path, stats) => watcher.onChange(path, stats));
    
};
startWatching();
 
 
