​

kglobalshortcutsrc is easier to understand in a text editor.

​

For khotkeysrc, it uses a similar section model, but, since it is in groups, there are multiple sections that make up a shortcut action:

​ Example ``` [Data_1_2] Comment=Global keyboard shortcut to launch Konsole Enabled=true Name=Launch Konsole Type=MENUENTRY_SHORTCUT_ACTION_DATA

[Data_1_2Actions] ActionsCount=1

[Data_1_2Actions0] CommandURL=org.kde.konsole.desktop Type=MENUENTRY

[Data_1_2Conditions] Comment= ConditionsCount=0

[Data_1_2Triggers] Comment=Simple_action TriggersCount=1

[Data_1_2Triggers0] Key=Ctrl+Alt+T Type=SHORTCUT Uuid={fc1fa84a-7000-49d6-823b-bbce13d64646}

``` ​

Notice that the shortcut key is under the Data_1_2Triggers0 section even though the meaning of the trigger is under Data_1_2 Name. 
