package main

import (
	"godaemon/cmd/run"
)

// Example simple-keybinding shows how to grab keys on the root window and
// respond to them via callback functions. It also shows how to remove such
// callbacks so that they no longer respond to the key events.
// Note that more documentation can be found in the keybind package.

func main() {
	run.Run()
}
