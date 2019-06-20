import {BaseController} from '@app/core';
import { Controller, Get, Post, Context, Request, Response } from '@shared/node/express-server';
import { HotkeyManager, IHotkey } from '@app/api/hotkey-manager';


const hotkeyManager = new HotkeyManager();

@Controller('/api/hotkeys')
export class DictController {


    @Post('/add')
    async add(req, res){
        const keyData: IHotkey = req.body;
        hotkeyManager.addHotkey(keyData);
    } 
}

 