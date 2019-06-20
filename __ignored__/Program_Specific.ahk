#SingleInstance force
#Persistent
SetBatchLines, 200ms
Menu, Tray, Icon, %A_ScriptDir%/icons/main2.ico
SetTitleMatchMode 2
#Hotstring NoMouse
#Hotstring c*
#WinActivateForce
 
#^::Run C:\Users\Jon\Google Drive\Programming\AutoHotkey\startMain.bat
     


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

; ============================================== BROWSERS ============================================== ;

#If WinActive("ahk_exe firefox.exe")
	;$!c::Saver() ;$+d::Saver()
#If WinActive("ahk_exe chrome.exe")
	Hotkey, $!LButton, %nofunc%, B0 P5 T5 ;$+d::Saver()
	^+c::^+i
#If WinActive("ahk_exe chrome.exe") && WinExist("ahk_exe firefox.exe")
    ^#e::TabMover("ahk_exe chrome.exe","ahk_exe firefox.exe")
; ============================================== SOFTWARE ============================================== ;

#If WinActive("Library")
	$!s::SendInput, {Delete}
#If WinExist("ahk_exe foobar2000.exe")
	$!y::!F3
#If WinActive("ahk_class MediaPlayerClassicW")
	;$!c::Deleter(Approved)
	Space::Numpad0

; ============================================== GAMES ============================================== ;
#If WinActive("ahk_exe hh.exe")
    ::var::variable
    ::fu::function
    ::gu::gui
    ::exp::expression
    ::ob::object
    ::cla::class
    ::ho::hotkey
    ::como::comobject
    ::par::parameter
	::con::control
	::mo::mouse
	::onm::onmessage
	::post::postmessage
	::sendm::sendmessage
	::mes::message
	::-::_

#If WinActive("ahk_exe pythonw.exe")
	::im::import  
	::ret::return
; ::pr::print(
    ::le::len(

#If WinActive("ahk_exe notepad++.exe")
	;::-::_
	
    If WinActive(".py - Notepad++") {
        ; ::im::import  
        ; ::ret::return
        ; ::pr::print(
        ; ::le::len(
    }
	
#If

;=========== GAMES ==========================================================;
#IfWinActive, ahk_exe Dangan3Win.exe
C::P
F::F1
1::F1
2::F1
3::F2
4::F2
5::F3
CapsLock::Tab
;#IfWinActive, ahk_exe FL.exe ; Fruity Loops
#If WinActive("ahk_exe FL.exe") && !WinActive("ahk_exe chrome.exe") && !WinActive("ahk_exe firefox.exe") ; Fruity Loops
    2::F6 ; Channel Rack
    3::F7 ; Piano Roll
    4::F7
    5::F7
    6::F9 ; Mixer
    7::F9 ; Mixer
    CapsLock::Tab
    !d::SendInput {Del}
    !y::SendInput ^{z}
    ^y::SendInput ^{z}
    !c::+p
#If

/*
#if WinActive("Undertale")
w::Up
a::Left
s::Down
d::Right
e::Enter
r::Enter
f::Sendinput z
c::Esc
x::Esc


;=====================================================================;
#If (WinActive("淘宝网 - Nightly") or WinActive("天猫 - Nightly") or WinActive("阿里巴巴 - Nightly") or WinActive("蘑菇街"))
	WheelDown::WheelAccel(7)
	WheelUp::WheelAccel(7)
#If
*/





