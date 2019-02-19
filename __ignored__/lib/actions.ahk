
#If !WinActive("ahk_exe code.exe")
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
#If