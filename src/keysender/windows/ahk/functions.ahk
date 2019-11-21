


run(cmd, args:=""){
	critical
	runcmd := format("{1} {2}", cmd, args)
	Run, %runcmd%
}

getActiveProcesspath(){
	UniqueID := WinActive("ahk_exe Explorer.EXE")
	WinGetActiveTitle, activeTitle
 	WinGet, processPath, ProcessPath, "%activeTitle%"
	;aa := ahk_id
	MsgBox, The active ProcessPath is "%processPath%".
	;Me3(UniqueID)

}
getCurrentExplorerPath(){
	explorerID := WinActive("ahk_exe Explorer.EXE")
	if (explorerID){
		ControlGetText, currentLocation, Edit1 ; "Edit1" points to the window control element that contains the full path of the current directory
		return currentLocation
	}
}
; =======================================================================================
sendKey(string){
    Critical
    SendMode, Input
    SendRaw %string%
    return
}

paste(params*){
	Actions.paste(params*)
}
enter(params*){
	Actions.enter(params*)
}
find(params*){
	Actions.find(params*)
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


 