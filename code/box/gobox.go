package main

/*
#cgo LDFLAGS: -lbox -Llib

#include "box.h"
*/
import "C"
import "runtime"
import "fmt"

type Box struct {
	c_box C.box_t
}

func NewBox(size int) *Box {
	box := new(Box)
	runtime.SetFinalizer(box, func(ins *Box) {
		C.box_destroy(ins.c_box)
	})
	box.c_box = C.box_create(C.size_t(size), nil)
	if box.c_box == nil {
		panic("Failed to initializ object")
	}
	return box
}

func (obj *Box) Push(val int) {
	err := C.int(0)
	C.box_push(obj.c_box, C.int(val), &err)

	if err != 0 {
		panic("Failed to push value")
	}
}

func (obj *Box) Pop() int {
	err := C.int(0)
	val := C.box_pop(obj.c_box, &err)

	if err != 0 {
		panic("Failed to pop value")
	}

	return int(val)
}

func main() {
	box := NewBox(3)
	box.Push(42)
	val := box.Pop()

	fmt.Println("Popped ", val)
}
