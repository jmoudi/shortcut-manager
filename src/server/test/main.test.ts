import { init } from './../src/app/init';
/*  
//import {} from '../src';
import {
    loadC,
    consume,
    getAll,
    tagMatcher, numMatcher, commentMatcher
} from '../src/tasks/load'; */
import {
    loadConfig,
    getKeyCodeMap,
    createKeyCodeMap
} from '../src/tasks';
import { default as ioHook } from 'iohook';

import { IOHookApp } from '../src/app/IoHookApp';


const log = console.log

afterAll(async (done) => {

    done();
});


describe.only('app', () => {
    test('app', async () => {
        const km = await createKeyCodeMap();
        const app = new IOHookApp({keymap: km });
        app.register(['alt', 'c'], () => console.log(`tttest`));
        const res = app
        //log('', res);
        expect(res).toBeDefined();
        
    });
    test('app', async () => {

        const app = await init();
        app.register(['shift', 'c'], () => console.log(`tttest`));
        const res = app
        //log('', res);
        expect(res).toBeDefined();
        
    });
    test.only('app', async () => {

        const app = ioHook;
        app.registerShortcut([30], () => console.log(`tttest`));
        app.registerShortcut([38], () => console.log(`tttest`));

        const res = app
        //log('', res);
        expect(res).toBeDefined();
        
    });
});

describe('', () => {
/*     test('test1', async () => {
        const res = await loadC(async s => await consume(s, [tagMatcher, numMatcher, commentMatcher]));
        log('res', res);
        expect(res).toBeDefined();
        
    }); */
    
    test('getKeyCodeMap', async () => {
        const res = await createKeyCodeMap();
        //console.table(res);
        for (const [k,v] of res.keys.entries()){
            log('', k, v);
        }
        
        expect(res).toBeDefined();
        
    }); 
    test('config', async () => {
        const res = await loadConfig({});
        log('res', res);
        expect(res).toBeDefined();
        
    }); 
/*     test('test1', async () => {
        const res = await parseKeys();
        log('res', res);
        expect(res).toBeDefined();
        
    }); 
    test('test2', async () => {
        const res1 = await loadC(c => c);
        const res = await getAll(res1, async s => await consume(s, {
            all: [tagMatcher, numMatcher],
            some: [commentMatcher]
        }));
        //log('', res);
        expect(res).toBeDefined();
        
    }); */
});