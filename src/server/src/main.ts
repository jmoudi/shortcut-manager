import { run } from './init';
async function main(){
    //console.clear()
    console.log(`aaaaa`);
    const res = await run();
    console.log(`res`,  res);
    return res;
}

//readIntegrity().catch((err) => { console.log(err); process.exit(1); });
 main()
.catch(err => { console.error(err); process.exit(1); });