import {FSWatcher, Stats} from '@std/fs'
import {Logger,log} from '@std/log';
import {execa} from '@std/subprocess';
import {fromEvent} from '@std/async';

const gcc = (src: string, args: string[]) => execa('gcc', );

const logger = new Logger();
interface FileListener {
    (path: string, stats: Stats): Promise<void>|void;
}
class CFileWatcher extends FSWatcher {
    options = {
        alwaysStat: true,
        depth: 5,
        atomic: true,
        awaitWriteFinish: true
    }

    constructor(){
        super();
        this.bindHooks();
        this.add([
            './'
        ]);
    }
    bindHooks(){
        this.on("change", this.onChange.bind(null));
    }

    onChange: FileListener = (file, stats) => {
        logger.info('ch', file, stats);
        //gcc
    }

}
const watcher = new CFileWatcher();
watcher.on("change", this.onChange);


const reload = async (path) => {
    const res = await execa(`sudo python`, [path]);
    log(`res`, res);
};
async function watch(){
    const patterns = [
        'src/py/*.py'
    ]
    const watcher = chokidar.watch(patterns);
    log(`watcher`, patterns);
    watcher.on('change', (path) => {
        log(`File ${path} has been changed`);
        reload(path);
    });
}
watch();
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