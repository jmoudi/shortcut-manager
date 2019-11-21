#SingleInstance force
#Persistent
SetBatchLines, 200ms
Menu, Tray, Icon, %A_ScriptDir%/icons/main2.ico
SetTitleMatchMode 2
#Hotstring NoMouse
#Hotstring c*
#WinActivateForce

; ============================================== SOFTWARE ============================================== ;
#If WinActive("ahk_exe honeyview.exe")
	NumpadEnter::Space ;# Down/Page-turn
    Numpad0::Space ;# Down/Page-turn
    Numpad7::F11 ;# Maximize/Minimize
    Numpad3::F11 ;# Maximize/Minimize
    Numpad1::Left ; Left
    Numpad2::Right ; Right
    NumpadDot::Up ; Up
#If WinActive("Library")
	$!s::SendInput, {Delete}
#If WinExist("ahk_exe foobar2000.exe")
	$!y::!F3
#If WinActive("ahk_class MediaPlayerClassicW")
	;$!c::Deleter(Approved)
	Space::Numpad0


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

; ============================================== PROGRAMMING ============================================== ;
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

; ============================================== GAMES ============================================== ;

#IfWinActive, ahk_exe Dangan3Win.exe
    C::P
    F::F1
    1::F1
    2::F1
    3::F2
    4::F2
    5::F3
    CapsLock::Tab
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
*/

#If

