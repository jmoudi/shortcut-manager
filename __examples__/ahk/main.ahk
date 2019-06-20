#SingleInstance force
SetBatchLines, -1
#InstallKeybdHook
#InstallMouseHook
SetCapsLockState, Off
SetNumLockState, On
SetScrollLockState, Off
Menu, Tray, Icon, %A_ScriptDir%/../assets/icons/CHN.ico
#Include %A_ScriptDir%/actions.ahk
#Include %A_ScriptDir%/app.ahk

global assigned_keys := {}


main(){
	global
	inputStr = %1%
	debug = %2%
	config := parseArgs(inputStr)
	if (debug == "--debug"){
		showAll()
	}
	
}
MsgBox, start
main()

