import {FSWatcher, Stats,pathExists} from '@std/fs'
import {Logger,log} from '@std/log';
import {execa} from '@std/subprocess';
import {fromEvent} from '@std/async';
import path from 'path';

const gcc = (args: string[]) => execa('gcc', args, {
    stdio: ['pipe', 'pipe', 'pipe'],
    timeout: 10000
});
const runCompiledFile = (src: string) => execa(src, {
    stdio: ['pipe', 'pipe', 'pipe'],
    timeout: 10000,
    env: process.env
});


const logger = new Logger();

interface FileListener {
    (path: string, stats: Stats): Promise<any>; //|void
}

const handleCFilesChanges: FileListener = async (file, stats) => {
    const dest = path.join('./packages/XSender/bin', path.parse(file).name);
    logger.info('ch', file, dest);
    const compileTask = await gcc([
        file, //'./XSender/fakeKey.c', 
        '-o', 
        dest, 
        '-lX11', '-lXtst', '-lXext'
    ]);
    //logger.info(compileTask)
    //const runTask = runFile(dest);
    //await compileTask();
    await pathExists(dest);
    //const res = await runCompiledFile(dest);return res;
/*     const res = await Promise.all([
        compileTask,
        //runTask
    ]); */
    

}

type WatchOptions = ConstructorParameters<typeof FSWatcher>[0];
const o: WatchOptions = {}
const defOpts: WatchOptions = {
    disableGlobbing: false,
    //cwd: path.resolve(process.cwd(), `..`, ),
    cwd: path.resolve(process.cwd()),
    alwaysStat: true,
    depth: 10,

    //atomic: true,
    awaitWriteFinish: true
}
class CFileWatcher extends FSWatcher {
    /* options = {
        cwd: path.resolve(process.cwd()),
        alwaysStat: true,
        depth: 10,
    
        //atomic: true,
        awaitWriteFinish: true
    } */

    constructor(){
        super(defOpts);
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
        logger.info(`onChange`, file);
        const res = await handleCFilesChanges(file, stats).catch((p) => this.handleError(p));
        logger.info(`res`, res);
        //return res
    }

}



const startWatching = async () => {
    const watcher = new CFileWatcher();
    logger.info('watcher', watcher.getWatched());
    watcher.add([
        './packages/**/sendFake.c'
    ]);
    logger.info('watcher', watcher.getWatched());

    watcher.on('error', err => watcher.handleError(err));
    watcher.on('change', (path, stats) => watcher.onChange(path, stats));
    
};
startWatching();
 
 
