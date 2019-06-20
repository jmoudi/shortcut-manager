import {chokidar} from '@Modules/filesystem'
import {log} from '@Modules/logger';
import {default as execa} from 'execa';


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