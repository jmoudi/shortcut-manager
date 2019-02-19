#SingleInstance force
SetBatchLines, -1
#InstallKeybdHook
#InstallMouseHook
SetCapsLockState, Off
SetNumLockState, On
SetScrollLockState, Off
Menu, Tray, Icon, %A_ScriptDir%\lib\icons\JPN.ico
#Include, %A_ScriptDir%\lib\ahk\handlers.ahk


ガーターニーソ

#If (!WinActive("ahk_exe Code.exe"))
	!c::enter("キャミ")
    !+c::paste("キャミ")
	!d::enter("ニーソ")
	!+d::paste("ニーソ")
	!s::enter("{space}ニーソ OR ニーソックス{space}")
	!^s::paste("{space}ニーソ OR ニーソックス{space}")
	!+s::paste("{space}ニーソ OR ニーソックス OR ニーハイソックス{space}")
	; *************** FIND ***************
	!x::find("ニーソッ")
	!+x::find("ソックス")
	!^x::find("ニーソックス")
	!<^>x::find("旗袍")
	!y::find("パンプス")
	!+y::find("單鞋")
	!^y::find("高跟")
	; *************** MIDDLE ***************
	!f::enter("ニーソックス")
	!+f::paste("キャミソール")
	!^f::enter("ニーハイソックス")
	!g::enter("キャミドレス")
	!+g::paste("キャミワンピース")
	!^g::paste("罗马 鞋")
	!h::enter("ニーハイソックス")
	!+h::paste("羅馬")
	!^h::paste("(space)羅馬 鞋(space)")
	!j::paste(" 羅馬鞋 OR 羅馬涼鞋 OR 羅馬女鞋 OR 羅馬高跟鞋 ")
	!k::paste("一字 OR 一字扣带 OR 一字带 OR 一字扣 OR 一字式扣带")
	!l::paste("-taobao.com -site:tmall.com -sit!e688.com -site:jd.com -youzan.com -z!h26.com -56.de -wadonxi")
	!v::enter("パンプス")
	!+v::paste("パンプス")
	!b::paste("ショーツ")
	!n::paste("旗袍 改良旗袍 日常")
	!m::paste("上衣")
	!+m::paste("衬衫")
	!^m::paste("针织衫")
	!i::paste("半身裙")
	!+i::paste("褶裙")
	!^i::paste("半身裙")
	!+z::paste("旗袍 改良旗袍 日常")
	!^z::paste("罗马 鞋")
#If