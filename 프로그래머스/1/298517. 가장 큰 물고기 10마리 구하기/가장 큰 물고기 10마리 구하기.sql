select f.id as ID, f.length as LENGTH from FISH_INFO as f
where f.length is not null
order by f.length desc, f.id asc
limit 10;