 
//import {} from '../src';
import {loadC,consume,getAll,
    tagMatcher, numMatcher, commentMatcher
} from '../src/tasks/load';
import {
        parseKeys,
} from '../src/tasks/parse-keys';
import {
    loadConfig
} from '../src/tasks/load-config';


const log = console.log

afterAll(async (done) => {

    done();
});



describe('', () => {
/*     test('test1', async () => {
        const res = await loadC(async s => await consume(s, [tagMatcher, numMatcher, commentMatcher]));
        log('res', res);
        expect(res).toBeDefined();
        
    }); */
    test.only('test22', async () => {
        const res = await loadConfig({});
        log('res', res);
        expect(res).toBeDefined();
        
    }); 
    test('test1', async () => {
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
        
    });
});