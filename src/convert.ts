import { Registry } from '@Modules/core/src/classes';
import { Hotkey } from '@/types';
import { log } from '@/util';

enum Separator {

}
const toAHK = ({key,value,command}: Hotkey) => `${key}${command}${value}`;

export class KeyMap extends Map<string, Hotkey> {

    getAll(){
        const output: string[] = [];
        for (const [k,v] of this.entries()){
            output.push(toAHK(v));
        }
        return output.join(";");
    }
}
const keymap = new KeyMap();
 
export function convert(hotkeys: Hotkey[]){
    for (const hotkey of hotkeys){ log("h", hotkey)
        keymap.set(hotkey.key, {...hotkey});
    }
    const str = keymap.getAll();
    return str;
}

//process.stdout.write(keyList);