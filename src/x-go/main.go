package main

// #cgo CFLAGS: -v -lX11 -g -Wall
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <X11/Xlib.h>
// #include <X11/keysym.h>
// #include <stdlib.h>
// #include "xsendkey.h"
import "C"
import (
	"fmt"
	"unsafe"
)

func main() {
	name := C.CString("Gopher")
	defer C.free(unsafe.Pointer(name))

	year := C.int(2018)
	print("year", year)
	g := C.struct_Greetee{
		name: name,
		year: year,
	}
	sizse := C.XK_V
	size := C.SendKeyPressedEvent(&g, (*C.char)(ptr))

	b := C.GoBytes(ptr, size)
	fmt.Println(string(b))
	print("gr", g)
}
