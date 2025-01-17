WITH
table1 AS (
    SELECT name
    FROM Users
    JOIN MovieRating mr
    ON Users.user_id = mr.user_id
    GROUP BY Users.name
    ORDER BY COUNT(Users.user_id) DESC, Users.name ASC
    limit 1
),
table2 AS (
    SELECT title
    FROM Movies m
    JOIN MovieRating mr
    ON m.movie_id = mr.movie_id
    WHERE created_at >= '2020-02-01' AND created_at <= '2020-02-29'
    GROUP BY m.movie_id
    ORDER BY AVG(rating) DESC, m.title ASC
    limit 1
)

SELECT name AS results
FROM table1

UNION ALL

SELECT title AS results
FROM table2;
