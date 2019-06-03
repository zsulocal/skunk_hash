package skunk_hash

import (
	"encoding/hex"
	"testing"
)

func TestX16r(t *testing.T) {
	header := "040000002a13e0af784e613caf0e2d847544355bea2369a79a6450083676000000000000f2e705e0f944feb181a53a661bbf0a927a0ba9aea456a487a857075bc90e6ed325c7f45c669e001b51cc5b58"
	header_bin, _ := hex.DecodeString(header)
	powhash := GetPowHash(header_bin)
	powhash_hex := hex.EncodeToString(powhash)
	if powhash_hex != "9ec66ed598166ac18c343a8123b0c8b6358037a723f80a330a6b000000000000" {
		t.Error("Test x16r powhash failed")
		return
	}
}

//
