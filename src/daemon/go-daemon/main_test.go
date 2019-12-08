package main

import (
	"godaemon/pkg/keylistener"

	. "github.com/onsi/ginkgo"
	. "github.com/onsi/gomega"
)

var _ = Describe("Main", func() {
	d := keylistener.DoRun()
	Context("keylistener", func() {
		It("should start", func() {
			Expect(d).To(Equal(1))
		})
	})

})
