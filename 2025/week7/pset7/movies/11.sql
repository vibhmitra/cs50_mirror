-- list the titles of the five highest rated movies (in order) that Chadwick Boseman starred in, starting with the highest rated.
-- Your query should output a table with a single column for the title of each movie.
-- You may assume that there is only one person in the database with the name Chadwick Boseman.

select distinct(movies.title) from movies join stars on movies.id = stars.movie_id
join ratings on ratings.movie_id = movies.id
where stars.person_id in (
    select id from people where name = 'Chadwick Boseman'
) order by ratings.rating desc limit 5;

-- select movies.title from movies join ratings on ratings.movie_id = movies.id
