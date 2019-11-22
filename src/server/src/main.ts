import {pipe} from 'rxjs';
import { start } from './init';
async function main(){
    console.clear()
    const res = start();
    console.log(`res`,  res);
    return res;
}

//readIntegrity().catch((err) => { console.log(err); process.exit(1); });
 main()
.catch(err => { console.error(err); process.exit(1); });