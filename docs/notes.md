#
##
### WEBEXT

 


```scheme
(xbindkey '(shift a) "xsel -v --clipboard --output --selectionTimeout 3000")
(xbindkey '(shift z) "xbindkeys_show")
(xbindkey '(shift x) "xsel --clipboard --output --selectionTimeout 3000")
(xbindkey '(shift c) "xclip -out -selection 'clipboard'")
(xbindkey '(shift v) "xclip -verbose -out -loops 3 -selection 'clipboard'")
(xbindkey '(shift b) "xclip -out -loops 3 -selection 'clipboard'")
(xbindkey '(shift n) "xbindkeys --show")
(xbindkey '(alt v) "xsendkey Control+Shift+T")

(xbindkey-function '(shift a)
		   (lambda ()
      ))
```
sudo python customizable_hotkey.py
wmctrl -l | awk '{print $0}'
wmctrl -l | awk '{print $0 $1 $2}'
wmctrl -l | awk 'firefox'
wmctrl -l | awk {^.*firefox.*$}
ls -l /usr/bin | awk '{print $0}'

sudo python key.py 
python scripting.py
wine AutoHotkeyU64.exe test/test.ahk

Otherwise, bind wmctrl or xdotool to a hotkey via kcmshell5 khotkeys. Those commands can activate a window found by class or title patterns.




sudo python key.py 

pref("intl.ime.hack.on_any_apps.fire_key_events_for_composition", true);
#else // #ifdef EARLY_BETA_OR_EARLIER
pref("intl.ime.hack.on_any_apps.fire_key_events_for_composition", false);
#endif // #ifdef EARLY_BETA_OR_EARLIER #else
// If true and the above pref is false, dispatch the keydown and keyup events
// only on IME-unaware web apps.  So, this supports web apps which listen to
// only keydown or keyup event to get a change to do something at every text
// input.
pref("intl.ime.hack.on_ime_unaware_apps.fire_key_events_for_composition", true);
#else // #ifdef MOZ_WIDGET_ANDROID
pref("intl.ime.hack.on_any_apps.fire_key_events_for_composition", false);
pref("intl.ime.hack.on_ime_unaware_apps.fire_key_events_for_composition", false);



There are three special shortcuts:

    _execute_browser_action: works like a click on the extension's browser action.
    _execute_page_action: works like a click on the extension's page action.
    _execute_sidebar_action: opens the extension's sidebar. Only supported in Firefox, and only from Firefox version 54.

For example, this defines a key combination to click the extension's browser action:


gecko-ce comman
gecko-ce comman



<!DOCTYPE html>

<html>
  <head>
    <meta charset="utf-8">
  </head>

<body>
  <form>
      <label>Keyboard shortcut</label>
      <input type="text" id="shortcut" >
      <button id="update">Update keyboard shortcut</button>
      <button id="reset">Reset  keyboard shortcut</button>
  </form>
  <script src="options.js"></script>
</body>



{
  "name": "Sample Commands Extension",
  "description": "Press Ctrl+Shift+U to send an event (Command+Shift+U on a Mac).",
  "homepage_url": "https://github.com/mdn/webextensions-examples/tree/master/commands",
  "manifest_version": 2,
  "version": "1.0",

  "applications": {
    "gecko": {
      "id": "commands-demo@mozilla.org",
      "strict_min_version": "60.0b5"
    }
  },

  "background": {
    "scripts": ["background.js"]
  },

  "commands": {
    "toggle-feature": {
      "suggested_key": { "default": "Ctrl+Shift+U" },
      "description": "Send a 'toggle-feature' event to the extension"
    }
  },

  "options_ui": {
    "page": "options.html",
    "browser_style": true
  }
}
</html>




### INTERAL XUL
https://w3c.github.io/uievents/#interface-keyboardevent

```javascript
 KeyboardEvent

[Constructor
(DOMString type
, optional KeyboardEventInit eventInitDict
), Exposed=Window]
interface KeyboardEvent : UIEvent {
  // KeyLocationCode
  const unsigned long DOM_KEY_LOCATION_STANDARD = 0x00;
  const unsigned long DOM_KEY_LOCATION_LEFT = 0x01;
  const unsigned long DOM_KEY_LOCATION_RIGHT = 0x02;
  const unsigned long DOM_KEY_LOCATION_NUMPAD = 0x03;

  readonly attribute DOMString key;
  readonly attribute DOMString code;
  readonly attribute unsigned long location;

  readonly attribute boolean ctrlKey;
  readonly attribute boolean shiftKey;
  readonly attribute boolean altKey;
  readonly attribute boolean metaKey;

  readonly attribute boolean repeat;
  readonly attribute boolean isComposing;

  boolean getModifierState(DOMString keyArg
);
};

```


chrome://global-platform/locale/platformKeys.properties
chrome://global/locale/keys.properties                              


  <p>This test examines the ARIA properties for keyshortcuts multiple shortcuts.</p>
    <body>
     <div id="test" tabindex="0" role="button" aria-keyshortcuts="Shift+Space Alt+Space">Submit</h1>
  </body>

  <div id="manualMode"></div>
  <div id="log"></div>
  <div id="ATTAmessages"></div>
