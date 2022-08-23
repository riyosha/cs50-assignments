SELECT title FROM movies WHERE id IN
    (SELECT stars.movie_id
    FROM people
    LEFT JOIN stars ON people.id = stars.person_id
    WHERE people.name = "Helena Bonham Carter") AND
    id in
    (SELECT stars.movie_id
    FROM people
    LEFT JOIN stars ON people.id = stars.person_id
    WHERE people.name = "Johnny Depp");