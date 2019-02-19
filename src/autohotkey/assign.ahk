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
	config := parseArgs(inputStr)
	showAll()
}

main()

