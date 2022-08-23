SELECT movies.title
FROM movies
INNER JOIN ratings ON movies.id = ratings.movie_id
WHERE movies.id IN
    (SELECT stars.movie_id
    FROM people
    INNER JOIN stars ON people.id = stars.person_id
    WHERE people.name = "Chadwick Boseman")
ORDER BY rating DESC
LIMIT 5;
