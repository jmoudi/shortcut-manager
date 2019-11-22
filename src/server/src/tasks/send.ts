import { pipe } from 'fp-ts/lib/pipeable';
import {execa} from '@std/subprocess';
import {
    read as readFromClipboard, 
    write as writeToClipboard} from 'clipboardy';
import {execFile,execFileSync} from 'child_process';
import path from 'path';

const binp = path.resolve("../../bin/paste");

const pressCtrlV = () => execa(binp, {
    buffer: false,
    stdio: ['pipe','pipe','pipe'],
    cleanup: true,
    stripFinalNewline: true,
    timeout: 10000
}); //promisify(() => execa(binp));
const pressCtrlVStestync = () => execFileSync(binp, {
    buffer: false,
    stdio: ['pipe','pipe','pipe'],
    cleanup: true,
    stripFinalNewline: true,
    timeout: 10000
});

export async function pasteText(text: string){
    const newContent = text;
    const d = Date.now().toString();
    console.time(d);
    const oldContent = await readFromClipboard();
    console.log("oldContent", oldContent)
    await writeToClipboard(newContent);
    console.log("newContent", newContent)
    //console.log(`oldContent`, oldContent);
    //const o = await pressCtrlV();
    const o = pressCtrlVStestync();
    //o.stderr
    //const res = await execFile(`./lib/xsendkey`, [`Control+v`]);
    await writeToClipboard(oldContent);
    const aaaa = await readFromClipboard();
    console.log("finished", aaaa, o.toString())
    console.timeEnd(d);
    //console.log(`res`, res);
    //execFile(`./lib/xsendkey`, [`Control+v`]);
    //spawn(`xdotool`, [`key`, `ctrl+v`]);
    //return exec(`bash /home/jm/Projects/Apps/BashScripts/src/xdotool/xclip_run.sh "${text}"`)
    //return execFile(`/home/jm/Projects/Apps/BashScripts/src/xdotool/xclip_run.sh`, [`ooo`]) 
} 


 