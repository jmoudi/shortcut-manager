"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
//import {walk,walkSync,readdirp} from '../src';
//import { log } from '../dist/index';
const fs_1 = require("@Modules/fs");
const teststr = `
FIRST LINE
{{attr1}}: valA
{{attr2}}: valB
{{attr3}}: valC
LAST LINE
`;
describe('dependencies', () => {
    const testdir = `/home/jm/Templates/AppTemplate/`;
    test(`Watcher`, async () => {
        console.log(`Watcher`, fs_1.Watcher);
        expect(fs_1.Watcher).toBeTruthy();
    });
});
/*

describe('readdirp', () => {
    const testdir = `/home/jm/Templates/AppTemplate/`
    test(`1`, async () => {
        const outp = readdirp(testdir, {
            fileFilter: (e) => isntMd(e.basename),
            directoryFilter: (e) => isntExcludedDir(e.basename)
        })
        .on('warn', error => console.error('non-fatal error', error))
        .on('error', error => console.error('fatal error', error))
        .on('end', () => console.log('done'))
        .on('data', handleData);
        const res = await outp;

    });

})

describe('walk', () => {
    const testdir = `/home/jm/Templates/AppTemplate/`
    test(`1`, async () => {
        const outp = walkSync(testdir,  );
        console.log("outp", outp)
    });

})
 */ 
//# sourceMappingURL=data:application/json;charset=utf-8;base64,eyJmaWxlIjoiL2hvbWUvam0vUHJvamVjdHMvQXBwcy9Ib3RrZXlNYW5hZ2VyL3Rlc3Qvd2F0Y2gudGVzdC50cyIsIm1hcHBpbmdzIjoiOztBQUFBLGdEQUFnRDtBQUNoRCxzQ0FBc0M7QUFDdEMsb0NBQW9DO0FBRXBDLE1BQU0sT0FBTyxHQUFHOzs7Ozs7Q0FNZixDQUFDO0FBRUYsUUFBUSxDQUFDLGNBQWMsRUFBRSxHQUFHLEVBQUU7SUFDMUIsTUFBTSxPQUFPLEdBQUcsaUNBQWlDLENBQUE7SUFDakQsSUFBSSxDQUFDLFNBQVMsRUFBRSxLQUFLLElBQUksRUFBRTtRQUN2QixPQUFPLENBQUMsR0FBRyxDQUFDLFNBQVMsRUFBQyxZQUFPLENBQUMsQ0FBQztRQUMvQixNQUFNLENBQUMsWUFBTyxDQUFDLENBQUMsVUFBVSxFQUFFLENBQUM7SUFDakMsQ0FBQyxDQUFDLENBQUE7QUFDTixDQUFDLENBQUMsQ0FBQTtBQUVGOzs7Ozs7Ozs7Ozs7Ozs7Ozs7Ozs7Ozs7Ozs7R0EyQkciLCJuYW1lcyI6W10sInNvdXJjZXMiOlsiL2hvbWUvam0vUHJvamVjdHMvQXBwcy9Ib3RrZXlNYW5hZ2VyL3Rlc3Qvd2F0Y2gudGVzdC50cyJdLCJzb3VyY2VzQ29udGVudCI6WyIvL2ltcG9ydCB7d2Fsayx3YWxrU3luYyxyZWFkZGlycH0gZnJvbSAnLi4vc3JjJztcbi8vaW1wb3J0IHsgbG9nIH0gZnJvbSAnLi4vZGlzdC9pbmRleCc7XG5pbXBvcnQge1dhdGNoZXJ9IGZyb20gJ0BNb2R1bGVzL2ZzJztcblxuY29uc3QgdGVzdHN0ciA9IGBcbkZJUlNUIExJTkVcbnt7YXR0cjF9fTogdmFsQVxue3thdHRyMn19OiB2YWxCXG57e2F0dHIzfX06IHZhbENcbkxBU1QgTElORVxuYDtcblxuZGVzY3JpYmUoJ2RlcGVuZGVuY2llcycsICgpID0+IHtcbiAgICBjb25zdCB0ZXN0ZGlyID0gYC9ob21lL2ptL1RlbXBsYXRlcy9BcHBUZW1wbGF0ZS9gXG4gICAgdGVzdChgV2F0Y2hlcmAsIGFzeW5jICgpID0+IHtcbiAgICAgICAgY29uc29sZS5sb2coYFdhdGNoZXJgLFdhdGNoZXIpO1xuICAgICAgICBleHBlY3QoV2F0Y2hlcikudG9CZVRydXRoeSgpO1xuICAgIH0pXG59KVxuXG4vKiBcblxuZGVzY3JpYmUoJ3JlYWRkaXJwJywgKCkgPT4ge1xuICAgIGNvbnN0IHRlc3RkaXIgPSBgL2hvbWUvam0vVGVtcGxhdGVzL0FwcFRlbXBsYXRlL2BcbiAgICB0ZXN0KGAxYCwgYXN5bmMgKCkgPT4ge1xuICAgICAgICBjb25zdCBvdXRwID0gcmVhZGRpcnAodGVzdGRpciwge1xuICAgICAgICAgICAgZmlsZUZpbHRlcjogKGUpID0+IGlzbnRNZChlLmJhc2VuYW1lKSxcbiAgICAgICAgICAgIGRpcmVjdG9yeUZpbHRlcjogKGUpID0+IGlzbnRFeGNsdWRlZERpcihlLmJhc2VuYW1lKVxuICAgICAgICB9KVxuICAgICAgICAub24oJ3dhcm4nLCBlcnJvciA9PiBjb25zb2xlLmVycm9yKCdub24tZmF0YWwgZXJyb3InLCBlcnJvcikpXG4gICAgICAgIC5vbignZXJyb3InLCBlcnJvciA9PiBjb25zb2xlLmVycm9yKCdmYXRhbCBlcnJvcicsIGVycm9yKSlcbiAgICAgICAgLm9uKCdlbmQnLCAoKSA9PiBjb25zb2xlLmxvZygnZG9uZScpKVxuICAgICAgICAub24oJ2RhdGEnLCBoYW5kbGVEYXRhKTtcbiAgICAgICAgY29uc3QgcmVzID0gYXdhaXQgb3V0cDtcblxuICAgIH0pOyBcblxufSlcblxuZGVzY3JpYmUoJ3dhbGsnLCAoKSA9PiB7XG4gICAgY29uc3QgdGVzdGRpciA9IGAvaG9tZS9qbS9UZW1wbGF0ZXMvQXBwVGVtcGxhdGUvYFxuICAgIHRlc3QoYDFgLCBhc3luYyAoKSA9PiB7XG4gICAgICAgIGNvbnN0IG91dHAgPSB3YWxrU3luYyh0ZXN0ZGlyLCAgKTtcbiAgICAgICAgY29uc29sZS5sb2coXCJvdXRwXCIsIG91dHApXG4gICAgfSk7IFxuXG59KVxuICovIl0sInZlcnNpb24iOjN9