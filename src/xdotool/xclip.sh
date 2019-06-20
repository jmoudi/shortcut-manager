

bash /home/jm/Projects/Apps/BashScripts/src/xdotool/xclip_run.sh "ooooo"

Usage: xclip [OPTION] [FILE]...
Access an X server selection for reading or writing.

  -i, -in          read text into X selection from standard input or files
                   (default)
  -o, -out         prints the selection to standard out (generally for
                   piping to a file or program)
  -l, -loops       number of selection requests to wait for before exiting
  -d, -display     X display to connect to (eg localhost:0 
  -h, -help        usage information
      -selection   selection to access ("primary", "secondary", "clipboard" or "buffer-cut")
      -noutf8      don t treat text as utf-8, use old unicode
      -target      use the given target atom
      -rmlastnl    remove the last newline charater if present
      -version     version information
      -silent      errors only, run in background (default)
      -quiet       run in foreground, show wha s happening
      -verbose     running commentary

function writeToClipboard(){
    local input="$1"
    echo $input | xclip -sel clip
}; writeToClipboard "aaaaa"; xclip -o -selection clipboard



function paste(){
    local input="$1"
    echo $input | xclip -sel clip
}; writeToClipboard "aaaaa"

function read_into_clipboard(){
    echo "ooooo" | xclip -sel clip
};

xclip -o -sel clip

xclip -i -sel clip dssdfdsf

xclip -i -verbose

[jm@jm-pc ~]$ xterm -help
XTerm(344) usage:
    xterm [-options ...] [-e command args]
 