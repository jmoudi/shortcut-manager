
package keylistener

import (
	"fmt"
	"log"
	"github.com/BurntSushi/xgb/xproto"

	"github.com/BurntSushi/xgbutil"
	"github.com/BurntSushi/xgbutil/keybind"
	"github.com/BurntSushi/xgbutil/xevent"
 
)


type ActionFunc func(keyStr string)

type Action struct {
	name string
	action ActionFunc
}
type ActionMap map[string]Cmd

func (m ActionMap) New() (ActionMap){
	keymap := ActionMap{
	}
	return keymap
}

func (m ActionMap) Add(k string, a ActionFunc) ActionMap {
	m[k] = cb
	return m
}


type Cmd struct {
	name string
	action ActionFunc
}
type CmdMap map[string]Cmd

type KeyPressHandler func(X *xgbutil.XUtil, e xevent.KeyPressEvent)
type BKeyMap map[string]KeyPressHandler

func (m BKeyMap) Add(k string, cb KeyPressHandler) BKeyMap {
	m[k] = cb
	return m
}