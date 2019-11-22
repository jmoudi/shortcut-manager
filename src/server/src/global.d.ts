interface HotkeyConfig {
    key: string[];
    command: string;
    args: string[]
}


type Callback = (...args: any[]) => any;

interface ShortcutInit {
  id?: number;
  keys: string[];
  action: Callback;
}