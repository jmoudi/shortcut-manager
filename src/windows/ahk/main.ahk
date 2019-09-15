#SingleInstance force
#InstallKeybdHook
#InstallMouseHook
SetBatchLines, -1
SetCapsLockState, Off
SetNumLockState, On
SetScrollLockState, Off
SetTitleMatchMode, 2 ;2: A window's title can contain WinTitle anywhere inside it to be a match. 

;Menu, Tray, Icon, %A_ScriptDir%/../assets/icons/CH.ico


global debug := 0
global assigned_keys := {}

load(){
	global
	for n, param in A_Args  ; For each parameter:
	{
		if (param == "--debug"){
			debug := 1
		}
		script := A_Args[0]
		firstParam := A_Args[1]
		
	}
	;MsgBox ddd %script% %firstParam%.
}
load()
#Include %A_ScriptDir%/functions.ahk
#Include %A_ScriptDir%/classes.ahk
;#Include %A_ScriptDir%/app.ahk
#Include %A_ScriptDir%/default.ahk




pp(){
	Args = %A_Args%
	aa := Args[0]
	bb := Args[1]
	MsgBox "%aa%"
	MsgBox "%bb%"
}
;pp()
 




main(){
	global
	inputStr = %1%
	debugArg = %2%
	MsgBox, debugArg "%debugArg%"
	config := parseArgs(inputStr)
	if (debugArg == "--debug"){
		
		debug := 1
		MsgBox, debugArg "%debug%"
		;showAll()
	}
	
}
;MsgBox, start
;main()

