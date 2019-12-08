// Example simple-keybinding shows how to grab keys on the root window and
// respond to them via callback functions. It also shows how to remove such
// callbacks so that they no longer respond to the key events.
// Note that more documentation can be found in the keybind package.
package keylistener

import (
	"fmt"
	"log"
	"github.com/BurntSushi/xgb/xproto"

	"github.com/BurntSushi/xgbutil"
	"github.com/BurntSushi/xgbutil/keybind"
	"github.com/BurntSushi/xgbutil/xevent"
)







// DoRun dorun
func parse(xu *xgbutil.XUtil, keyStr string) ([]xproto.Keycode) {
	// Get the mods/key first
	mods, keycodes, err := keybind.ParseString(xu, keyStr)
	if err != nil {
		log.Panic(err)
	}
	log.Print("mods, keycodes", mods, keycodes)
	return keycodes
}

// DoRun dorun
/* func matcher(xu *xgbutil.XUtil, s string) ([]xproto.Keycode) {
	// Get the mods/key first
	mods, keycodes, err := keybind.Ke(xu, keyStr)
	if err != nil {
		return err
	}
	log.Print("mods, keycodes", mods, keycodes)
	return keycodes
} */

// HandleKeyPress aaa
func HandleKeyPress(X *xgbutil.XUtil, e xevent.KeyPressEvent) {
	log.Println("Key press!")
	log.Print(e, "\n")
	fmt.Print(e, "================\n")
	//parse(X, e)
	// keybind.LookupString does the magic of implementing parts of
	// the X Keyboard Encoding to determine an english representation
	// of the modifiers/keycode tuple.
	// N.B. It's working for me, but probably isn't 100% correct in
	// all environments yet.
	modStr := keybind.ModifierString(e.State)
	keyStr := keybind.LookupString(X, e.State, e.Detail)
	if len(modStr) > 0 {
		log.Printf("Key: %s-%s\n", modStr, keyStr)
	} else {
		log.Println("Key:", keyStr)
	}
	log.Printf("Key: %s-%s\n", modStr, keyStr)

	if keybind.KeyMatch(X, "Escape", e.State, e.Detail) {
		if e.State&xproto.ModMaskControl > 0 {
			log.Println("Control-Escape detected. Quitting...")
			xevent.Quit(X)
		}
	}
}



// HandleKeyPress aaa
func HandleKeyPress2(m CmdMap, X *xgbutil.XUtil, e xevent.KeyPressEvent) {
	log.Println("Key press!")
	log.Print(e, "\n")
	
}
type ActionFunc func(keyStr string)
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
func tt(s string){
	log.Print("PRESSED: ", s)
}
func bindMap() (m CmdMap){
	keymap := CmdMap{
		//map2 := map[string]func(X *xgbutil.XUtil, e xevent.KeyPressEvent){ 
			"shift-C": Cmd{
				name: "shift+C",
				action: tt,
			},
			"shift-D": Cmd{
				name: "shift+D",
				action: tt,
			},
	}
	return keymap
}

func (m CmdMap) lookup(cmdStr string){
		a, ok := m[cmdStr]
		//fmt.Printf("key[%s] value[%s]\n", k, v, a)
		log.Print("cmdStr: ", cmdStr)
		log.Print("cmd: ", ok, a)
/* 		if a {
			log.Print("cmd: ", ok, a)
		} */
	
}

func (m CmdMap) bindAll(cmdStr string){
	for k, v := range m { 
		a, ok := m[k]
		//fmt.Printf("key[%s] value[%s]\n", k, v, a)
		log.Print("key: ", k, "val: ", v)
		log.Print("cmd: ", ok, a)
/* 		if a {
			log.Print("cmd: ", ok, a)
		} */
	}
}

/* eymap := BKeyMap{
	//map2 := map[string]func(X *xgbutil.XUtil, e xevent.KeyPressEvent){ 
      
		"shift-D": HandleKeyPress, 
		"shift-F": HandleKeyPress,
	}
	aa := keymap.Add("shift-A", HandleKeyPress)
	fmt.Print("aa", aa)
	fmt.Println("Map-2: ", keymap)  */

// DoRun dorun
func DoRun() int {
	cmdmap := bindMap()
/* 	m := make(map[string]func)
	m["Control-v"]
	fmt.Println(sammy["animal"]) */
	// Connect to the X server using the DISPLAY environment variable.
	X, err := xgbutil.NewConn()
	if err != nil {
		log.Fatal(err)
	}

	// Anytime the keybind (mousebind) package is used, keybind.Initialize
	// *should* be called once. It isn't strictly necessary, but allows your
	// keybindings to persist even if the keyboard mapping is changed during
	// run-time. (Assuming you're using the xevent package's event loop.)
	keybind.Initialize(X)

	
	// Before attaching callbacks, wrap them in a callback function type.
	// The keybind package exposes two such callback types: keybind.KeyPressFun
	// and keybind.KeyReleaseFun.
	//cb1 := keybind.KeyPressFun(HandleKeyPress)
	cb1 := keybind.KeyPressFun(
 		func(X *xgbutil.XUtil, e xevent.KeyPressEvent) {
			log.Println("Key press!")
			log.Print(e)
			
			keyStr := keybind.LookupString(X, e.State, e.Detail)
			log.Print("keyStr", keyStr)
			cmdmap.lookup(keyStr)
		}) 
	err = cb1.Connect(X, X.RootWin(), "shift-c", true)

		// We can now attach the callback to a particular window and key
		// combination. This particular example grabs a key on the root window,
		// which makes it a global keybinding.
		// Also, "Mod4-j" typically corresponds to pressing down the "Super" or
		// "Windows" key on your keyboard, and then pressing the letter "j".
		// N.B. This approach works by issuing a passive grab on the window
		// specified. To respond to Key{Press,Release} events without a grab, use
		// the xevent.Key{Press,Release}Fun callback function types instead.
/* 	err = cb1.Connect(X, X.RootWin(), "Mod4-j", true)

	err = cb1.Connect(X, X.RootWin(), "Mod2-f", true)
	err = cb1.Connect(X, X.RootWin(), "Alt-c", true)
	err = cb1.Connect(X, X.RootWin(), "Control-v", true)
	err = cb1.Connect(X, X.RootWin(), "shift-c", true)
	err = cb1.Connect(X, X.RootWin(), "shift-d", true)
	//mod1 = alt
	err = cb1.Connect(X, X.RootWin(), "Mod1-a", true) */



	// A keybinding can fail if the key string could not be parsed, or if you're
	// trying to bind a key that has already been grabbed by another client.
	if err != nil {
		log.Fatal(err)
	}

	// We can even attach multiple callbacks to the same key.
	/* 	err = keybind.KeyPressFun(
	   		func(X *xgbutil.XUtil, e xevent.KeyPressEvent) {
	   			log.Println("A second handler always happens after the first.")
	   		}).Connect(X, X.RootWin(), "Mod4-j", true)
	   	if err != nil {
	   		log.Fatal(err)
	   	} */

	// Finally, if we want this client to stop responding to key events, we
	// can attach another handler that, when run, detaches all previous
	// handlers.
	// This time, we'll show an example of a KeyRelease binding.
	/* err = keybind.KeyReleaseFun(
		func(X *xgbutil.XUtil, e xevent.KeyReleaseEvent) {
			// Use keybind.Detach to detach the root window
			// from all KeyPress *and* KeyRelease handlers.
			keybind.Detach(X, X.RootWin())

			log.Printf("Detached all Key{Press,Release}Events from the "+
				"root window (%d).", X.RootWin())
		}).Connect(X, X.RootWin(), "Mod4-Shift-q", true)
	if err != nil {
		log.Fatal(err)
	} */

	// Finally, start the main event loop. This will route any appropriate
	// KeyPressEvents to your callback function.
	log.Println("Program initialized. Start pressing keys!")
	xevent.Main(X)
	return 1
}
