#SingleInstance force
SetBatchLines, -1
#InstallKeybdHook
#InstallMouseHook
SetCapsLockState, Off
SetNumLockState, On
SetScrollLockState, Off
;Menu, Tray, Icon, %A_WorkingDir%\Icons\main1.ico
; =======================================================================================
sendKey(string){
    Critical
    SendMode Input
    SendRaw %string%
    return
}
; ============================================== TOTAL REPLACEMENTS ============================================== ;

LWin::LCtrl

´::'
NumpadDot::.
F1::!F1
F12::!F11
CapsLock::Enter
NumLock::RAlt
;F12::Run Calc.exe
Alt::Return
^'::sendKey("``")
!'::sendKey("´")
!ü::è ; è U+00E8, È U+00C8
!ö::é ; é U+00E9, É U+00C9
!ä::à ; à U+00E0, À U+00C0
<^>!+ü::ç ; ç U+00E7, Ç U+00C7

<^>!q::sendKey("@")
+!q::SendInput, @
^q::SendRaw, @

/*

!ü::sendKey("è") ; è U+00E8, È U+00C8
!ö::sendKey("é") ; é U+00E9, É U+00C9
!ä::sendKey("à") ; à U+00E0, À U+00C0
<^>!+ü::sendKey("ç") ; ç U+00E7, Ç U+00C7
*/
; ============================================== GENERAL ============================================== ;

#If (WinActive("ahk_exe mintty.exe"))
    ^v::SendInput +{Insert}
    ;^f::Send +{Insert}
    !s::
    SendInput git clone {Space}^v
    SendInput {Enter}
#If (!WinActive("ahk_exe everything.exe"))
    !y::SendInput !z
    !z::SendInput !y

#If (!WinActive("ahk_exe Code.exe"))
    !q::SendInput ^{PgUp}
    !w::SendInput ^{Home}
    !e::SendInput ^{PgDn}
    !r::SendInput !{Left}
    !t::SendInput !{Right}
    !1::SendInput {F2}
    !2::SendInput ^{w}
    !3::SendInput {F5}
    !4::SendInput site:
    +!4::SendInput inurl:
    !5::SendInput intitle:
    +!5::SendInput inanchor:"
    ^+r::SendInput ^+{j} 
    ^#a::Run %A_WorkingDir%\ahk_START_ALL.bat
#If WinActive("ahk_exe everything.exe")
    ^t::sendKey("t") ; disable "Always on Top"
; ============================================== BROWSERS ============================================== ;
#If WinActive("ahk_exe firefox.exe")
	;$!c::Saver() ;$+d::Saver()
#If WinActive("ahk_exe chrome.exe")
	Hotkey, $!LButton, %nofunc%, B0 P5 T5 ;$+d::Saver()
	^+c::^+i
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

