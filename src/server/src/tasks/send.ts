import {exec, execFile,spawn} from 'child_process';
import {default as execa} from 'execa';

import {} from '../utils/clipboard';
import {read as readFromClipboard, write as writeToClipboard} from 'clipboardy';

export async function paste(text: string){
    const newContent = `123aaaaabc`;
    console.time("1");
    const oldContent = await readFromClipboard();
    await writeToClipboard(newContent);
    //console.log(`oldContent`, oldContent);
    const res = await execa(`./lib/xsendkey`, [`Control+v`]);
    await writeToClipboard(oldContent);
    console.timeEnd("1");
    //console.log(`res`, res);
    //execFile(`./lib/xsendkey`, [`Control+v`]);
    //spawn(`xdotool`, [`key`, `ctrl+v`]);
    //return exec(`bash /home/jm/Projects/Apps/BashScripts/src/xdotool/xclip_run.sh "${text}"`)
    //return execFile(`/home/jm/Projects/Apps/BashScripts/src/xdotool/xclip_run.sh`, [`ooo`]) 
} 


 