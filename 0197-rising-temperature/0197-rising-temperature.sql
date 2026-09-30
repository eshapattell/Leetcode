# Write your MySQL query statement below
SELECT w1.Id
FROM Weather w1
JOIN Weather w2
ON w1.RecordDate=DATE_ADD(w2.RecordDate,INTERVAL 1 DAY)
WHERE w1.Temperature > w2.Temperature;