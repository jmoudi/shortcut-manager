﻿#SingleInstance force
SetBatchLines, -1
#InstallKeybdHook
#InstallMouseHook
SetCapsLockState, Off
SetNumLockState, On
SetScrollLockState, Off
Menu, Tray, Icon, %A_ScriptDir%\lib\icons\CHN.ico
#Include, %A_ScriptDir%\lib\ahk\handlers.ahk

#If (!WinActive("ahk_exe Code.exe"))
	!c::enter("キャミ") ("发发型 ") ;"鱼嘴 坡跟 凉鞋")
	!d::enter("ショーツ")
	!+d::paste("鲍勃")
	!s::find("キャミ")
	!+s::find("ショーツ")
	!^s::find("罗马鞋 OR 罗马凉鞋 OR 罗马女鞋 OR 罗马高跟鞋")
	; *************** FIND ***************
	!x::find("ボブ") ; 波波")
	!+x::find("發發")
	!^x::find("髮髮")
	!<^>x::find("旗袍")
	!y::find("bob") ; 鲍勃 髮髮型
	!+y::find("lob")
	!^y::find("lob")
	; *************** MIDDLE ***************
	!f::enter("ボブ")
	!+f::paste("罗马")
	!^f::enter("罗马鞋")
	!g::enter(" キャミソール ")
	!+g::paste("キャミソール")
	!^g::paste("罗马 鞋")
	!h::enter(" キャミ")
	!+h::paste("發發")
	!^h::paste("(space)羅馬 鞋(space)")
	!j::paste(" 羅馬鞋 OR 羅馬涼鞋 OR 羅馬女鞋 OR 羅馬高跟鞋 ")
    !+j::paste("單鞋")
	!k::paste("一字 OR 一字扣带 OR 一字带 OR 一字扣 OR 一字式扣带")
	!l::paste("-taobao.com -site:tmall.com -site:1688.com -site:jd.com -youzan.com -zh26.com -56.de -wadonxi -suning")
	!v::enter("凉鞋")
	!+v::paste("凉鞋")
	!b::paste("单鞋", "浅口鞋","高跟鞋")
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