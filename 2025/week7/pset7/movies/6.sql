-- the average rating of all movies released in 2012
select avg(rating) as average_ratings_2012 from movies join ratings on movies.id = ratings.movie_id where movies.year = '2012';
