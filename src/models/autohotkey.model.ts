
export class AutoHotkey {

    lineSeparator: string;
    constructor(){
        this.lineSeparator = "\n";
    }

    toString(){
        
    }

    toLine(init){
        const { hotkey, method, input } = init;
        return `${hotkey}::${method}(${input})`
    }
    toJSON(input){
        return JSON.stringify(input).replace(/(")/g, '\"\"');
    }
}