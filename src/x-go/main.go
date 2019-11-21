package main

// #cgo CFLAGS: -g -Wall
// #include <stdlib.h>
// #include "greeter.h"
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
	size := C.greet(&g, (*C.char)(ptr))

	b := C.GoBytes(ptr, size)
	fmt.Println(string(b))
	print("gr", g)
}
