'use strict';
const fs = require('fs');
//module.exports = require('./dist/index.js');
//const  = require('./dist/index.js');
const log = console.log;

const test = [
    { key: "alt+c", input: "aaa", cmd: "paste" },
    { key: "alt+x", input: "aaa", cmd: "find" },
];

class AHK {
    constructor(){
        this.lineSeparator = "\n";
    }

    toString(){
        
    }
}
function AHKLine(hotkey, method, input){
    return `${hotkey}::${method}(${input})`

}
function convertToAHK(keyConfig, ){
    const schema = 
    const hotkey = isStr(keyConfig) ? keyConfig : c;

    }
}


function toJSON(input){
    return JSON.stringify(input).replace(/(")/g, '\"\"');
}

function main(){
    
    process.stdout.write(keyList);
}
main();

