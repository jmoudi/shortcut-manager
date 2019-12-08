package config

import (
	//"fmt"
	"log"
	"io/ioutil"
	"github.com/goccy/go-yaml"
)

type T struct {
	A string
	B struct {
			RenamedC int   `yaml:"c"`
			D        []int `yaml:",flow"`
	}
}


// ReadKeybindings
func ReadKeybindings(filePath string) (T) {
	t := T{}
	b, err := ioutil.ReadFile(filePath)
	if err != nil {
		log.Fatal(err)
	}
	log.Print(string(b))
	err = yaml.Unmarshal(b, &t)
	if err != nil {
		log.Fatal(err)
	}
	return t
}