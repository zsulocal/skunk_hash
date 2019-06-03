package skunk_hash

// #cgo CFLAGS: -I.
// #cgo LDFLAGS: -L. -lskunk_hash
// #include "skunkhash.h"
import "C"

import (
	"unsafe"
)

func GetPowHash(hash []byte) []byte {
	powhash := make([]byte, 32)
	C.Skunk_Hash((*C.char)(unsafe.Pointer(&hash[0])), (*C.char)(unsafe.Pointer(&powhash[0])))
	return powhash
}
