
;; Example:
(define (define-event-key key1) 
	"Define event keys"
	(let ((k1 key1))
		(lambda ()
		     (display k1)
		     (newline))))

(nodemon -- './src/bindkeys.sh'
 "socat - tcp6-connect:localhost:2222")


(xbindkey-function '(alt z)
		   (lambda ()
		     (define-event-key (alt))
		     (newline)))

(xbindkey-function '(alt s)
		   (lambda ()
		     (peek '')
		     (newline)))

(xbindkey-function '(control a)
		   (lambda ()
		     (display "Hello from Scheme!")
		     (newline)))



(define (define-chord-keys key1 key2 cmd-k1 cmd-k2 cmd-k1-k2 cmd-k2-k1)
    "Define chording keys"
  (let ((k1 #f) (k2 #f))
    (xbindkey-function key1 (lambda () (set! k1 #t)))
    (xbindkey-function key2 (lambda () (set! k2 #t)))
    (xbindkey-function (cons 'release key1)
		       (lambda ()
			 (if (and k1 k2)
			     (run-command cmd-k1-k2)
			     (if k1 (run-command cmd-k1)))
			 (set! k1 #f) (set! k2 #f)))
    (xbindkey-function (cons 'release key2)
		       (lambda ()
			 (if (and k1 k2)
			     (run-command cmd-k2-k1)
			     (if k2 (run-command cmd-k2)))
			 (set! k1 #f) (set! k2 #f)))))


;; Example:
;;   Shift + b:1                   start an xterm
;;   Shift + b:3                   start an rxvt
;;   Shift + b:1 then Shift + b:3  start gv
;;   Shift + b:3 then Shift + b:1  start xpdf

;;(define-event-key '(shift "g")
;;)

(define-chord-keys '(shift "r") '(shift "t")
  "bash /home/jm/Projects/Apps/BashScripts/src/manage_system/test.sh" "pass" "pass" "pass")
 