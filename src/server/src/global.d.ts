interface HotkeyConfig {
    key: string[];
    command: string;
    args: string[]
}


type Action = <T = any>(...args: T[]) => void|Promise<void>;
type Callback = (...args: any[]) => any;

interface ShortcutInit {
  id?: number;
  keys: string[];
  action: Callback;
}