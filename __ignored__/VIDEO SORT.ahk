!y::
SendInput ^s
Sleep 100
Reload
Return



MouseGetPos, , , , OutputVarControl
Return
;##################################################################
!s::SendInput {esc}

;##################################################################
!d::
SendInput {esc}
Sleep 100
SendInput {right}{Enter}
Return
;##################################################################

!c::
SendInput ^{PgDn}
Sleep 400
	Loop 8
	{
	SendInput {Right}
	Sleep 600
	}
Sleep 1000
SendInput {esc}
Sleep 100
Return


!g::
Loop 5
{
Sleep 300
	Loop 8
		{
		SendInput {Right}
		Sleep 300
		}
Sleep 500
SendInput ^{PgDn}
}
Return

;##################################################################

!a::
SendInput {esc}
Sleep 100
SendInput {left}{Enter}
Return


;##################################################################

#IfWinActive ahk_class MediaPlayerClassicW
!x::
{
Loop 8
	{
	SendInput {Right}
	Sleep 200
	IfWinNotActive ahk_class MediaPlayerClassicW
		break
	}
}
Return

;##################################################################
Numpad7::
Sendinput {esc}
Sleep 100
SendInput {left}{Enter}
Return
;##################################################################

 





!Numpad1::
Loop 3
{
SendInput {Numpad1}
}
Return

!Numpad2::
Loop 3
{
SendInput {Numpad2}
}
Return




 
