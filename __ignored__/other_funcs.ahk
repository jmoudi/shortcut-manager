
TabMover(fromProgram, toProgram){
    WinActivate, %fromProgram%
    WinWaitActive, %fromProgram%,,5
    SendMode, Input
    BlockInput, On
    ClipboardStore := Clipboard 
    Clipboard := ""
    WinActivate, %fromProgram%
    WinWaitActive, %fromProgram%,,5
    Send {F6}{Sleep 150}^c
    ClipWait, 5
    WinActivate, %toProgram%
    WinWaitActive, %toProgram%,,5
    Send {F6}{Sleep 80}^a{backspce}{Sleep 120}^v{Sleep 20}
    Clipboard := ""
    Send {F6}{Sleep 50}^v{Sleep 20}{F6}{Sleep 50}
    Send {F6}{Sleep 50}^c
    ClipWait, 5
    if (Clipboard != ""){
        Send {F6}{Sleep 20}!{enter}
    }

    BlockInput, Off
    Clipboard := ClipboardStore
    return
    
}


nofunc(){
return
}
nofunc := Func("nofunc").Bind()


#If WinActive("ahk_exe chrome.exe") && WinExist("ahk_exe firefox.exe")
    ^#e::TabMover("ahk_exe chrome.exe","ahk_exe firefox.exe")


	



;=====================================================================;
#If (WinActive("淘宝网 - Nightly") or WinActive("天猫 - Nightly") or WinActive("阿里巴巴 - Nightly") or WinActive("蘑菇街"))
	WheelDown::WheelAccel(7)
	WheelUp::WheelAccel(7)
#If
*/