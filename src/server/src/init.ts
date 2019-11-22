import { fromEvent } from 'rxjs';
import ioHook from 'iohook';
import { IOHookEvent, IoHookInit, Evt } from '@/types';
import { loadConfig } from '@/tasks/load-config';
import { paste } from '@/tasks/send';
import { IOHookApp } from '@/io';
import { parseKeys } from './utils/parse-keys';
import { CachedKey } from './utils/cached-key';
import { ActionMap } from './utils/actions';


const logger = console;


const defaultInit: IoHookInit = { logging: false };


const debug = false;
 
const onPressed = <T extends IOHookEvent>(e: T) => {
    logger.info("e", e);
};
const onPressed2 = <T extends IOHookEvent>(e: T) => {
    logger.info("dsfde", e);
};

ioHook.registerShortcut([0x007a], onPressed);
ioHook.registerShortcut([52], onPressed2);


export const createObservable = () => {
    const obs = fromEvent<IOHookEvent>(ioHook, Evt.keydown);
    /*     obs.pipe(map(
            onPressed
        )); */
    return obs;
};
export const start = async () => {
    const obs = createObservable();
    obs.subscribe(onPressed);
    ioHook.start(debug);
    logger.info('started');
    return 1;
};

const actions = new Map<string, Function>();

interface App {
    keymap: Map<number|string, CachedKey>,
    actions: 
}
const app = {
    
} as App;

const keycodes = new Map<string, CachedKey>();


export async function init({ logging }: IoHookInit = defaultInit) {
    app.keymap = await parseKeys(); 
    actions
    const conf1 = {
        actions,

    }
    const conf = await loadConfig({});
    app.actions = new ActionMap();
    app.actions.set('enter', paste);
    conf.keys.forEach(app.actions)
    const ioapp = new IOHookApp(conf1);
    ioapp.bindAll(conf.keys);
    ioapp.configure();
  
  }
  