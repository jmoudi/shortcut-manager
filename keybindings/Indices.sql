/*

forEach letter

*/

CREATE INDEX [China_1] WHERE (
    DateAdded =
    group_concat(Artist, ' - , 'Y)s strftime('%Y-%m-%d %H:%M:')

)


CREATE INDEX [Korea_1] WHERE (
    DateAdded =
    group_concat(Artist, ' - , 'Y)s strftime('%Y-%m-%d %H:%M:')

)

CREATE INDEX [Japan_1] WHERE (
    DateAdded =
    group_concat(Artist, ' - , 'Y)s strftime('%Y-%m-%d %H:%M:')

)