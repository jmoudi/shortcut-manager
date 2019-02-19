

CREATE DATABASE HotkeyDB; 


CREATE TABLE ChangeLog (
    ChangeID            INTEGER NOT NULL   PRIMARY KEY,
    ItemID              INTEGER NOT NULL,
    DateAdded           NUMERIC DEFAULT (datetime('now')),
    DateModified        NUMERIC DEFAULT (datetime('now')),
)
/* ********************************************************************************** */

CREATE TABLE Keys (
    Key            TEXT               NOT NULL PRIMARY KEY,
    Windows             TEXT(128)     NOT NULL,
    TitleEngl         TEXT(128),
    ReleaseYear       NUMERIC,
    Director          TEXT(128),
    Country           TEXT(128),
    Genres            TEXT(255),

    DateAdded         NUMERIC NOT NULL DEFAULT (datetime('now')),
    DateModified      NUMERIC NOT NULL DEFAULT (datetime('now')),
    FOREIGN KEY (DateModified) REFERENCES ChangeLog(DateModified) 
        ON UPDATE SET DEFAULT
)

CREATE TABLE Modifiers (
    WatchID         TEXT NOT NULL    PRIMARY KEY,
)

CREATE TABLE CompiledShortcut (
    WatchID         TEXT NOT NULL    PRIMARY KEY,
    AutoHotkey,
    Browser,
    VSCode
)



/