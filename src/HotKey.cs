[DllImport("user32.dll")]
public static extern bool RegisterHotKey(IntPtr hWnd, int id, int fsModifiers, int vlc);
[DllImport("user32.dll")]
public static extern bool UnregisterHotKey(IntPtr hWnd, int id);

protected override void WndProc(ref Message m)
{
    if (m.Msg == 0x0312)
    {
        //TODO: action here.
    }
    base.WndProc(ref m);
}

...

//Adds a Shortcut (Hot key) to the combination: Ctrl+Q
public void FunctionName()
{
    // Alt = 1, Ctrl = 2, Shift = 4, Win = 8
    MainForm.RegisterHotKey(this.Handle,
        this.GetType().GetHashCode(), 2, (int)'Q');
}