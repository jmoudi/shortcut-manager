#SingleInstance force
SetBatchLines, -1
#InstallKeybdHook
#InstallMouseHook
SetCapsLockState, Off
SetNumLockState, On
SetScrollLockState, Off
Menu, Tray, Icon, %A_ScriptDir%\lib\icons\CHN.ico
#Include, %A_ScriptDir%\lib\handlers.ahk


#If (!WinActive("ahk_exe Code.exe"))
	!c::enter("罗马") ;"鱼嘴 坡跟 凉鞋")
	!d::enter("罗马 鞋")
    !+d::enter(" 罗马鞋 OR 罗马凉鞋 OR 罗马高跟鞋 ")
	!^d::paste(" 罗马 高跟 ")
	!s::enter("罗马鞋 OR 罗马凉鞋 OR 罗马女鞋 OR 罗马高跟鞋 OR 罗马粗跟鞋 OR 罗马中跟鞋")
	!+s::paste("罗马鞋 OR 罗马凉鞋 OR 罗马女鞋 OR 罗马高跟鞋 OR 罗马粗跟鞋 OR 罗马中跟鞋")
	!^s::paste("罗马鞋 OR 罗马凉鞋 OR 罗马女鞋 OR 罗马高跟鞋")
	; *************** FIND ***************
	!x::find("罗马")
	!+x::find("单鞋")
	!^x::find("鱼嘴")
	!<^>x::find("旗袍")
	!y::find("羅馬")
	!+y::find("單鞋")
	!^y::find("高跟")
	; *************** MIDDLE ***************
	!f::enter("罗马")
	!+f::paste("罗马")
	!^f::enter("罗马鞋")
	!g::enter("罗马 鞋")
	!+g::paste("罗马 鞋")
	!^g::paste("旗袍")
	!h::enter("羅馬")
	!+h::paste("羅馬")
	!^h::paste("(space)羅馬 鞋(space)")
	!^j::paste(" 羅馬鞋 OR 羅馬涼鞋 OR 羅馬女鞋 OR 羅馬高跟鞋 ")
    !+j::paste("單鞋")
    !j::enter("鱼嘴")
	!k::paste("一字 OR 一字扣带 OR 一字带 OR 一字扣 OR 一字式扣带")
	!l::paste("-taobao.com -site:tmall.com -site:1688.com -site:jd.com -youzan.com -zh26.com -56.de -wadonxi -suning")
	!v::enter("凉鞋")
	!+v::paste("凉鞋")
	!b::paste("单鞋", "浅口鞋","高跟鞋")
	!n::paste("旗袍 改良 日常")
	!m::paste("上衣")
	!+m::paste("衬衫")
	!^m::paste("针织衫")
	!i::paste("半身裙")
	!+i::paste("褶裙")
	!^i::paste("半身裙")
	!+z::paste("旗袍 改良旗袍 日常")
	!^z::paste("罗马 鞋")
#If