
/*************************************************************************************/
SCHEMAS

CREATE TABLE VSCode (
    id                INT NOT NULL PRIMARY KEY,
    physical_key             VARCHAR(1) NOT NULL,
    modifier
    formatted         TEXT,
);

CREATE TABLE Firefox (
    id                INT NOT NULL PRIMARY KEY,
    physical_key             VARCHAR(1) NOT NULL,
    modifier
    formatted         TEXT,
);

CREATE TABLE AutoHotkey (
    id                INT NOT NULL PRIMARY KEY,
    physical_key             VARCHAR(1) NOT NULL,
    modifier
    formatted         TEXT,
);

/*************************************************************************************/


CREATE TABLE IF NOT EXISTS [Keys] (
    ID integer PRIMARY KEY NOT NULL UNIQUE,
    Button text NOT NULL,
    [Type] text NOT NULL,
);

CREATE TABLE IF NOT EXISTS [Modifiers] (
    ID integer PRIMARY KEY NOT NULL UNIQUE,
    alt boolean,
    shift boolean,
    ctrl boolean,
    win boolean,
    altGr boolean
);

/** 
TYPE = "modifier" | "key"

*/

CREATE TABLE IF NOT EXISTS [M] (
    ID integer PRIMARY KEY NOT NULL UNIQUE,
    Title text NOT NULL,
    Artist text NOT NULL,
    Album text,
    Genres text,
    DateAdded numeric DEFAULT (datetime('now')),
    DateModified numeric DEFAULT (datetime('now'))
);
CREATE TABLE IF NOT EXISTS [CheckOut] (
    ID integer PRIMARY KEY NOT NULL UNIQUE,
    Title text,
    Artist text,
    Album text,
    Genres text,
    FoundOn text
    DateAdded numeric DEFAULT (datetime('now')),
    DateModified numeric DEFAULT (datetime('now'))
);
CREATE TABLE IF NOT EXISTS [SourceSites] (
    ID integer PRIMARY KEY NOT NULL UNIQUE,
    Title text,
    Artist text,
    Album text,
    Genres text,
    FoundOn text
    DateAdded numeric DEFAULT (datetime('now')),
    DateModified numeric DEFAULT (datetime('now'))
);
/*********************************************************************************************/
CREATE INDEX [FavSongs] WHERE (
    DateAdded =
    group_concat(Artist, ' - , 'Y)s strftime('%Y-%m-%d %H:%M:')
    




CREATE TABLE Keys (
    id                INT NOT NULL PRIMARY KEY,
    physical_key             VARCHAR(1) NOT NULL,
    altKey BOOLEAN
    shiftKey BOOLEAN
    ctrlKey
    winKey
    altGr
    formatted         TEXT,
);
