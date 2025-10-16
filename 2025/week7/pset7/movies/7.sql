-- list all movies released in 2010 and their ratings, in descending order by rating. For movies with the same rating, order them alphabetically by title.
-- Your query should output a table with two columns, one for the title of each movie and one for the rating of each movie.
-- Movies that do not have ratings should not be included in the result.

-- select title, rating from movies join ratings on movies.id = ratings.movie_id where movies.year = '2010' and ratings.rating is not null order by movies.title desc;


select title, rating from ratings join movies on ratings.movie_id = movies.id where year = 2010  order by rating desc, title asc;
