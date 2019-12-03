import {createServer} from 'net';
//import {log} from '@Modules/log';
const log = console.log;
const config = {
    path: `aa`
}


interface Command {
  name: string;
  execute(): any;
  

}
interface CommandMap extends Map<string, Command> {

}

interface KeyListenerServer {
  registeredCommands: Command[];
}


export function startServer(){
    const server = createServer((c) => {
        // 'connection' listener
        console.log('client connected');
        c.on('end', () => {
          console.log('client disconnected');
        });
        c.write('hello\r\n');
        //c.pipe(c);
      });
      server.on(`data`, (data) => log(data));
      server.on(`connection`, (socket) => {
        socket.on(`data`, (buffer) => {
            const data = buffer.toString().trim();
            log(data);
            //const [key,mod,]data
            if (data === `getk`){
                socket.write(`dsfdsfds` + `\n`)
            }
        });
    });

      server.on('error', (err) => {
        throw err;
      });
      server.listen(2222, () => {
        console.log('server bound');
      });
}