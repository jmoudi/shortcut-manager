# Server Notes

## Index

## Notes

### d

 LOAD VALUES AS TEMP DATABASE INTO :MEMORY


CREATE TABLE ChangeLog (
    ChangeID            INTEGER NOT NULL   PRIMARY KEY,
    ItemID              INTEGER NOT NULL,
    DateAdded           NUMERIC DEFAULT (datetime('now')),
    DateModified        NUMERIC DEFAULT (datetime('now')),
)
/* ********************************************************************************** */
