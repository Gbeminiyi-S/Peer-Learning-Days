SELECT score, COUNT(score) as number
FROM second_table
GROUP BY score
Order BY number DESC;
