import keyboard

print('Press and release your desired shortcut: ')
shortcut = keyboard.read_hotkey()
print('Shortcut selected:', shortcut)

def on_triggered():
	print("Triggered!")
	keyboard.write("rayt")

def wr():
    keyboard.write('foobar')

def main():
    key = keyboard.get_hotkey_name(['shift', 'alt', 'c'])
    print('main', key)
    keyboard.add_hotkey('alt+f', lambda: keyboard.write('foobar'))
    keyboard.add_hotkey(key, on_triggered)

main()


print("Press ESC to stop.")
keyboard.wait('esc')