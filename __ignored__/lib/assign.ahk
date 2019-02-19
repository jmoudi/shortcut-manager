

 
class Parse {
	args(paramStr){
		config := {}
		for index, queryStr in StrSplit(paramStr, ";"){
			if (StrLen(queryStr) > 0){
				init := Parse.query(queryStr)
				config[init["key"]] := init
			}
		}
		return config
	}
	query(queryStr){
		init := {}
		for i, param in StrSplit(queryStr, "&"){
			keyVal := StrSplit(param, "=")
			key := keyVal[1]
			value := keyVal[2]
			init[key] := value
		}
		return init
	}

	show(obj){
		str := ""
		for key, val in obj {
			str .= "KEY:( " . key . " )    CMD:(" . val.command . ")    INPUT:(" . val.input . ")    ISOBJECT:(" . IsObject(val) . ") `n"
		}
		MsgBox % "Stringified Object:`n" . str
	}
}

class Hotkey {
	__New(key, command, input){
		Global
		this.key := key
		this.command := command
		this.input := input
		if (StrLen(key) > 0){
			funcObj := ObjBindMethod(Actions, command, input)
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
