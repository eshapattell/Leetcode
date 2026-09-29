# Write your MySQL query statement below

SELECT EU.unique_id as unique_id, E.name as name
FROM Employees E 
left join EmployeeUNI EU
on E.id =EU.id