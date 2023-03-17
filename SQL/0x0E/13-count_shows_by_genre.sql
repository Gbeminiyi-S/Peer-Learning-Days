SELECT tg.name AS genre, COUNT(tg.name) AS number_of_shows FROM tv_genres AS tg
INNER JOIN tv_show_genres AS sg
ON tg.id = sg.genre_id
INNER JOIN tv_shows AS ts
ON sg.show_id = ts.id
GROUP BY tg.name
ORDER BY number_of_shows DESC;
