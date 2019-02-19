
CREATE TABLE IF NOT EXISTS [China_1] (
    ID integer PRIMARY KEY NOT NULL UNIQUE,
    Title text NOT NULL,
    Artist text NOT NULL,
    Album text,
    Genres text,
    DateAdded numeric DEFAULT (datetime('now')),
    DateModified numeric DEFAULT (datetime('now'))
);