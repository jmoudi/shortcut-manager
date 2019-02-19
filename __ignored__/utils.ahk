


imprint(){
	global
	Critical
	BlockInput On
	ClipSaved := ClipboardAll
	Clipboard := ""
	Sleep 50
	if (Clipboard == ""){
		SendInput, ^c {Sleep 50}
		ClipWait, 1
		if (Clipboard != ""){
			total := "input=" . Clipboard . "key=c&modifier=1&method=p"
			;MsgBox %total%
			makeKey("!c", "paste", Trim(Clipboard), StrMethods)
		}
	}
	BlockInput Off
}
 

 
popupWhileKeyDown(){
}


	parse(inputStr){
		inputArray := StrSplit(inputStr, ",")
		RegExMatch(inputStr,"O)\b.*\B", match)
	}
    	quote(var){
		Critical
		;RegExReplace()
		Critical
		;E(Format(" ""{1}"" ", var))		
	}
	newtab(var){
		Critical
		string := A_Space . var
		SendInput, %string%{Sleep 80}
		SendInput, !{enter}
	}

    
Me3(params*){
	global
	name := "Message3"
	Gui, %name%:New, , %name%
	Gui, %name%:Font, s10, Verdana
	width := 500
	height := 700 ; h%height% x10
	for i, param in params {
		time := format("{1}:{2}:{3}", A_Min, A_Sec, A_MSec)
		line := format("`n({1}): {2} :     {3}", time, i, param)
		overview .= line
		Me1(line)
	}
	;MsgBox %overview%ddfg dgdfg
	;GuiControl, Text, Mainbox, %overview%  `n
	;Gui, %name%:Add, Edit, Section x10 y10 vMainbox, %overview%
	
	;Gui, %name%:Add, Edit, Section w500 h500 x10 y10, %Mainbox%

	Gui, %name%:Add, Edit, vMainbox Section w500 h500 x10 y10, %Mainbox%

	GuiControlGet, output,, %Mainbox% ; get Content of Editbox ATTENTION changing the varname makes it stop working
	Mainbox := overview

	;MsgBox %output% %Mainbox%
	;output := %overview%
	;MsgBox %output% %overview%
	;GuiControl, Text, %Mainbox%, %output%
	;Gui, %name%:Add, Text, xp yp+10 vMainbox, %overview%
	Gui, %name%:Show, x630 h500
}
 

 } catch Error {
	txt := Format("({1}):  ERROR LEVEL:{2}  LAST ERROR:{3}  ", A_NowUTC, ErrorLevel, A_LastError)
	MsgBox % txt + A_WorkingDir
	;FileAppend, %txt%, %A_WorkingDir%\log.txt
} 

_sendToActive(var, options := ""){
	Critical
	if (!WinActive("ahk_exe Code.exe")){
		SetKeyDelay, 3ms
		SendInput, %var%
		if (options == "enter"){
			SendInput, {Sleep 20}{Enter}
		}
	}
	if (WinActive("ahk_exe Code.exe")){
		MsgBox "minimize code first!"
	}
}