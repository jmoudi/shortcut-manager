package main

import (
	"godaemon/src/keylistener"

	. "github.com/onsi/ginkgo"
	. "github.com/onsi/gomega"
)

var _ = Describe("Main", func() {
	d := keylistener.DoRun()
	Context("keylistener", func() {
		It("should be a novel", func() {
			Expect(d).To(Equal(1))
		})
	})

})
