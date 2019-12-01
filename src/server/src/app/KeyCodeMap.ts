import { CachedKey } from '@/app/CachedKey';
import { state, normalizeKey } from '../tasks/load-keycodes';
export class KeyCodeMap {
    codes: Map<number, CachedKey>;
    keys: Map<string, CachedKey>;
    constructor() {
        this.codes = new Map<number, CachedKey>();
        this.keys = new Map<string, CachedKey>();
    }
    register(c: CachedKey) {
        this.setCode(c.code, c);
        this.setAlias(c.alias[0], c);
        //for (const alias of c.alias){
        //}
        if (state.debug === true) {
            console.log(``, c.code, c.alias);
        }
        return this;
    }
    setCode(code: number, c: CachedKey) {
        this.codes.set(code, c);
    }
    setAlias(alias: string, c: CachedKey) {
        //unnormalized
        this.keys.set(alias, c);
        //normalized
        this.keys.set(normalizeKey(alias), c);
        const isModifier = /(Shift|Co?n?tro?l|Alt|Meta)/.test(alias);
        if (isModifier) {
            const [name, end] = alias.split(`_`);
            if (end === 'L') {
                this.keys.set(name, c);
                this.keys.set(normalizeKey(name), c);
            }
        }
    }
    getCode(code: number | string) {
        code = typeof code === 'number' ? code : parseInt(code);
        return this.codes.get(code);
    }
    getAlias(alias: string) {
        return this.keys.get(alias);
    }
}
