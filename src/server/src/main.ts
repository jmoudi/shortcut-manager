import { init,init2 } from '@/app/init';

//DEPRECATED because the ioHook-listener doesn't prevent the pressed keys from firing
async function main(){
    //console.clear()
    console.log(`aaaaa`);
    const res = await init();

    // @ts-ignore
    console.log(`active:`,  res.ioHook.active, res.ioHook.shortcuts);
    return res;
}

//readIntegrity().catch((err) => { console.log(err); process.exit(1); });
 main()
.catch(err => { console.error(err); process.exit(1); });