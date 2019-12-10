package config

import (
	//"fmt"
	"log"
	"io/ioutil"
	//"github.com/goccy/go-yaml"
	yaml "gopkg.in/yaml.v2"
)

type T struct {
	A string
	B struct {
			RenamedC int   `yaml:"c"`
			D        []int `yaml:",flow"`
	}
}

type Keybinding struct {
	Key []string `yaml:"key"`
	Command string `yaml:"command"`
	Args []string `yaml:"args"`
}
type Keybinding2 struct {
	key []string
	command string
	args []string
}
type KeybindingsConfig struct   {
	Version string `yaml:"version"`
	Keybindings []Keybinding `yaml:"keybindings"`
}

 func (k KeybindingsConfig) GetAll() int {
	
	for i,v := range k.Keybindings { 
		//a, ok := m[k]
		//fmt.Printf("key[%s] value[%s]\n", k, v, a)
		log.Print("key: ", k, "val: ", v)
		//log.Print("cmd: ", ok, a)
 		if a {
			log.Print("cmd: ", ok, a)
		}  
	}
	return 1
} */
// ReadKeybindings
func ReadKeybindings(filePath string) (interface{}) {
	var t KeybindingsConfig // interface{} //:= T{}
	b, err := ioutil.ReadFile(filePath)
	if err != nil {
		log.Fatal(err)
	}
	log.Print(string(b))
	err = yaml.Unmarshal(b, &t)
	log.Print(t)
	//yaml "gopkg.in/yaml.v2"
	if err != nil {
		log.Fatal(err)
	}

	for
	//c := t.GetAll()
	return t
}