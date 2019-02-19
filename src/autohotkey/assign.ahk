#SingleInstance force
SetBatchLines, -1
#InstallKeybdHook
#InstallMouseHook
SetCapsLockState, Off
SetNumLockState, On
SetScrollLockState, Off
;Menu, Tray, Icon, %A_ScriptDir%\lib\icons\CHN.ico

#Include %A_ScriptDir%/actions.ahk
#Include %A_ScriptDir%/app.ahk

global assigned_keys := {}


show(obj){
	str := ""
	for key, val in obj {
		str .= "KEY:( " . key . " )    CMD:(" . val.command . ")    VALUE:(" . val.value . ")    ISOBJECT:(" . IsObject(val) . ") `n"
	}
	MsgBox % "Stringified Object:`n" . str
}
showOne(){
	str := "KEY" . key . "COMMAND" . command . "VALUE" . value "`n"
	MsgBox %str%
}
showAll(){
	str := ""
	for key, val in assigned_keys {
		str .= "KEY:( " . val.key . " )    CMD:(" . val.command . ")    VALUE:(" . val.value . ")    ISOBJECT:(" . IsObject(val) . ") `n"
	}
	MsgBox % "Stringified Object:`n" . str
}


parseArgs(inputStr){
	global
	for index, inputStr in StrSplit(inputStr, ";"){
		if (StrLen(inputStr) > 0){
			;MsgBox %queryStr%
			
			KeyArray := StrSplit(inputStr, ",")
			; init := { key: KeyArray[1], command: KeyArray[2], value: KeyArray[3] }
			key := KeyArray[1]
			command := KeyArray[2]
			value := KeyArray[3]
			;Loop % KeyArray.MaxIndex()
			assigned_keys[key] := new Hotkey(key, command, value)
		}
	}

	return config
}





main(){
	global
	inputStr = %1%
	config := parseArgs(inputStr)
	showAll()
	/*for i, init in config {
		assigned_keys[init["key"]] := new Hotkey(init["key"], init["command"], init["value"])
	}
	Parse.show(assigned_keys)
	MsgBox %arg% 
	*/
}

;main("+c,paste,abbbbb;!d,paste,kkkkk") ;!f,find,rrrr;")
main()

