export interface IHotkey {
    //keys: HotkeyKeys;
    key?: string; //IHotkey.keys;
    keys?: string;
    //[k: keyof tST ]: string;
    command: string;
    args: string[];
}
export class Hotkey {
    key: string;
    command: string;
    args: string[];
    constructor(init: IHotkey) {
        this.key = init["key"] || init["keys"] || init["hotkey"];
        this.command = init["command"] || init["cmd"];
        this.args = init["args"] || init["params"];
    }
}