
$psexe = Join-path $PWD "powershell.exe"
Debug-Process -Name "AutoHotkey*"
write-Host { 
    $STACKTRACE
    $ErrorView
    $EXECUTIONCONTEXT
    $STACKTRACE
    $MYINVOCATION
    $ERROR
    $EXECUTIONCONTEXT
}
write-Host "autoHotkey" $autoHotkey


 function traceError(){
    Write-Host {
        Message="AUTOHOTKEY"
        $ERROR
        $STACKTRACE
        $ErrorView
        $EXECUTIONCONTEXT
        $STACKTRACE
        $MYINVOCATION
        $EXECUTIONCONTEXT
    }
 }

 $KEYBINDINGS_PATH = "D:\Projects\Apps\hotkey-manager\src\ahk"
 function exec([Array[string]]$arglist){
    ## IMPORTANT: must be started as admin
    $ahk = Start-Process -FilePath "autohotkey" -ArgumentList $arglist -WorkingDirectory $KEYBINDINGS_PATH -Verb RunAs -WindowStyle  Hidden -PassThru -Verbose; 
    #runas /user:Administrator
    #Invoke-Command
}
function startAutohotkey() {
    $args = @("main.ahk")
    try {
        exec $args
    } catch {
        traceError
    }
    Write-Host "SUCCESSFULLY STARTED WITH ARGS: $args"
    Start-Process -FilePath .\Run-AHK.ps1 -Wait 
     #Start-Process "autohotkey.exe" -ArgumentList "build" -WindowStyle "hidden" -WorkingDirectory $path
    Write-Host "Finished " + $ru;
}
