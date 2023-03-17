SELECT tg.name FROM tv_genres AS tg
INNER JOIN tv_show_genres AS sg
ON tg.id = sg.genre_id
INNER JOIN tv_shows AS ts
ON sg.show_id = ts.id
WHERE ts.title = 'Dexter'
ORDER BY tg.name;
