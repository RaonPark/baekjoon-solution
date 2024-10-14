select ID,
case 
when size_of_colony <= 100 then 'LOW'
when size_of_colony between 101 and 1000 then 'MEDIUM'
when size_of_colony >= 1001 then 'HIGH'
end
as SIZE
from ecoli_data
