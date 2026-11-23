select f.flavor from FIRST_HALF as f
    inner join ICECREAM_INFO as i
    on f.flavor = i.flavor
where i.ingredient_type = 'fruit_based'
group by f.flavor having sum(f.total_order) > 3000
order by f.total_order desc;
