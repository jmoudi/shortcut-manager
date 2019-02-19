

class Actions {

	paste(var){
		Global
		Critical
		if (!WinActive("ahk_exe code.exe") && (WinActive("ahk_exe firefox.exe") || WinActive("ahk_exe chrome.exe"))){
			SendInput, %var%{Sleep 20}
		}
	}

	enter(var){	
		;Global
		;Critical
		;MsgBox %var%
		if (!WinActive("ahk_exe code.exe")){
		;if (!WinActive("ahk_exe code.exe") && (WinActive("ahk_exe firefox.exe") || WinActive("ahk_exe chrome.exe"))){
			SendInput, %var%{Sleep 20}
			SendInput, {Enter}
		}
	}
	find(inpString){
		Critical
		If ( StrLen(inpString := StrReplace(inpString, " ")) >= 3)
			StringTrimRight, inpString, inpString, 1
		browser := WinExist("ahk_exe firefox.exe")
		PostMessage, 0x08,,,,%browser% ; kill focus
		BlockInput On
		SendEvent, ^f{Sleep 20} ; ^{Home}{End}{F3}
		;If InStr(inpString, "+")
		;	SendInput, {raw}%inpString%  ; SendEvent, ^f%inpString% ;{enter}{Sleep20}
		;Else
		SendInput, %inpString%^g{Sleep 200}  ; SendEvent, ^f%inpString% ;{enter}{Sleep20}
		
		BlockInput Off
		;PostMessage, 0x100, 0x0D, 0, , %title%
		;SendInput, ^f{Sleep 50}+^{Right}{Sleep 30}%output%{enter}{Sleep 150};SendInput, %inpString%{Sleep 50}
		Sleep 100
		Return
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


 
class Parse {
	parseArgs(paramStr){
		config := {}
		for index, queryStr in StrSplit(paramStr, ";"){
			if (StrLen(queryStr) > 0){
				;MsgBox %queryStr%
				init := Parse.parseKey(queryStr)
				config[init["key"]] := init
			}
		}
		return config
	}
	parseKey(inputStr){
		init := {}
		for i, param in StrSplit(inputStr, ","){
			init := { key: param[1], command: param[2], value: param[3] }
			;MsgBox % param[1]
			;init["key"] := param[1]
			;init["command"] := param[2]
			;init["value"] := param[3]
		}
		for i,p in init {
			MsgBox % p
		}
		;MsgBox % init["key"]
		return init
	}

	show(obj){
		str := ""
		for key, val in obj {
			str .= "KEY:( " . key . " )    CMD:(" . val.command . ")    VALUE:(" . val.value . ")    ISOBJECT:(" . IsObject(val) . ") `n"
		}
		MsgBox % "Stringified Object:`n" . str
	}
}

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




/*
		if (init){
			msg := init["key"] . init["command"] . init["input"]
			MsgBox aaa %msg%
		}

if (key == "key"){
	msg .= "---" . value
}
if (key == "command"){
	msg .= "-zzzz-" . value
}
if (key == "params"){
	msg .= "iiiiii" . value
}
*/
