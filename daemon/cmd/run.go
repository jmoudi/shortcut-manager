package run

import (
	"log"
	"godaemon/pkg/keylistener"
	"godaemon/pkg/config"
)
// Example simple-keybinding shows how to grab keys on the root window and
// respond to them via callback functions. It also shows how to remove such
// callbacks so that they no longer respond to the key events.
// Note that more documentation can be found in the keybind package.

// Run run start
func Run() {
	const (
		file = "/home/jm/Projects/Apps/hotkey-manager/src/config/test.yml"
		file2 = "file:///home/jm/Projects/Apps/hotkey-manager/src/config/test.yml"
	)
	conf := config.ReadKeyConfig(file)
	log.Print(conf)
	log.Print(keylistener.DoRun)
	//keylistener.DoRun()
}
