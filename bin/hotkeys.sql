/* sqlite .read MusicDB.sql */

/* sqlite_bind(':MainTable)    :MainTable */

CREATE TABLE IF NOT EXISTS [ChangeLog] (
    ChangeID integer PRIMARY KEY NOT NULL UNIQUE,
    [Date] numeric DEFAULT (datetime('now')),
    [Action] text,
    [Table] text,
    ItemID integer NOT NULL,
    [Changes] int DEFAULT (sqlite3_changes(sqlite3*))
);
CREATE TABLE IF NOT EXISTS [FavSongs] (
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
/*********************************************************************************************/
CREATE TRIGGER LogOnInsert AFTER INSERT ON FavSongs FOR EACH ROW 
BEGIN
    INSERT INTO ChangeLog(
        [Table],
        ItemID,
        [Action]
    ) 
    VALUES (
        'FavSongs',
        NEW.ID,
        'Insert'
    ); 
END;
/*********************************************************************************************/
CREATE TRIGGER LogOnUpdate AFTER INSERT ON FavSongs FOR EACH ROW 
BEGIN
    INSERT INTO ChangeLog(
        [Table],
        ItemID,
        [Action]
    ) 
    VALUES (
        'FavSongs',
        NEW.ID,
        'Modified'
    ); 
END;
/*********************************************************************************************/

/*********************************************************************************************/
COLLATE()
/*********************************************************************************************/

/*********************************************************************************************/
CREATE TRIGGER OnUpdateChangeDateModified AFTER UPDATE OF Title, Artist, Album, Genres ON FavSongs FOR EACH ROW 
BEGIN
    UPDATE FavSongs
        SET DateModified = datetime('now')
        WHERE ID = NEW.ID;
END;
/*********************************************************************************************/
INSERT INTO FavSongs(Title, Artist) VALUES ('test', 'somearttest');

/*********************************************************************************************/
    CASE x WHEN w1 THEN r1 WHEN w2 THEN r2 ELSE r3 END
    CASE WHEN x=w1 THEN r1 WHEN x=w2 THEN r2 ELSE r3 END
/*********************************************************************************************/


ON UPDATE SET DEFAULT
/*********************************************************************************************/
        DateAdded numeric REFERENCES ChangeLog(DateAdded) ON UPDATE SET DEFAULT,
        DateModified numeric REFERENCES ChangeLog(DateModified) ON UPDATE SET DEFAULT

    VALUES (
        NEW.FavID, 
        datetime('now'), 
        datetime('now')
    ); 
/*********************************************************************************************/
CREATE TRIGGER onadd_insert_datetime AFTER INSERT ON FavSongs FOR EACH ROW 
BEGIN 
    UPDATE FavSongs SET 
        date_added = datetime('now'), 
        last_modified = datetime('now') WHERE id = new.ID;    
END;
/*********************************************************************************************/


DROP TRIGGER DataAdded;

CREATE TRIGGER onadd_insert_datetime AFTER INSERT ON FavSongs FOR EACH ROW BEGIN 
    UPDATE FavSongs SET date_added = datetime('now'), last_modified = datetime('now') WHERE id = new.ID;    
END;
CREATE TRIGGER OnAddLog AFTER INSERT ON FavSongs FOR EACH ROW BEGIN 
    INSERT INTO ChangeLog (ItemID, [Table], DateAdded) VALUES (NEW.ID, 'FavSongs', datetime('now')); 
END;

CREATE TRIGGER onadd_insert_datetime AFTER INSERT ON FavSongs FOR EACH ROW BEGIN 
    UPDATE FavSongs SET date_added = datetime('now'), last_modified = datetime('now') WHERE id = new.ID;    
END;
CREATE TRIGGER onadd_log AFTER INSERT ON FavSongs FOR EACH ROW BEGIN 
    INSERT INTO log_favourite_songs (id, datetime) VALUES (new.ID, datetime('now')); 
END;




CREATE TABLE FavSongs (FavID integer NOT NULL PRIMARY KEY UNIQUE, SongID integer, Title text NOT NULL, Artist text, Album text, Genres text, 
DateAdded numeric REFERENCES ChangeLog (DateAdded) ON UPDATE SET DEFAULT, 
DateModified NUMERIC REFERENCES ChangeLog (DateModified) ON UPDATE SET DEFAULT, 

FOREIGN KEY (DateAdded) REFERENCES ChangeLog (DateAdded), 
FOREIGN KEY (DateModified) REFERENCES ChangeLog (DateModified));



CREATE VIEW

lower()

/*********************************************************************************************/
CREATE INDEX Films ChangeLog(DateAdded, DateModified) DESC
/*********************************************************************************************/
CREATE TRIGGER main.DataAdded AFTER INSERT ON main.Films
FOR EACH ROW BEGIN
    INSERT INTEGERO ChangeLog(FilmID) VALUES (numeric('now')); 
END;



    CREATE TABLE IF NOT EXISTS [Songs] (
        SongID integer PRIMARY KEY UNIQUE,
        Title text NOT NULL,
        TitleE text,
        Artist text,
        Album text,
        Genres text,
        [Length] numeric
    )
    CREATE TABLE IF NOT EXISTS [Artists] (
        ArtistID        integer       NOT NULL PRIMARY KEY UNIQUE,
        [Name]          text          NOT NULL,
        NameN           text,
        Genres          text,
    )
    CREATE TABLE IF NOT EXISTS [Albums] (
        AlbumID         integer         NOT NULL PRIMARY KEY,
        Title           text            NOT NULL,
        TitleN          text,
        ReleaseYear     numeric,
        Artist          text,
        Songs           text,
        Genres          text,
        [Length]        numeric
    )



/*********************************************************************************************/
CREATE [TEMP] VIEW [IF NOT EXISTS] view_name(column-name-list)
AS 
   select-statement;


SELECT
 trackid,
 tracks.name,
 albums.Title AS album,
 media_types.Name AS media,
 genres.Name AS genres
FROM
 tracks
INNER JOIN albums ON Albums.AlbumId = tracks.AlbumId
INNER JOIN media_types ON media_types.MediaTypeId = tracks.MediaTypeId
INNER JOIN genres ON genres.GenreId = tracks.GenreId;


max()
 