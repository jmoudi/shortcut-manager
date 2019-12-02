package main

import (
	"bytes"
	clipboard "github.com/atotto/clipboard"
	"io"
	"log"
	"os"
	"os/exec"
)

func pacmanconf(args []string) (string, string, error) {
	var outbuf, errbuf bytes.Buffer
	cmd := exec.Command("pacman-conf", args...)
	cmd.Env = append(os.Environ(), "GIT_TERMINAL_PROMPT=0")

	cmd.Stdout = &outbuf
	cmd.Stderr = &errbuf

	err := cmd.Run()
	stdout := outbuf.String()
	stderr := errbuf.String()

	return stdout, stderr, err
}

// soooo
func CWrite(new_str string) {
	old_str, err := clipboard.ReadAll()
	if err != nil {
		log.Fatal(err)
	}
	clipboard.WriteAll(new_str)
	cp := exec.Command("./paste")
	cp.Run()
	log.Print("old_str", old_str, "new_str", new_str)

}

// soooo
func main() {
	CWrite("ccccccc")
}

func mainc() {

	//var oo = []string{"--selection", "--input"}
	//c2 := exec.Command("xsel", oo...)

	c1 := exec.Command("xsel", "--selection", "--input")
	stdin1, err := c1.StdinPipe()
	if err != nil {
		log.Fatal(err)
	}
	//string inp1 = "ccccc"
	stdin1.Write([]byte("inp1"))

	if err = c1.Start(); err != nil {
		log.Fatal(err)
	}
	if err = c1.Wait(); err != nil {
		log.Fatal(err)
	}
	log.Print("CLEAR")
}

func main2() {
	c1 := exec.Command("ls")
	stdout1, err := c1.StdoutPipe()
	if err != nil {
		log.Fatal(err)
	}

	if err = c1.Start(); err != nil {
		log.Fatal(err)
	}
	if err = c1.Wait(); err != nil {
		log.Fatal(err)
	}

	c2 := exec.Command("wc", "-l")
	c2.Stdin = stdout1

	stdout2, err := c2.StdoutPipe()
	if err != nil {
		log.Fatal(err)
	}

	if err = c2.Start(); err != nil {
		log.Fatal(err)
	}
	if err = c2.Wait(); err != nil {
		log.Fatal(err)
	}

	io.Copy(os.Stdout, stdout2)
}
