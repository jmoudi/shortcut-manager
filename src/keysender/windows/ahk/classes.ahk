#Include %A_ScriptDir%/functions.ahk


 



class GuiWindow {
	__New(name, width, height){
		this.name := name
		this.setDimensions(width, height)
		this.setFont("Verdana", 10)
		this.setContent("")
		
	}
	setDimensions(width, height){
		this.width := width
		this.height := height
	}
	setFont(fonttype, fontsize){
		this.fonttype := fonttype
		this.fontsize := fontsize
	}
	setContent(content){
		this.content := content
	}

	show(x:=630, y:=500){
		global
		name := this.name
		content := this.content
		width := this.width
		height := this.height
		fonttype := this.font
		fontsize := this.size
		controlName := "Mainbox"
		Gui, %name%:New,, %name%
		Gui, %name%:Font, s%fontsize%, %fonttype%
		Gui, %name%:Add, Edit, v%controlName% Section w%width% h%height% x10 y10, %content%
		Gui, %name%:Show, x%x% h%y%
	}
}
arrayToString(params*){
	outputStr := ""
	for i, param in params {
		time := format("{1}:{2}:{3}", A_Min, A_Sec, A_MSec)
		line := format("`n({1}): {2} :     {3}", time, i, param)
		outputStr .= line
	}
	return outputStr
}
class Msg {

	stringify(params*){
		outputStr := ""
		for i, param in params {
			time := format("{1}:{2}:{3}", A_Min, A_Sec, A_MSec)
			line := format("`n({1}): {2} :     {3}", time, i, param)
			outputStr .= line
		}
		return outputStr
	}
	box(params*){
		window := new GuiWindow("Message", 500, 700)
		window.setContent(Msg.stringify(params*))
		window.show()
	}
}


class Powershell {
	start(){
		run("pwsh -WorkingDirectory ~")
	}
	startInCurrentDir(){
		currentPath := getCurrentExplorerPath()
		cmd := Format("pwsh -NoLogo -WorkingDirectory ""{1}""", currentPath)
		if (debug){
			MsgBox, comd "%cmd%"
		}
		run(cmd)
	}

}




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

class objdebug {

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

}