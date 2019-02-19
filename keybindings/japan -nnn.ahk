#SingleInstance force
SetBatchLines, -1
#InstallKeybdHook
#InstallMouseHook
SetCapsLockState, Off
SetNumLockState, On
SetScrollLockState, Off
Menu, Tray, Icon, %A_ScriptDir%\lib\icons\JPN.ico
#Include, %A_ScriptDir%\lib\handlers.ahk


#If (!WinActive("ahk_exe Code.exe"))
	!c::enter(" ニーソ OR ニーソックス ")
    !+c::paste("キャミ")
	!d::enter(" ニーソ OR ニーソックス OR ニーハイソックス ")
	!s::enter("キャミソール")
	!+s::paste(" ニーハイソックス ")
	!^s::paste("インナー キャミ")
	; *************** FIND ***************
	!x::find("ニーソッ")
	!+x::find("ショーツx")
	!^x::find("スリップ")
	!<^>x::find("旗袍")
	!y::find("ニーハイx")
	!+y::find("ショーツx")
	!^y::find("ブラウスx")
	; *************** MIDDLE ***************
	!f::enter("ニーソ")
	!+f::paste("ニーソ")
	!^f::enter("罗马鞋")
	!g::enter(" ニーソックス ")
	!+g::paste("キャミワンピース")
	!^g::paste("罗马 鞋")
	!h::enter("ブラウス ")
	!+h::paste("ブラウス ")
	!^h::paste("(space)羅馬 鞋(space)")
	!j::paste("シュミーズ キャミソール")
	!k::paste("一字 OR 一字扣带 OR 一字带 OR 一字扣 OR 一字式扣带")
	!l::paste("-taobao.com -site:tmall.com -sit!e688.com -site:jd.com -youzan.com -z!h26.com -56.de -wadonxi")
	!v::enter("ニーハイ")
	!+v::paste("パンプス")
	!b::paste("ショーツ")
	!n::paste("旗袍 改良旗袍 日常")
	!m::paste("スリップ")
	!+m::paste("衬衫")
	!^m::paste("针织衫")
	!i::paste("半身裙")
	!+i::paste("褶裙")
	!^i::paste("半身裙")
	!+z::paste("旗袍 改良旗袍 日常")
	!^z::paste("罗马 鞋")
#If