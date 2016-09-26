package main

/*
#cgo LDFLAGS: -lfancy -Llib

#include "fancy.h"
*/
import "C"

func be_fancy(ent string) {
	cstr := C.CString(ent)
	C.cppug_be_fancy_on_stdout(cstr)
}

func main() {
	be_fancy("gopher")
}
