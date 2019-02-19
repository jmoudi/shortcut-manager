import keyboard




def assign():
    print("Assinging key bindings ...")
    keyboard.add_hotkey('shift+d', lambda: keyboard.write('foobar'))
    


assign()