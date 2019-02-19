

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

; =======================================================================================

class Hotkey {
	__New(key, command, value){
		Global
		this.key := key
		this.command := command
		this.value := value
		if (StrLen(key) > 0){
			funcObj := ObjBindMethod(Actions, command, value)
			Hotkey, %key%, %funcObj%, B0 P5 T5
		}
	}
}

 