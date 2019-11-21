 
 

; ============================================== TOTAL REPLACEMENTS ============================================== ;
CapsLock::Enter
NumLock::RAlt
Alt::Return
LWin::LCtrl
F1::!F1
F12::!F11
;NumpadDot::.
+^1::sendKey("(")
+^2::sendKey(")")
+^3::sendKey("*")
+^4::sendKey("-")
+^5::sendKey("=")
F4::Powershell.startInCurrentDir()
+F4::Powershell.start()
#+s::Msg.box("aaaa", "bbbb", "cccc")
#+d::Msg.box("aaaa", "bbbb", "cccc")


; ============================================== GENERAL ============================================== ;
;F12::Run Calc.exe
#If (WinActive("ahk_exe mintty.exe"))
    ^v::SendInput +{Insert}
    ;^f::Send +{Insert}
    !s::
    SendInput git clone {Space}^v
    SendInput {Enter}
#If (!WinActive("ahk_exe everything.exe"))
    !y::SendInput !z
    !z::SendInput !y


#If WinActive("ahk_exe everything.exe")
    ^t::sendKey("t") ; disable "Always on Top"
; ============================================== BROWSERS ============================================== ;
#If (!WinActive("ahk_exe Code.exe"))
    !q::SendInput ^{PgUp}
    !w::SendInput ^{Home}
    !e::SendInput ^{PgDn}
    !r::SendInput !{Left}
    !t::SendInput !{Right}
    ^#a::Run %A_WorkingDir%\ahk_START_ALL.bat
#If (WinActive("ahk_exe firefox.exe") || WinActive("ahk_exe chrome.exe"))
    !1::SendInput {F2}
    !2::SendInput ^{w}
    !3::SendInput {F5}
    !4::SendInput site:
    +!4::SendInput inurl:
    !5::SendInput intitle:
    +!5::SendInput inanchor:"
    ^+r::SendInput ^+{j} 
	;$!c::Saver() ;$+d::Saver()
#If WinActive("ahk_exe chrome.exe")
	Hotkey, $!LButton, %nofunc%, B0 P5 T5 ;$+d::Saver()
	^+c::^+i
#If
