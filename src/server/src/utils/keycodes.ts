import keycode from 'keycode';

keycode.names[13] // => 'enter'
keycode.codes['enter'] // => 13

// assume event is an keydown event with key 'enter'
keycode.isEventKey(event, 'enter') // => true
keycode.isEventKey(event, 'down') // => false

keycode.isEventKey(event, 13) // => true
keycode.isEventKey(event, 40) // => false