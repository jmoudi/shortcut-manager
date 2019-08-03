;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Start of xbindkeys guile configuration ;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; This configuration is guile based.
;;   http://www.gnu.org/software/guile/guile.html
;; any functions that work in guile will work here.
;; see EXTRA FUNCTIONS:

;; Version: 1.8.6

;; If you edit this file, do not forget to uncomment any lines
;; that you change.
;; The semicolon(;) symbol may be used anywhere for comments.

;; To specify a key, you can use 'xbindkeys --key' or
;; 'xbindkeys --multikey' and put one of the two lines in this file.

;; A list of keys is in /usr/include/X11/keysym.h and in
;; /usr/include/X11/keysymdef.h
;; The XK_ is not needed.

;; List of modifier:
;;   Release, Control, Shift, Mod1 (Alt), Mod2 (NumLock),
;;   Mod3 (CapsLock), Mod4, Mod5 (Scroll).


;; The release modifier is not a standard X modifier, but you can
;; use it if you want to catch release instead of press events

;; By defaults, xbindkeys does not pay attention to modifiers
;; NumLock, CapsLock and ScrollLock.
;; Uncomment the lines below if you want to use them.
;; To dissable them, call the functions with #f


;;;;EXTRA FUNCTIONS: Enable numlock, scrolllock or capslock usage
;;(set-numlock! #t)
;;(set-scrolllock! #t)
;;(set-capslock! #t)

;;;;; Scheme API reference
;;;;
;; Optional modifier state:
;; (set-numlock! #f or #t)
;; (set-scrolllock! #f or #t)
;; (set-capslock! #f or #t)
;; 
;; Shell command key:
;; (xbindkey key "foo-bar-command [args]")
;; (xbindkey '(modifier* key) "foo-bar-command [args]")
;; 
;; Scheme function key:
;; (xbindkey-function key function-name-or-lambda-function)
;; (xbindkey-function '(modifier* key) function-name-or-lambda-function)
;; 
;; Other functions:
;; (remove-xbindkey key)
;; (run-command "foo-bar-command [args]")
;; (grab-all-keys)
;; (ungrab-all-keys)
;; (remove-all-keys)
;; (debug)

 
;; Extra features
(xbindkey-function '(control shift a)
                   (lambda ()
                     (display "Hello from Scheme!")
                    ))

;; Double click test
(xbindkey-function '(shift w)
                   (let ((count 0))
                     (lambda ()
                       (set! count (+ count 1))
                       (if (> count 1)
                           (begin
                            (set! count 0)
                            (run-command "xterm"))))))

;; Time double click test:
;;  - short double click -> run an xterm
;;  - long  double click -> run an rxvt
(xbindkey-function '(shift g)
                   (let ((time (current-time))
                         (count 0))
                     (lambda ()
                       (set! count (+ count 1))
                       (if (> count 1)
                           (begin
                            (if (< (- (current-time) time) 1)
                                (run-command "xterm")
                                (run-command "rxvt"))
                            (set! count 0)))
                       (set! time (current-time)))))


;; Chording keys test: Start differents program if only one key is
;; pressed or another if two keys are pressed.
;; If key1 is pressed start cmd-k1
;; If key2 is pressed start cmd-k2
;; If both are pressed start cmd-k1-k2 or cmd-k2-k1 following the
;;   release order
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

 

 ;: event_type PRESS RELEaSE BUTTON SYM, CODE argc argv

(xbindkey-function '(shift a)
		   (lambda ()
        (grab-all-keys)
         ))
(xbindkey-function '(shift c)
		   (lambda ()
        (debug)
         ))
(xbindkey-function '(shift d)
		   (lambda ()
       (display "================")
        (display 'press)
         ))
(xbindkey-function '(shift z)
		   (lambda ()
       (display "======111==========")
       (display 'argc)
       (display 'argv)
       (display 'event_type)
       (display 'CODE)
       (display 'BUTTON)
       (display 'SYM)
       (display 'SYM)
       (display "======2222========")
         ))
(xbindkey-function '(shift v)
                   (lambda ()
                     (run-command "xsendkey Control+Shift+T")))

(xbindkey-function '(alt c)
                   (lambda ()
                     (run-command "xsendkey Control+Shift+T")))