select c.id, c.genotype, p.genotype from ECOLI_DATA as c
    inner join ECOLI_DATA as p
    on c.parent_id = p.id
where c.genotype & p.genotype = p.genotype
order by c.id asc;