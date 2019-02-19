import {execute} from '@/execute';
import {convert} from '@/convert';
import { log } from '@/util';

const test = [
    { key: "!c", value: "aaa", command: "paste" },
    { key: "!x", value: "aaa", command: "find" },
];

(async () => {
    const str = convert(test);
    log("Stringified:", str);
    const exec = execute(["+c,paste,abbbbb;!d,paste,kkkkk"]);
    log("exec", exec);
})();