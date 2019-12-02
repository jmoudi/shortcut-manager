package main2_test

import (
	"testing"

	. "github.com/onsi/ginkgo"
	. "github.com/onsi/gomega"
)

func TestGoDaemon(t *testing.T) {
	RegisterFailHandler(Fail)
	RunSpecs(t, "GoDaemon Suite")
}
