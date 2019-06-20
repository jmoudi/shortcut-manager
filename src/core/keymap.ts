import { Registry } from '@Modules/core/src/classes';
import { Hotkey } from '@/types';

export class KeyMap extends Map<string, Hotkey> {

    getAll(){
        return Array.from(this.entries());
    }

    stringify(cb){
        const output: string[] = [];
        for (const [k,v] of this.entries()){
            output.push(cb(v));
        }
        return output.join(";");
    }
}