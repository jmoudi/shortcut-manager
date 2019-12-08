package config_test

import (
	. "github.com/onsi/ginkgo"
	. "github.com/onsi/gomega"
	"testing"
)

var _ = Describe("Config", func() {
	res := 1
	It("should be a novel", func() {
		Expect(res).To(Equal(1))
	})
})

func TestReadKeybindings(t *testing.T) {
	const (
		file = "/home/jm/Projects/Apps/hotkey-manager/src/config/test.yml"
		file2 = "file:///home/jm/Projects/Apps/hotkey-manager/src/config/test.yml"
	)
	conf := ReadKeybindings(file)
	log.Print(conf)
	fmt.Print(conf)
	//keylistener.DoRun()
}