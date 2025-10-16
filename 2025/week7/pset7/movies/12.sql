-- list the titles of all movies in which both Bradley Cooper and Jennifer Lawrence starred.
-- Your query should output a table with a single column for the title of each movie.
-- You may assume that there is only one person in the database with the name Bradley Cooper.
-- You may assume that there is only one person in the database with the name Jennifer Lawrence.

-- select movies.title from movies
-- join stars on movies.id = stars.movie_id
-- join people on stars.person_id = people.id
-- where people.name = 'Bradley Cooper' or people.name = 'Jennifer Lawrence';

select movies.title from movies
join stars on movies.id = stars.movie_id
where stars.person_id in (
    select people.id from people join stars on people.id = stars.person_id
    where people.name = 'Jennifer Lawrence' or people.name = 'Bradley Cooper'
)
group by movies.title
having count(movies.title) > 1;

