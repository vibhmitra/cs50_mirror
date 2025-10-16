select avg(energy) as avg_energy_drake from songs where artist_id = (select id from artists where name = 'Drake');
