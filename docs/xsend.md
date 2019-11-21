hanks for the help!
I believe that a full description of the problems I ran into might help others.  Here goes:

-Definately check out the programs mentioned by erb.  It was invaluable.

-The window that you send to and the windows mentioned in the XEvent structure that one sends must be correct.  All events propagate up towards the root window until that are grabbed by an interested window.  Thus you must send to the window you are interested in communicating with.

-AllowSendEvent  will cause some hassles.  I have it working for most application now.  I am still working on the window manager so that it will accept my events properly.  Make sure to check resources if all else fails.

-Make sure to use XFlush() so that your XSendEvent will be
executed.

-Check the state value of the XEvent structure for correctness.




It's been a little while but after some tinkering, it turned out that my delay between key down and key up was simply too low. After setting it to 15ms the application registered the actions as keystrokes properly and (still) with very high accuracy.


XkbKeycodeToKeysym




In a modern system you are likely to use Xkb and with Xkb layouts are called groups. You can get the current group in XkbStateRec with XkbGetState, and then translate valid keycodes one by one until you get the keysym you need.