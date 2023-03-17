SELECT ts.title FROM tv_genres AS tg
INNER JOIN tv_show_genres AS sg
ON tg.id = sg.genre_id
INNER JOIN tv_shows AS ts
ON sg.show_id = ts.id
WHERE tg.name = 'Comedy'
ORDER BY ts.title;
