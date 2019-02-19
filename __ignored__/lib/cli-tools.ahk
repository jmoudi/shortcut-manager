#SingleInstance force
SetBatchLines, -1
#InstallKeybdHook
#InstallMouseHook
SetCapsLockState, Off
SetNumLockState, On
SetScrollLockState, Off
Menu, Tray, Icon, %A_ScriptDir%\lib\icons\main1.ico
#Include, %A_ScriptDir%\src\handlers.ahk
; ============================================== TOTAL REPLACEMENTS ============================================== ;
!s::enter("./sq.sh")
!c::enter("./create.sh")
!v::enter("./build.sh ./image-loader")
!b::enter("./build.sh")
!r::enter("./run.sh")
!f::enter("./start.sh")