
  
Set-ExecutionPolicy -Scope LocalMachine -ExecutionPolicy Bypass -Force 
$KEYBINDINGS_PATH = "D:\Projects\Apps\hotkey-manager\src\keysender/windows/ahk"

function exec([string[]]$arglist){
    ## IMPORTANT: must be started as admin
    ##Debug-Process -Name "AutoHotkey*"
    $cmd = "autohotkey"
    $proc = Start-Process "autohotkey" -ArgumentList @("main.ahk") -WorkingDirectory $KEYBINDINGS_PATH -PassThru -Verbose -RedirectStandardError "ahk.log" #exec $args
    if ($proc.ExitCode -gt 0){ ThrowError -ExceptionObject @{cmd=$cmd} } 
    return $ahk
}

class AHK {
    run(){
        #-ArgumentList @("runtime.ahk", ...otherScripts)
    }
}
function startAutohotkey() {
    $args = @("main.ahk")
    try {
        $proc = Start-Process "autohotkey" -ArgumentList @("main.ahk") -WorkingDirectory $KEYBINDINGS_PATH -PassThru -Verbose -RedirectStandardError "ahk.log" #exec $args
    } catch {
        Write-Error $Error[0].CategoryInfo $Error[0].ErrorDetails -TargetObject $proc
        return
    }
    Write-Host "SUCCESSFULLY STARTED WITH ARGS: $args"
} 
startAutohotkey


Write-Error $StackTrace

function exec2([Array[string]]$arglist){
    Start-Process "autohotkey" -ArgumentList @("main.ahk") -WorkingDirectory $KEYBINDINGS_PATH -Verbose
    $LastExitCode

    $MyInvocation
    $PSCommandPath
    $PSDebugContext
    ## IMPORTANT: must be started as admin
    $ahk = Start-Process -FilePath "autohotkey" -ArgumentList $arglist -WorkingDirectory $KEYBINDINGS_PATH -Verb RunAs -WindowStyle  Hidden -PassThru -Verbose; 
    #runas /user:Administrator
    #Invoke-Command
} 